#include <stdio.h>

#include "kernel.h"
#include "process.h"
#include "memory.h"
#include "semaphore.h"
#include "srtf.h"

#define MAX_PROCESSES 100
process_t* processList[MAX_PROCESSES];
int numProcesses = 0;

int value = 1;
int *semaphore = &value;

void sysCall(kernelFunctions func, process_t *process, segment *segment){
    switch (func)
    {
    case PROCESS_INTERRUPT:
        processInterrupt(processList[numProcesses]);
        break;
    case PROCESS_CREATE:
        process = processCreate(process->id, process->name);
        processList[numProcesses] = process;
        numProcesses++;
        break;
    case PROCESS_FINISH:
        processFinish(processList[numProcesses]);
        break;
    case MEM_LOAD_REQ:
        memLoadReq(process->id, segment->size);
        break;
    case MEM_LOAD_FINISH:
        memLoadFinish(process->id);
        break;
    case SEMAPHORE_P:
        P(semaphore);
        break;
    case SEMAPHORE_V:
        V(semaphore);
        break;
    default:
        break;
    }
}

void interruptControl(kernelFunctions func, process_t *process){
    switch (func)
    {
    case MEM_LOAD_FINISH:
        memLoadFinish(process->id);
        break;
    default:
        break;
    }
}