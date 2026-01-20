#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void* num){
    int id = *(int*)num; // philosopher id
    int left = id;
    int right = (id+1)%NUM_PHILOSOPHERS;

    while(1){
        printf("Philosopher %d is thiniking\n", id);
        sleep(1);
        printf("Philosopher %d is hungry\n", id);

        // try to pick up left fork
        pthread_mutex_lock(&forks[left]);
        printf("Philosopher %d picked up left fork %d\n", id, left);

        // try to pick up the right fork
        pthread_mutex_lock(&forks[right]);
        printf("Philosopher %d picked up right fork %d\n",id, right);

        printf("Philosopher %d is eating\n",id);
        sleep(1);

        // put down the right fork
        pthread_mutex_unlock(&forks[right]);
        printf("Philosopher %d put down right fork %d\n", id, right);

        // put down the left fork
        pthread_mutex_unlock(&forks[left]);
        printf("Philosopher %d put down left fork %d\n", id, left);
    }
}
int main(){
    pthread_t philosophers[NUM_PHILOSOPHERS];

    int ids[NUM_PHILOSOPHERS];

    // initialize forks > mutex
    for(int i = 0; i < NUM_PHILOSOPHERS; i++){
        pthread_mutex_init(&forks[i], NULL);
    }

    // init philosophers > threads
    for(int i = 0; i < NUM_PHILOSOPHERS; i++){
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // wait for all philosophers to finish (in this case, they never will)
    for(int i = 0; i < NUM_PHILOSOPHERS; i++){
        pthread_join(philosophers[i], NULL);
    }

    // destroy forks > mutex
    for(int i = 0; i < NUM_PHILOSOPHERS; i++){
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
