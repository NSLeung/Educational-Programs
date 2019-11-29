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

#define READ_FD 0
#define WRITE_FD 1
// static int fd[2];

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

static int outfd[2];   //Parent's write pipe
static int infd[2];    //Parent's read pipe
// static int fd[2];

void daemonize(void)
{
    printf("daemonizing\n");
    pid_t pid, sid;
    int fd;

	// Already a daemon? Parent process is init.d => parent pid = 1
	if ( getppid() == 1 )
		return;

	switch ( pid = fork() ) {
    case -1: // Error
        printf("failed to fork");
        exit(EXIT_FAILURE);
    case 0: // Child process
        break;
    default: // Kills the Parent Process, orphaning this one and making initd adopt it
        exit(EXIT_SUCCESS);
	}

	// Create a new SID for the child process
	sid = setsid();
	if (sid < 0) {
        // P_ERR_STR("Failure to setsid - exiting");
        printf("Failure to setsid - exiting");
		exit(EXIT_FAILURE);
	}

	// change the current working directory
	if ((chdir("/")) < 0)  {
        // P_ERR_STR("Failure to chdir - exiting");
        printf("Failure to chdir - exiting");
		exit(EXIT_FAILURE);
	}
	fd = open("/dev/null",O_RDWR, 0);
	if (fd != -1) {
        
        
		dup2(fd, STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		if (fd > 2)
			close (fd);
	}
    
	else {
		// P_ERR_STR("Failure to close STDs - exiting");
        printf("Failure to close STDs - exiting");
		exit(EXIT_FAILURE);
	}

	// Resetting File Creation Mask
	umask(027);
    // printf("end of daemon code");
}


void* executor(void* x) { // what happens if signal gets sent before it can register to ignore?
  
    // P_INFO_STR("EXECUTOR");
    printf("executor thread!\n");
    (void)x; 
    //job* y = (job*)x;
    //char* task = y->task;
    //int job_number = y->job_number;

    // ignore SIGUSR1
    sigset_t set;
    sigaddset(&set, SIGUSR1);
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    // execute task
    //redirect file descriptors to describe errors
    
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

    return (void*) NULL;
}


//remember to compile with -pthread or -lpthread
int main(int argc, char* argv[]){

    printf("we in main\n");
    /*
    if(pipe(outfd)) == -1){
            printf("pipe broken \n");
    }
    if(pipe(infd)) == -1){
            printf("pipe broken \n");
    }
    
    dup2(STDOUT_FILENO, fd[0]);
    dup2(STDERR_FILENO, fd[1]);
    */
    // daemonize();

    pthread_t tid;
    printf("starting up executor thread\n");
    if(pthread_create(&tid, NULL, executor, (void*) NULL) != 0)
        printf("executor thread failed to start\n");
    pthread_exit((void*)NULL);

    return 0;
}