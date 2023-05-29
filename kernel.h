#ifndef KERNEL_H
#define KERNEL_H

#include <stdio.h>
#include "process.h"
#include "memory.h"

typedef enum{
    PROCESS_INTERRUPT = 1,
    PROCESS_CREATE = 2,
    PROCESS_FINISH = 3,

    MEM_LOAD_REQ = 6,
    MEM_LOAD_FINISH = 7,

    SEMAPHORE_P = 10,
    SEMAPHORE_V = 11,
} kernelFunctions;

void sysCall(kernelFunctions func, process_t *process, segment *segment);

#endif 