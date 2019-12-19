#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){
    /**
     * //array of file descriptors (used to return 2 file descriptors referring to ends of pipe)
     * pipefd[0] refers to read end of the pipe
     * pipefd[1] - write end of pipe
     */
    int pipefd[2];  
    pid_t cpid; //declaration of child process id
    char buf;

    if (argc != 2) {    //user must pass 1 additional arguments
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {   //create pipe + error checking
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();  //returns child process id
    if (cpid == -1) {   //error checking
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */

        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } 
    // else {            /* Parent writes argv[1] to pipe */
    //     close(pipefd[0]);          /* Close unused read end */
    //     write(pipefd[1], argv[1], strlen(argv[1]));
    // }
     else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}