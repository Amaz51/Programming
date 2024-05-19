#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/shm.h>

#define MAX_SIZE 1024

void remove_duplicates(int* data, int* size) {
    int i, j, k;
    for (i = 1; i < *size; ++i) {
        for (j = i + 1; j < *size; ) {
            if (data[i] == data[j]) {
                for (k = j; k < *size - 1; ++k) {
                    data[k] = data[k + 1];
                }
                --(*size);
            } else {
                ++j;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    const char* filename = argv[1];

    int shmid = shmget(IPC_PRIVATE, MAX_SIZE * sizeof(int), IPC_CREAT | 0666);
    int* ptr = (int*) shmat(shmid, NULL, 0);

    pid_t pid1, pid2;

    if ((pid1 = fork()) == 0) {  // First child process
        int fd = open(filename, O_RDONLY);

        char buffer[MAX_SIZE];
        ssize_t size = read(fd, buffer, sizeof(buffer) - 1);
        buffer[size] = '\0';
        close(fd);

        char* token = strtok(buffer, " \n");
        int index = 1;
        while (token != NULL) {
            ptr[index++] = atoi(token);
            token = strtok(NULL, " \n");
        }
        ptr[0] = index; // size of ptr on 0 index
        ptr[index] = -1; // End marker

        exit(EXIT_SUCCESS);

    } else if (pid1 > 0) {
        if ((pid2 = fork()) == 0) {  // Second child process
            waitpid(pid1, NULL, 0);

            int size = ptr[0];
            remove_duplicates(ptr, &size);

            ptr[0] = size; // update size after removing duplicates

            exit(EXIT_SUCCESS);

        } else if (pid2 > 0) {
            waitpid(pid2, NULL, 0);

            int fd = open(filename, O_WRONLY | O_TRUNC);

            int i = 1;
            char buffer[MAX_SIZE];
            buffer[0] = '\0';

            while (i < ptr[0]) {
                char num_str[12];
                sprintf(num_str, "%d ", ptr[i]);
                strcat(buffer, num_str);
                ++i;
            }

            write(fd, buffer, strlen(buffer));
            close(fd);

            shmdt(ptr);
            shmctl(shmid, IPC_RMID, NULL);

        }
    }

    return 0;
}
