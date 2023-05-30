#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>

#define MAX_PROCESS_NAME 50

typedef struct Process{
    char name[MAX_PROCESS_NAME];
    int id;
    int remainingTime;
    int arrivalTime;
    struct Process *new;
} process_t;

void getProcess();
process_t* processCreate(int id, const char *name);
void processInterrupt(process_t *process);
void processFinish(process_t *process);

#endif