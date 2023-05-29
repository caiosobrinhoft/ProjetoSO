#ifndef SRTF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSOS 100
#define TEMPO_BLOQUEIO 200

typedef struct{
    int id;
    int tempo_execucao;
    int tempo_restante;
    int tempo_espera;
    int tempo_bloqueio;
} Processo;

void srtf(Processo processos[], int num_processos);

#endif