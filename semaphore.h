#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sem_t io_mutex;

void P(int *s);
void V(int *s);

#endif 