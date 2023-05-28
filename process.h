<<<<<<< HEAD
#ifndef PROCESS_H
#include <stdio.h>

#define MAX_PROCESS_NAME 50

typedef struct{
    char name[MAX_PROCESS_NAME];
    int id;
    int remainingTime;
} process_t;

process_t* processCreate(int id, const char *name);
void processInterrupt(process_t *process);
void processFinish(process_t *process);

=======
#ifndef PROCESS_H
#include <stdio.h>

#define MAX_PROCESS_NAME 50

typedef struct {
    char name[MAX_PROCESS_NAME];
    int id;
    int remainingTime;
} process_t;

process_t* processCreate(int id, const char *name);
void processInterrupt(process_t *process);
void processFinish(process_t *process);

>>>>>>> 2c0af9f5d5ab43bb3d9eeab5078a603ab9476c57
#endif