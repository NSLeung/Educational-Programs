#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define WRITE_END 1
#define READ_END 0
int main(int argc, char* argv[]){
    int fd[2], nbytes;
    pid_t child_pid;
    // char string[] = "Hello, World!\n";
    // char string[20];
    // strcpy(string, argv[1]);
    char readbuffer[200];

    pipe(fd);

    if((child_pid = fork()) == -1){
        perror("fork failed");
        exit(1);
    }

    if(child_pid == 0){
        // close(fd[0]); //child process closes input side of pipe
        // write(fd[1], string, (strlen(string) + 1)); //send string through output side

        dup2(fd[WRITE_END], STDOUT_FILENO);
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        execlp("/bin/ls", "ls", "-l", (char* )NULL);
        fprintf(stderr, "Failed to execute ls\n");
        exit(1);
    }
    else {
        close(fd[WRITE_END]); //parent closes output side
        nbytes = read(fd[READ_END], readbuffer, sizeof(readbuffer));
        printf("Received string: %s\n", readbuffer);
    }
    return(0);
}