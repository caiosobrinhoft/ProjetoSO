<<<<<<< HEAD
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

=======
#ifndef MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#define KILOBYTE 1024
#define MEGABYTE (1024 * KILOBYTE)
#define GYGABYTE (1024 * MEGABYTE)
#define MAX_MEMORY_SIZE (1 * GYGABYTE)
#define PAGE_SIZE (8 * KILOBYTE)

typedef struct{
    unsigned int segmentNumber;
    unsigned int processID;
    unsigned int baseAddress;
    unsigned int size;
    struct segment* next;
} segment;

typedef struct{
    unsigned int pageNumber;
    unsigned int processID;
    unsigned int secondChanceBit;
    struct page* next;
} page;

//Page functions
void freePageList(page* head);
void printPageList(page* head);
page* createPageList();
page* createPage(unsigned int pageNumber);

//Segment functions
void freeSegmentList(segment* head);
void printSegmentList(segment* head);
segment* createSegmentList();
segment* createSegment(unsigned int segmentNumber);

>>>>>>> 2c0af9f5d5ab43bb3d9eeab5078a603ab9476c57
#endif