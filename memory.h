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

#endif