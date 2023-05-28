#ifndef MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#define KILOBYTE 1024
#define MEGABYTE (1024 * KILOBYTE)
#define GYGABYTE (1024 * MEGABYTE)
#define MAX_MEMORY_SIZE (1 * GYGABYTE)
#define PAGE_SIZE (8 * KILOBYTE)

// Estrutura para representar uma página
typedef struct {
    int segmentID;
    int pageID;
    int referenced;
} Page;

// Estrutura para representar um segmento
typedef struct {
    int segmentID;
    int size;
    Page* pages;
} Segment;

//Functions
void allocateSegment(int processID, int size);
void freeSegment(int processID);
int translateVirtualToPhysical(int processID, int virtualAddress);
void memLoadFinish(int processID);
void memLoadReq(int processID, int size);

#endif