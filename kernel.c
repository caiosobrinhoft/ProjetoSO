<<<<<<< HEAD
#include <stdio.h>

#include "kernel.h"
#include "process.h"
#include "memory.h"

void sysCall(kernelFunctions func){
    switch (func)
    {
    case PROCESS_INTERRUPT:
        //processInterrup();
        break;
    case PROCESS_CREATE:
        //processCreate();
        break;
    case PROCESS_FINISH:
        //processFinish();
        break;
    case MEM_LOAD_REQ:
        //memoryLoadReq();
        break;
    case MEM_LOAD_FINISH:
        //memoryLoadFinish();
        break;
    case SEMAPHORE_P:
        //semaphoreP();
        break;
    case SEMAPHORE_V:
        //semaphoreV();
        break;
    default:
        break;
    }
}

void interruptControl(kernelFunctions func, process_t *process){
    switch (func)
    {
    case MEM_LOAD_FINISH:
        
        break;
    default:
        break;
    }
=======
#include <stdio.h>

#include "kernel.h"
#include "process.h"

void sysCall(kernelFunctions func, process_t *process){
    switch (func)
    {
    case PROCESS_INTERRUPT:
        processInterrup(process);
        break;
    case PROCESS_CREATE:
        //processCreate();
        break;
    case PROCESS_FINISH:
        processFinish(process);
        break;
    case MEM_LOAD_REQ:
        //memoryLoadReq();
        break;
    case MEM_LOAD_FINISH:
        //memoryLoadFinish();
        break;
    case SEMAPHORE_P:
        //semaphoreP();
        break;
    case SEMAPHORE_V:
        //semaphoreV();
        break;
    default:
        break;
    }
}

void interruptControl(kernelFunctions func, process_t *process){
    switch (func)
    {
    case MEM_LOAD_FINISH:
        
        break;
    default:
        break;
    }
>>>>>>> 2c0af9f5d5ab43bb3d9eeab5078a603ab9476c57
}