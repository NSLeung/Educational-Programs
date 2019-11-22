#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
#include <string.h>
//fun with fork
#include <sys/types.h> 
  
void forkexample() 
{ 
    int x = 1; 
  
    if (fork() == 0) 
        printf("Child has x = %d\n", ++x); 
    else
        printf("Parent has x = %d\n", --x); 
} 
int main() 
{ 
    // forkexample(); 
    pid_t pid = fork();
    printf("HELLO WORLD!\n");
    if(pid < 0)
        return 1;
    else if(pid == 0){
        printf("child process pid: %d\n", getpid());
        printf("parent's pid: %d\n", getppid());
    }
    else{   //parent executes first, then child
        printf("return from fork, child process's pid: %d\n", pid);
        printf("original pid: %d\n", getpid());
    }
    return 0; 
} 