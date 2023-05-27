#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

process_t* processCreate(int id, const char *name){
    process_t* new_process = (process_t*)malloc(sizeof(process_t));
    if(new_process == NULL){
        printf("Erro ao alocar memoria para o processo.\n");
        return NULL;
    }

    new_process->id = id;
    strncpy(new_process->name, name, MAX_PROCESS_NAME - 1);
    new_process->name[MAX_PROCESS_NAME - 1] = '\0';

    return new_process;
}

void processInterrupt(process_t *process){
    printf("Interrupcao do processo %d\n", process->id);
    // Realizar as ações necessárias para tratar a interrupção
    //troca de contexto etc

    free(process);
    printf("Processo %d interrompido!\n", process->id);

}

void processFinish(process_t *process){
    printf("Finalizando o processo %d\n", process->id);

    free(process);
}