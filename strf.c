#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srtf.h"

void srtf(Processo processos[], int num_processos) {
    int tempo_total = 0;
    int processos_concluidos = 0;
    int processo_atual = -1;
    int proxima_operacao = 0; // 0 - execução, 1 - read, 2 - write, 3 - print

    while (processos_concluidos < num_processos) {
        int menor_tempo_restante = -1;
        int proximo_processo = -1;

        // Encontra o próximo processo com o menor tempo restante
        for (int i = 0; i < num_processos; i++) {
            if (processos[i].tempo_restante > 0 && (menor_tempo_restante == -1 || processos[i].tempo_restante < menor_tempo_restante)) {
                menor_tempo_restante = processos[i].tempo_restante;
                proximo_processo = i;
            }
        }

        if (proximo_processo != -1) {
            // Atualiza o tempo restante do processo atual
            processos[proximo_processo].tempo_restante--;

            // Verifica se o processo atual deve ser interrompido
            if (processo_atual != -1 && proxima_operacao != 0) {
                processos[processo_atual].tempo_bloqueio += TEMPO_BLOQUEIO;
                tempo_total += TEMPO_BLOQUEIO;
                printf("Processo %d interrompido no tempo %d\n", processos[processo_atual].id, tempo_total);
                processo_atual = -1;
            }

            if (processo_atual != proximo_processo) {
                processo_atual = proximo_processo;
                printf("Executando processo %d no tempo %d\n", processos[processo_atual].id, tempo_total);
            }

            if (processos[processo_atual].tempo_restante == 0) {
                processos_concluidos++;
                printf("Processo %d concluído no tempo %d\n", processos[processo_atual].id, tempo_total);
                processo_atual = -1;
            }

            // Define a próxima operação do processo atual
            if (processo_atual != -1) {
                switch (proxima_operacao) {
                    case 0:
                        proxima_operacao = 1;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        proxima_operacao = 0;
                        break;
                }
            }
        } else {
            tempo_total++;
        }
    }
}