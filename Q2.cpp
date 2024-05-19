#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
    int fd = open("data.txt", O_RDWR | O_APPEND);
    off_t file_size = lseek(fd, 0, SEEK_END); 
    lseek(fd, 0, SEEK_SET); 

    char* mapped_data = static_cast<char*>(mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0));
    if (mapped_data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    cout << "Content of memory-mapped region: " << mapped_data << endl;

    mapped_data[file_size - 1] = '\0'; 
    strcat(mapped_data, "-updated");

    cout << "Updated content of memory-mapped region: " << mapped_data << endl;
    if (munmap(mapped_data, file_size) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}