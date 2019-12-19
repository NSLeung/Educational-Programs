#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
/* since pipes are unidirectional, we need two pipes.
   one for data to flow from parent's stdout to child's
   stdin and the other for child's stdout to flow to
   parent's stdin */
 
#define NUM_PIPES          2
 
#define PARENT_WRITE_PIPE  0
#define PARENT_READ_PIPE   1
 
int pipes[NUM_PIPES][2];
 
/* always in a pipe[], pipe[0] is for read and 
   pipe[1] is for write */
#define READ_FD  0
#define WRITE_FD 1
 
#define PARENT_READ_FD  ( pipes[PARENT_READ_PIPE][READ_FD]   )
#define PARENT_WRITE_FD ( pipes[PARENT_WRITE_PIPE][WRITE_FD] )
 
#define CHILD_READ_FD   ( pipes[PARENT_WRITE_PIPE][READ_FD]  )
#define CHILD_WRITE_FD  ( pipes[PARENT_READ_PIPE][WRITE_FD]  )
int main()
{
    int outfd[2];   //Parent's write pipe
    int infd[2];    //Parent's read pipe
    pipe(outfd); /* Where the parent is going to write to */
    pipe(infd); /* From where parent is going to read */
    if(!fork())
    {   //CHILD PROCESS
        
        close(STDOUT_FILENO);
        close(STDIN_FILENO);
        //basically overwriting file descriptors
        dup2(outfd[0], STDIN_FILENO);   
        dup2(infd[1], STDOUT_FILENO);
        close(outfd[0]); /* Not required for the child */
        close(outfd[1]);
        close(infd[0]);
        close(infd[1]);
        // system("/usr/bin/bc -q");   //alternative to exec ig
        execlp("ls","ls",(void*)NULL);
        exit(1);
    }
    else
    {   //parent code
        char input[100];
        close(outfd[0]); /* These are being used by the child */
        close(infd[1]);
        // write(outfd[1],"2^32\n",5); /* Write to child’s stdin */
        // input[read(infd[0],input,100)] = 0; /* Read from child’s stdout */
        read(infd[0],input,100);
        printf("input: %s",input);
        close(outfd[1]);
        close(infd[0]);
    }
    return 0;
}