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
    pid_t pid;
    pid = fork();
    
    int key=shmget(1221, sizeof(struct SMP) * 3, 0 );  
    struct SMP* ptr= (struct SMP*) shmat(key, NULL, 0);
    sem_init(&ptr[0].availability,0,1);
    sem_wait(&ptr[0].availability);
    sem_init(&ptr[1].availability,0,1);
    sem_wait(&ptr[1].availability);
    if (pid == 0) { // child process
        
        
        char input[MAX_SIZE];
        int fd = open("data.txt", O_RDONLY);
        if (fd == -1) {
            perror("Failed to open file");
            exit(1);
        }

        ssize_t size = read(fd, input, sizeof(input) - 1);
        if (size == -1) {
            perror("Failed to read file");
            close(fd);
            exit(1);
        }
        input[size] = '\0';

        close(fd);

        printf("Read data: %s\n", input);

        int sum = 0, count = 0;
        char *token = strtok(input, " \n");

        while (token != NULL) {
            int number = atoi(token);
            sum += number;
            count++;
            token = strtok(NULL, " \n");
        }

        ptr[0].sum=sum;
        ptr[0].count=count;

        printf("\nCount is: %d\n", count);
        printf("Sum is: %d\n", sum);
        
        sem_post(&ptr[0].availability);
    } else if (pid > 0) 
    { // parent process
            char input[MAX_SIZE];
        int fd = open("data1.txt", O_RDONLY);
        if (fd == -1) {
            perror("Failed to open file");
            exit(1);
        }

        ssize_t size = read(fd, input, sizeof(input) - 1);
        if (size == -1) {
            perror("Failed to read file");
            close(fd);
            exit(1);
        }
        input[size] = '\0'; // Null-terminate the string

        close(fd);

        printf("Read data from second file: %s\n", input);

        int sum = 0, count = 0;
        char *token = strtok(input, " \n");

        while (token != NULL) {
            int number = atoi(token);
            //printf("%d ", number);
            sum += number;
            count++;
            token = strtok(NULL, " \n");
        }

        printf("\nCount from second file is: %d\n", count);
        printf("Sum from second file is: %d\n", sum);
        ptr[1].sum=sum;
        ptr[1].count=count;
        sem_post(&ptr[1].availability);

        

        wait(NULL);
    } else {
        perror("fork failed");
        exit(1);
    }

    

    shmdt(ptr);
    return 0;
}
