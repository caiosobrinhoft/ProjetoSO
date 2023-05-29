#include <stdlib.h>
#include <stdio.h>
#include "memory.h"

segment* memory;  // Array para representar a memória
int numSegments = 0;  // Número de segmentos alocados

// Função para alocar um segmento de memória para um processo
void allocateSegment(int processID, int size) {
    int numPages = size / PAGE_SIZE;

    if ((numSegments + 1) * numPages * PAGE_SIZE > MAX_MEMORY_SIZE) {
        printf("Não há memória suficiente disponível.\n");
        return;
    }

    segment newSegment;
    newSegment.segmentID = processID;
    newSegment.size = size;
    newSegment.pages = (page*)malloc(numPages * sizeof(page));

    for (int i = 0; i < numPages; i++) {
        newSegment.pages[i].segmentID = processID;
        newSegment.pages[i].pageID = i;
        newSegment.pages[i].referenced = 0;
    }

    memory = (segment*)realloc(memory, (numSegments + 1) * sizeof(segment));
    memory[numSegments] = newSegment;
    numSegments++;

    printf("Segmento alocado para o processo %d.\n", processID);
}

// Função para liberar o segmento de memória alocado por um processo
void freeSegment(int processID) {
    for (int i = 0; i < numSegments; i++) {
        if (memory[i].segmentID == processID) {
            free(memory[i].pages);
            for (int j = i; j < numSegments - 1; j++) {
                memory[j] = memory[j + 1];
            }
            memory = (segment*)realloc(memory, (numSegments - 1) * sizeof(segment));
            numSegments--;

            printf("Segmento liberado para o processo %d.\n", processID);
            return;
        }
    }

    printf("Processo %d não possui segmento alocado.\n", processID);
}

// Função para traduzir um endereço virtual para um endereço físico
int translateVirtualToPhysical(int processID, int virtualAddress) {
    int virtualPage = virtualAddress / PAGE_SIZE;

    for (int i = 0; i < numSegments; i++) {
        if (memory[i].segmentID == processID) {
            page* pages = memory[i].pages;
            int numPages = memory[i].size / PAGE_SIZE;

            while (1) {
                page* page = &pages[virtualPage % numPages];
                if (page->referenced == 0) {
                    page->referenced = 1;
                    return (i * numPages + virtualPage) * PAGE_SIZE + (virtualAddress % PAGE_SIZE);
                }
                page->referenced = 0;
                virtualPage = (virtualPage + 1) % numPages;
            }
        }
    }

    printf("Endereço virtual inválido para o processo %d.\n", processID);
    return -1;
}

// Função de chamada de operação de carregamento na memória
void memLoadReq(int processID, int size) {
    allocateSegment(processID, size);
}

// Função de sinalização de final de carregamento
void memLoadFinish(int processID) {
    freeSegment(processID);
}