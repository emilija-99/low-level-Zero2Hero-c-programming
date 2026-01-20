#include <stdio.h>
#include <pthread.h>

pthread_spinlock_t lock;
int counter = 0;

void *increment_counter(void *arg){
    for(int i = 0; i < 100000; i++){
        pthread_spin_lock(&lock);
        counter++;
        pthread_spin_unlock(&lock);
        printf("Counter incremented to %d\n", counter);
    }

    return NULL;
}

int main(int argc, char *argv){
    pthread_t t1,t2;
    pthread_spin_init(&lock, 0);

    pthread_create(&t1, NULL, increment_counter, NULL);
    pthread_create(&t2, NULL, increment_counter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_spin_destroy(&lock);

    return 0;
}
