#include <stdio.h>
#include <pthread.h>
#define THREAD_COUNT 10

void *thread_target(void *arg){
    printf("Hello, i am a thread\n");
}

int main(int argc, char *argv){
    pthread_t threads[THREAD_COUNT];

    int i = 0;
    for(i = 0; i < THREAD_COUNT; i++){
        if(pthread_create(&threads[i], NULL, thread_target, NULL)){
            // perror("pthread_create");
            return -1;
        }
    }

    for(i = 0; i < THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}
