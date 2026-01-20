#include <stdio.h>
#include <pthread.h>
#define THREAD_COUNT 10

int counter = 0;
void *thread_target(void *vargs){
    for(int i = 0; i < 10000; i++){
        counter++;
    }
    printf("Counter: %d\n", counter);
}

int main(int argc, char *argv){
    pthread_t threads[THREAD_COUNT];

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
