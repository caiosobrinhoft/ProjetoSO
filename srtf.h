#ifndef SRTF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSOS 100
#define TEMPO_BLOQUEIO 200

struct Processo {
    int id;
    int tempo_execucao;
    int tempo_restante;
    int tempo_espera;
    int tempo_bloqueio;
} process;

void srtf(struct Processo processos[], int num_processos);

#endif