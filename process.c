#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

// Função para ler um programa sintético a partir de um arquivo
process_t *ler_programa_sintetico(char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura
    if (arquivo == NULL)
    { // Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    process_t *programa = malloc(sizeof(process_t)); // Aloca memória para armazenar o programa sintético

    // Lê os dados do cabeçalho do arquivo
    fscanf(arquivo, "%s %d %d %d", programa->name, &programa->id_segmento, &programa->prioridade_original, &programa->tamanho_segmento);

    // Lê a lista de semáforos usados pelo programa
    programa->num_semaforos = 0;
    while (1)
    {
        int semaforo;
        if (fscanf(arquivo, "%d", &semaforo) != 1)
            break;                                                                     // Lê um semáforo do arquivo e verifica se a leitura foi bem sucedida
        programa->semaforos[programa->num_semaforos++] = semaforo; // Armazena o semáforo lido na lista de semáforos e incrementa o contador de semáforos
    }

    // Lê a lista de comandos do programa
    programa->num_comandos = 0;
    programa->comandos = NULL;
    char comando[100];
    while (fgets(comando, 100, arquivo) != NULL)
    {                                                                                                    // Lê um comando do arquivo e verifica se a leitura foi bem sucedida
        programa->comandos = realloc(programa->comandos, (programa->num_comandos + 1) * sizeof(char *)); // Realoca memória para armazenar mais um comando na lista de comandos
        programa->comandos[programa->num_comandos] = strdup(comando);                                    // Armazena o comando lido na lista de comandos e incrementa o contador de comandos
        programa->num_comandos++;
    }

    fclose(arquivo); // Fecha o arquivo

    return programa; // Retorna o ponteiro para a estrutura que contém o programa sintético lido
}

process_t *processCreate(int id, const char *name)
{
    process_t *new_process = (process_t *)malloc(sizeof(process_t));
    if (new_process == NULL)
    {
        printf("Erro ao alocar memoria para o processo.\n");
        return NULL;
    }

    new_process->id = id;
    strncpy(new_process->name, name, MAX_PROCESS_NAME - 1);
    new_process->name[MAX_PROCESS_NAME - 1] = '\0';

    return new_process;
}

void processInterrupt(process_t *process)
{
    printf("Interrupcao do processo %d\n", process->id);
    // Realizar as ações necessárias para tratar a interrupção
    // troca de contexto etc

    free(process);
    printf("Processo %d interrompido!\n", process->id);
}

void processFinish(process_t *process)
{
    printf("Finalizando o processo %d\n", process->id);

    free(process);
}