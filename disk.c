#include <pthread.h>
#include <time.h>
#include <math.h>

#include "disk.h"
#include "process.h"
#include "semaphore.h"

// Variáveis globais

disk_scheduler_t disk_scheduler;

// Função para a chamada de DiskRequest

void diskRequest(process_t* process, int track, int read) {
    int time = DISK_OPERATION_TIME;

    if (disk_scheduler.forward_dir) {
        if (track >= disk_scheduler.curr_track)
            time += (track - disk_scheduler.curr_track) * DISK_TRACK_MOVE_TIME;
        else
            time += ((DISK_TRACK_LIMIT - disk_scheduler.curr_track) + (DISK_TRACK_LIMIT - track)) * DISK_TRACK_MOVE_TIME;
    } else {
        if (track < disk_scheduler.curr_track)
            time += (disk_scheduler.curr_track - track) * DISK_TRACK_MOVE_TIME;
        else
            time += (disk_scheduler.curr_track + track) * DISK_TRACK_MOVE_TIME;
    }

    // Cria uma estrutura com as informações necessárias para o handle simulado do disco
    disk_request_t* disk_req = create_disk_request();
    disk_req->process = process;
    disk_req->track = track;
    disk_req->read = read;
    disk_req->turnaround = time;

    // Adiciona a solicitação à lista de solicitações pendentes
    list_add(disk_scheduler.pending_requests, disk_req);

    // Atualiza o tempo restante do processo
    process->remainingTime -= time;

    // Emitir um sinal de interrupção para tratar a chamada de DiskRequest
    interruptControl(DISK_REQUEST, process);
}

void print_request(process_t* process, int duration) {
    io_print_log(process->name, duration);
    sem_post(&io_mutex);

    process->remainingTime -= duration;
    interruptControl(PRINT_FINISH, process);
}

void printFinish(process_t* process) {
    // Emitir um sinal de interrupção para tratar a finalização da operação de impressão
    interruptControl(PRINT_FINISH, process);
}

void diskFinish(process_t* process) {
    // Emitir um sinal de interrupção para tratar a finalização da operação de disco
    interruptControl(DISK_FINISH, process);
}