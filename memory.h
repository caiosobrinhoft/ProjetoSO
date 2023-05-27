#ifndef MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#define KILOBYTE 1024
#define MEGABYTE (1024 * KILOBYTE)
#define GYGABYTE (1024 * MEGABYTE)
#define MAX_MEMORY_SIZE (1 * GYGABYTE)

typedef struct Segment {
    unsigned int segmentNumber;
    unsigned int processID;
    unsigned int baseAddress;
    unsigned int size; 
} segment;

typedef struct Page {
    unsigned int pageNumber;
    unsigned int processID;
    unsigned int secondChanceBit;
} page;

#endif