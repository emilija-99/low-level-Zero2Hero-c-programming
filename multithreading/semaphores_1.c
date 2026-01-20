#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

sem_t sem;
char message[100]; // shared resource

void *publisher(void *arg){
    printf("Publishing message...\n");
    sprintf(message, "Hello.");
    sem_post(&sem);
    printf("Message published.\n");

    return NULL;
}
void *subscriber(void *arg){
    printf("Waiting for message...\n");
    sem_wait(&sem);
    printf("Received message: %s\n", message);

    return NULL;
}
int main(int argc, char *argv){
    pthread_t pub, sub;

    sem_init(&sem, 0,0);

    pthread_create(&pub, NULL, publisher, NULL);
    pthread_create(&sub, NULL, subscriber, NULL);

    pthread_join(pub, NULL);
    pthread_join(sub, NULL);

    sem_destroy(&sem);
    return 0;


}
