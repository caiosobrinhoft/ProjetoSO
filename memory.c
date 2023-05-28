<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"

Segment* memory;  // Array para representar a memória
int numSegments = 0;  // Número de segmentos alocados

// Função para alocar um segmento de memória para um processo
void allocateSegment(int processID, int size) {
    int numPages = size / PAGE_SIZE;

    if ((numSegments + 1) * numPages * PAGE_SIZE > MAX_MEMORY_SIZE) {
        printf("Não há memória suficiente disponível.\n");
        return;
    }

    Segment segment;
    segment.segmentID = processID;
    segment.size = size;
    segment.pages = (Page*)malloc(numPages * sizeof(Page));

    for (int i = 0; i < numPages; i++) {
        segment.pages[i].segmentID = processID;
        segment.pages[i].pageID = i;
        segment.pages[i].referenced = 0;
    }

    memory = (Segment*)realloc(memory, (numSegments + 1) * sizeof(Segment));
    memory[numSegments] = segment;
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
            memory = (Segment*)realloc(memory, (numSegments - 1) * sizeof(Segment));
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
            Page* pages = memory[i].pages;
            int numPages = memory[i].size / PAGE_SIZE;

            while (1) {
                Page* page = &pages[virtualPage % numPages];
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
=======
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"

page* createPage(unsigned int pageNumber){

    page* newPage = (page*)malloc(sizeof(page));
    newPage->pageNumber = pageNumber;
    newPage->processID = 0; // Inicialmente, nenhuma página está alocada
    newPage->secondChanceBit = 0;
    newPage->next = NULL;
    return newPage;
}

page* createPageList() {
    unsigned int totalPages = MAX_MEMORY_SIZE / PAGE_SIZE;
    page* head = NULL;
    page* current = NULL;

    for (unsigned int i = 0; i < totalPages; i++) {
        page* page = createPage(i);

        if (head == NULL) {
            head = page;
            current = page;
        } else {
            current->next = page;
            current = page;
        }
    }

    return head;
}

void printPageList(page* head) {
    page* current = head;

    while (current != NULL) {
        printf("page Number: %u, Process ID: %u\n", current->pageNumber, current->processID);
        current = current->next;
    }
}

void freePageList(page* head) {
    page* current = head;
    page* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

//segment functions
segment* createSegment(unsigned int segmentNumber) {
    segment* newSegment = (segment*)malloc(sizeof(segment));
    newSegment->segmentNumber = segmentNumber;
    newSegment->processID = 0; // Inicialmente, nenhum segmento está alocado
    newSegment->baseAddress = 0;
    newSegment->size = 0;
    newSegment->next = NULL;
    return newSegment;
}

segment* createSegmentList() {
    segment* head = NULL;

    return head;
}

void printSegmentList(segment* head) {
    segment* current = head;

    while (current != NULL) {
        printf("segment Number: %u, Process ID: %u\n", current->segmentNumber, current->processID);
        current = current->next;
    }
}

void freeSegmentList(segment* head) {
    segment* current = head;
    segment* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
>>>>>>> 2c0af9f5d5ab43bb3d9eeab5078a603ab9476c57
}