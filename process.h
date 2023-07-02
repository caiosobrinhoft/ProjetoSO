#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>

#define MAX_PROCESS_NAME 50
#define MAX_SEMAFOROS 10

typedef struct Process{
    // Cabecalho
    char name[MAX_PROCESS_NAME];
    int id_segmento;
    int prioridade_original;
    int tamanho_segmento;
    int semaforos[MAX_SEMAFOROS];
    int num_semaforos;
    // Comandos
    char **comandos;
    int num_comandos;
    // Legado
    int id;
    int remainingTime;
    int arrivalTime;
    struct Process *new; // Lista de processos
} process_t;

process_t *readSyntProgram(char *file_name);
process_t* processCreate(int id, const char *name);
void processInterrupt(process_t *process);
void processFinish(process_t *process);

#endif