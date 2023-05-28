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
}