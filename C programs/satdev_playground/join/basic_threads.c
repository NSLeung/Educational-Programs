#include <sys/types.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>


void *thread_print(void *x){
    // (void*)x;
    printf("Hello World\n");
}
int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, thread_print, (void*)NULL);
    pthread_exit((void*)NULL);
    return 0;
}