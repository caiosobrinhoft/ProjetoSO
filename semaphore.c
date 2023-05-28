#include <stdio.h>
#include <stdlib.h>
#include "semaphore.h"
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void P(int *s) {
    pthread_mutex_lock(&mutex);
    (*s)--;
    if (*s < 0) {
        // O processo fica bloqueado até que o semáforo seja liberado
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void V(int *s) {
    pthread_mutex_lock(&mutex);
    (*s)++;
    if (*s <= 0) {
        // Libera um processo bloqueado, se houver algum
        pthread_cond_signal(&cond);
    }
    pthread_mutex_unlock(&mutex);
}