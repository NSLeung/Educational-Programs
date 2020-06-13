#include <pthread.h>
#include <stdio.h>

void* printHello(void* unused_param)
{
    printf("Hello, World!\n");
}

int main(){
    pthread_t tid;
    pthread_create(&tid, 0, printHello, (void*) 0);
    pthread_exit(NULL);
    return 0;
}