#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/shm.h>
#include <semaphore.h>

#define MAX_SIZE 1024

struct SMP
{
    int sum;
    int count;
    sem_t availability;
};

int main(int argc, char* argv[]) {
    // Create shared memory
    int key = shmget(1221, sizeof(struct SMP) * 3, IPC_CREAT | IPC_EXCL | 0666); 
    if (key == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory
    struct SMP* ptr = (struct SMP*) shmat(key, NULL, 0);
    if (ptr == (void*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    int x, y;
    if (sem_getvalue(&ptr[1].availability, &x) == -1) {
        perror("sem_getvalue");
        exit(EXIT_FAILURE);
    }
    if (sem_getvalue(&ptr[2].availability, &y) == -1) {
        perror("sem_getvalue");
        exit(EXIT_FAILURE);
    }

    while (x == 0 || y == 0) {
        printf("Waiting\n");
        sleep(1); 
        if (sem_getvalue(&ptr[1].availability, &x) == -1) {
            perror("sem_getvalue");
            exit(EXIT_FAILURE);
        }
        if (sem_getvalue(&ptr[2].availability, &y) == -1) {
            perror("sem_getvalue");
            exit(EXIT_FAILURE);
        }
    }

    // Compute sum and count
    int sum = ptr[1].sum + ptr[2].sum;
    int count = ptr[1].count + ptr[2].count;

    // Print results
    printf("Sum is: %d\n", sum);
    printf("Count is: %d\n", count);

    if (count != 0) {
        printf("Average is: %d\n", sum / count);
    } else {
        printf("Count is zero, cannot compute average\n");
    }

    if (shmdt(ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    shmctl(key, IPC_RMID, NULL);
    return 0;
}
