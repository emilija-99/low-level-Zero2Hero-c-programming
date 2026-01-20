#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_THREADS 10

pthread_mutex_t mutex;
pthread_t threads[MAX_THREADS];

void startup_function() {
    pthread_mutex_init(&mutex,NULL);
}

void *thread_function(void *arg) {
    int *counter = (int *)arg;
        pthread_mutex_lock(&mutex);
        (*counter)++;
        pthread_mutex_unlock(&mutex);
        // printf("Counter: %d\n", *counter);

        return NULL;
}

int main(){
    startup_function();
    int counter = 0;

    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &counter);
    }


    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter: %d\n", counter);

    pthread_mutex_destroy(&mutex);
    return 0;
}
