#include <stdio.h>
#include <pthread.h>
#define THREAD_COUNT 10

int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_target(void *vargs){
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < 100000; i++){
        counter++;
    }
    printf("Counter: %d\n", counter);

    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv){
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_init(&mutex, NULL);

    int i = 0;
    for(i = 0; i < THREAD_COUNT; i++){
        if(pthread_create(&threads[i], NULL, thread_target, NULL)){
            return -1;
        }
    }

    for(i = 0; i < THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}
