#include <stdio.h>
#include <pthread.h>
#define THREAD_COUNT 10

typedef struct{
    int arg1;
    short arg2;
} pthread_arg_t;

void *thread_target(void *vargs){
    pthread_arg_t *args = (pthread_arg_t*)vargs;
    printf("Hello, i am a thread arg1: %d arg2: %d\n", args->arg1, args->arg2); // reference to field to structure
    return NULL;
}

int main(int argc, char *argv){
    pthread_t pthreadID;
    pthread_arg_t myargs;
    myargs.arg1 = 200;
    myargs.arg2 = 12;

    pthread_create(&pthreadID, NULL, thread_target, (void*)&myargs);
    pthread_join(pthreadID, NULL);

    return 0;
}
