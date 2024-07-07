#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define noofphilos 5

sem_t forks[noofphilos];
sem_t room_sem;

void* philosopher(void* arg) {
    int phil_id = *(int*)arg;
    int l_fork = phil_id;
    int r_fork = (phil_id + 1) % noofphilos;

    while (1) {
        printf("Philosopher %d is thinking.\n", phil_id);
        sleep(2);

        sem_wait(&room_sem); 

        sem_wait(&forks[l_fork]);
        sem_wait(&forks[r_fork]);

        printf("Philosopher %d is eating.\n", phil_id);
        sleep(3);

        sem_post(&forks[l_fork]);
        sem_post(&forks[r_fork]);

        sem_post(&room_sem); 
    }
}

int main() {
    pthread_t phills[noofphilos];
    int ids[noofphilos];

    sem_init(&room_sem, 0, noofphilos - 1); 
    for (int i = 0; i < noofphilos; i++) {
        sem_init(&forks[i], 0, 1); 
    }

    for (int i = 0; i < noofphilos; i++) {
        ids[i] = i;
        pthread_create(&phills[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < noofphilos; i++) {
        pthread_join(phills[i], NULL);
    }

    sem_destroy(&room_sem);
    for (int i = 0; i < noofphilos; i++) {
        sem_destroy(&forks[i]); // Destroying semaphores for forks
    }

    return 0;
}
