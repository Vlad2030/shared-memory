#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

char STORAGE_ID[10] = "1946714931"; 
// shared memory name
int STORAGE_SIZE = 4096; 
// shared memory size
char data[11] = "hello world"; 
// shared memory data

void write_shared_memory(
    char data,
    char STORAGE_SIZE[10],
    int prot,
    int flags,
    int shm_fd,
    off_t offset
){
    mmap(
        data, 
        // void *addr
        STORAGE_SIZE, 
        // size_t length
        PROT_WRITE, 
        // int prot
        MAP_SHARED,
        // int flags
        shm_fd, 
        // fd
        0 
        // off_t offset
    );
}

void delete_shared_memory(
    char STORAGE_ID[10],
    int STORAGE_SIZE
){
    munmap(
        STORAGE_ID, 
        // void *addr
        STORAGE_SIZE 
        // size_t length
    );
}

void main(data) {
    int shm_fd; 
    // shared memory file descriptor
    void* ptr; 
    // pointer to shared memory object
    void* dlt; 
    // delete shared memory object
    shm_fd = shm_open(
        STORAGE_ID,
        O_CREAT | O_RDWR,
        0666
    ); 
    // create the shared memory object
    ftruncate(
        shm_fd,
        STORAGE_SIZE
    ); 
    // configure the size of the shared memory object
    ptr = write_shared_memory(
        char data,
        int STORAGE_SIZE,
        int shm_fd
    ); 
    // writing shared memory
    printf("Shared Memory sent\n");
    nanosleep(0,125000000); 
    // sleep 0.125sec
    dlt = delete_shared_memory(
        STORAGE_ID,
        STORAGE_SIZE
    ); 
    // delete shared memory object
    printf("Shared Memore cleared\n");
}