#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t sem;
// publisher > post some work
void *signal_event(void *arg){
    printf("Doing something...\n");
    sleep(2);
    printf("Singal event completion!\n");
    sem_post(&sem);

    // return;
}
// other, wait for work
void *wait_for_event(void *arg){
    printf("Waiting for event...\n");
    sem_wait(&sem);
    // wait for publisher to publish event and then we
    // unlocking the semaphore locked resource
    printf("Event has been triggered!\n");

    // return;
}
int main(int argc, char *argv[]){
    pthread_t t1,t2;
    sem_init(&sem, 0,0);

    pthread_create(&t1, NULL, wait_for_event, NULL);
    pthread_create(&t2, NULL, signal_event, NULL);

    pthread_join(t1,NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    return 0;
}
