#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
#include <string.h>
//fun with fork
#include <sys/types.h> 

#define FORK_EX 0
#define FD_DUP_EX 1
#define TO_RUN fd_dup_ex
  
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
    if(TO_RUN == FORK_EX){
        // forkexample(); 
        pid_t pid = fork();
        printf("HELLO WORLD!\n");
        if(pid < 0)
            return 1;
        else if(pid == 0){  //child process!
            printf("child process pid: %d\n", getpid());
            printf("parent's pid: %d\n", getppid());
        }
        else{   //parent executes first, then child
            printf("return from fork, child process's pid: %d\n", pid);
            printf("original pid: %d\n", getpid());
        }
        return 0; 
    }

    else if(TO_RUN == FD_DUP_EX){
        int p[2];
        char *argv[2];
        argv[0] = "wc"; //word count system call
        argv[1] = 0;
        pipe(p);
        if(fork() == 0){
            close (STDIN);  //child closing stdin
            dup(p[STDIN]);  //copies fd of read end of the pipe into its fd i.e 0 (STDIN), dupes before closing
            close(p[STDIN]);
            close(p[STDPIT]);
            exec("/bin/wc", argv);  //wc reads from pipe
        }
        else{
            write(p[STDOUT], "hello world\n", 12);
            close(p[STDIN]);
            close(p[STDOUT]);
        }
    }
} 