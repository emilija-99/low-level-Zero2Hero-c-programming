#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

__thread int x_thd;
int counter = 10;
void* wait_for_event(void* arg){
    x_thd+=(counter++);
    printf("%d\n",x_thd);
    return NULL;
}

int main(){
    pthread_t threads[10];
    for(int i = 0; i < 10; i++){
        pthread_create(&threads[i], NULL, wait_for_event, NULL);
    }

    for(int i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}
