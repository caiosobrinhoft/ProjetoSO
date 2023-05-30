#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

void getProcess()
{
    FILE *file;
    char fileName[100];

    printf("Digite o nome do arquivo: ");
    fgets(fileName, 100, stdin);

    // Removendo o caractere de nova linha ('\n') da string
    int size = strlen(fileName);
    if (fileName[size - 1] == '\n')
    {
        fileName[size - 1] = '\0';
    }

    // Abrir o arquivo para leitura
    file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int id;
    const char *name;

    // Le o header do arquivo
    scanf("%s", &name);
    scanf("%d", &id);

    processCreate(id, name);

    fclose(file);
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