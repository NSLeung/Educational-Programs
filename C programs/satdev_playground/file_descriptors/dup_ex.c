#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WRITE_END 1
#define READ_END 0

int main(int argc, char* argv[]){
    pid_t pid;
    int fd[2];

    char firstcmd[20];
    char frsarg[20];
    char scmd[20];
    char secarg[20];

    //argc checking before assigning argv (needs 4 additional args)
    //firstcmd firstarg scmd secarg
    if(argc == 5){
        strcpy(firstcmd, argv[1]);
        strcpy(frsarg, argv[2]);
        strcpy(scmd, argv[3]);
        strcpy(secarg, argv[4]);
    }

    pipe(fd);
    pid = fork();

    if(pid==0)
    {
        //dup2(oldfd, newfd)
        dup2(fd[WRITE_END], STDOUT_FILENO); //closes stdout before overwriting with fd[1]; same as close(STDOUT_FILENO); dup(fd[1])
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        execlp(firstcmd, firstcmd, frsarg, (char*) NULL);   //execs ls -l
        fprintf(stderr, "Failed to execute '%s'\n", firstcmd);
        exit(1);
    }
    else
    { 
        pid=fork();

        if(pid==0)  //another child
        {
            dup2(fd[READ_END], STDIN_FILENO);
            close(fd[WRITE_END]);
            close(fd[READ_END]);
            execlp(scmd, scmd, secarg,(char*) NULL);
            fprintf(stderr, "Failed to execute '%s'\n", scmd);
            exit(1);
        }
        else    //original parent
        {
            int status;
            close(fd[READ_END]);
            close(fd[WRITE_END]);
            waitpid(pid, &status, 0);
        }
    }
}