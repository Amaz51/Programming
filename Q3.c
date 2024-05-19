#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 1024

sem_t traffic_lights_sem[4];  // Semaphore for each traffic light
sem_t intersection_lock;  // Binary semaphore for intersection

int generaterandomnumber() {
    return rand() % 10 + 1; // Generate random number between 1 and 10
}

void* traffic_lights(void* arg) {
    int tid = *((int*)arg);
    free(arg); // Free memory allocated for *tid

    int numberofcars = generaterandomnumber();
    printf("Traffic light %d: %d cars waiting\n", tid, numberofcars);

    while (numberofcars > 0) {
        sem_wait(&intersection_lock); // Lock the intersection

        // Allow cars to pass one by one
        for (int i = 0; i < numberofcars && i < 7; i++) {
            printf("Traffic light %d: Car %d is passing\n", tid, i + 1);
            sleep(1); // Simulate the time taken for a car to pass
            numberofcars--;
        }

        if (numberofcars > 0) {
            printf("Traffic light %d: Remaining cars %d, giving another green signal\n", tid, numberofcars);
        }

        sem_post(&intersection_lock); // Unlock the intersection
        sleep(1); // Simulate the time taken for the traffic light to switch
    }

    printf("Traffic light %d: No more cars waiting\n", tid);
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 4; i++) {
        sem_init(&traffic_lights_sem[i], 0, 1);
    }
    sem_init(&intersection_lock, 0, 1); // Initialize the binary semaphore

    pthread_t lights[4];

    for (int i = 0; i < 4; i++) {
        int* Trafficlight = malloc(sizeof(int));
        *Trafficlight = i; // Set the traffic light ID
        pthread_create(&lights[i], NULL, traffic_lights, Trafficlight);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(lights[i], NULL);
    }

    for (int i = 0; i < 4; i++) {
        sem_destroy(&traffic_lights_sem[i]);
    }
    sem_destroy(&intersection_lock); // Destroy the binary semaphore

    return 0;
}
