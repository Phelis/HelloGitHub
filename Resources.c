#include <stdio.h>    		// file operations: fopen, fwrite, fread 
#include <pthread.h>		// thread operations: 

typedef struct data {
    int id;		// index
    char* buf;		// a buffer
} Datagram;		// diagram constains data, called as datagram

pthread_mutex_t mMutex;

void *read_resource(void * argv) 
{
    printf("read_resource()");

    FILE *fp = NULL;
    Datagram * datagram = (Datagram *) argv;
    if (*datagram == NULL) 
    {
        fp = fopen("resource.res", "rb"); 
    }
    pthread_mutex_lock(&mMutex);
    //fread(,sizeof(Datagram),1, fp);
    
    fclose(fp);    // close the file
   
    pthread_mutex_unlock(&mMutext);

    pthread_exit(0);
}

void *write_resource(void* argv) 
{
    printf("write_resource()");

    FILE *fp = NULL;
    
    Datagram * datagram = (Datagram *) argv;    // cast from void pointer to datagram pointer
    if (*datagram == 0) {
        fp = fopen("resource.res", "wb");
    }

    pthread_mutex_lock(&mMutex);
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
