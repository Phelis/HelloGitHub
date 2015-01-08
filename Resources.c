#include "Resources.h"

#include <stdio.h>    		// file operations: fopen, fwrite, fread
#include <pthread.h>		// thread operations: 
#include <sys/mman.h>
#include <sys/file.h>		// O_CREAT, O_RDWR
#include <unistd.h>		// 

// the name of shared memory
const char *shared_memory = "shared_memory";

pthread_mutex_t mMutex;

void *read_resource(void * argv) 
{
    printf("read_resource()");

    FILE *fp = NULL;
    Datagram * datagram = (Datagram *) argv;
    if (datagram == NULL) 
    {
        fp = fopen("resource.res", "rb"); 
    }
    pthread_mutex_lock(&mMutex);
    //fread(,sizeof(Datagram),1, fp);
    
    fclose(fp);    // close the file
   
    pthread_mutex_unlock(&mMutex);

    pthread_exit(0);
}

void *write_resource(void* argv) 
{
    printf("write_resource()");

    FILE *fp = NULL;
    
    Datagram * datagram = (Datagram *) argv;    // cast from void pointer to datagram pointer
    if (datagram == NULL) {
        fp = fopen("resource.res", "wb");
    }

    pthread_mutex_lock(&mMutex);

    // unlink the shared memory
    shm_unlink(shared_memory);
    
    // open a block of shared memory
    int shared_memory_fd = shm_open(shared_memory, O_CREAT|O_RDWR, 0666);
    if (shared_memory_fd)
    {
        perror("failed to open a block of shared memory");
    }
    
    int r = ftruncate(shared_memory_fd, getpagesize());	// page size is equal to 4096
    if (r!=0)
    {
        perror("failed to truncate the block");
    }

    void * memory_map = mmap(0, getpagesize(), PROT_READ| PROT_WRITE, MAP_SHARED, shared_memory_fd, 0);
    if (memory_map == MAP_FAILED) 
    {
        perror("failed to map to the block");
    }
    
    close(shared_memory_fd);    // close the file descriptor

    //u_long *d = (u_long *) memory_map; // the size of u_long is 8 bytes
    

    r = munmap(memory_map, getpagesize());
    if (r != 0) 
    {
        perror("failed to un-map to a block");
    }

    r = shm_unlink(shared_memory);
    if (r != 0)
    {
        perror("failed to unlink a block");
    }
  //fwrite(,sizeof(Datagram), 1, fp);

    fclose(fp);
    pthread_mutex_unlock(&mMutex);

    pthread_exit(0);
}


void load_resource(Datagram *data)
{
    pthread_t load_thread;
    pthread_create(&load_thread, NULL, read_resource, (void *) &data);

    pthread_join(load_thread, NULL);
}

void save_resource(Datagram *data)
{
    pthread_t save_thread;
    pthread_create(&save_thread, NULL, write_resource, (void *) &data);

    pthread_join(save_thread, NULL);
}
