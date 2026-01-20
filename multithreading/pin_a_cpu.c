#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

void pin_to_core(int core_id)
{
    int cpu_count = sysconf(_SC_NPROCESSORS_ONLN);
    if (core_id < 0 || core_id >= cpu_count) return;

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    pthread_setaffinity_np(
        pthread_self(),
        sizeof(cpu_set_t),
        &cpuset
    );
}
void* thread_function(void* arg)
{
    int core_id = *(int*)arg;

    pin_to_core(core_id);

    int cpu = sched_getcpu();
    printf("Currently executing on CPU: %d\n", cpu);

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    printf("Affinity mask: ");
    for (int i = 0; i < CPU_SETSIZE; i++) {
        if (CPU_ISSET(i, &cpuset)) printf("%d ", i);
    }
    printf("\n");

    return NULL;
}

int main(void)
{
    pthread_t thread;
    int core_id = 6;

    pthread_create(&thread, NULL, thread_function, &core_id);
    pthread_join(thread, NULL);

    return 0;
}
