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

// executing
#define NUM_PIPES          2
#define PARENT_WRITE_PIPE  0
#define PARENT_READ_PIPE   1
int pipes[NUM_PIPES][2];
#define READ_FD  0
#define WRITE_FD 1
#define PARENT_READ_FD  ( pipes[PARENT_READ_PIPE][READ_FD]   )
#define CHILD_WRITE_FD  ( pipes[PARENT_READ_PIPE][WRITE_FD]  )
static int newfd[2];

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
    
    //pid_t child = fork();
    pid_t child = -1;
    if (child == -1) {
        /* fork failed */
    }
    if (child == 0) {
        // get job number
        // reopen stdout and stderr
        // direct those to file then execute 
        // FILE* f = freopen("/var/log/at/<job number>", "w", stdout)
        // execl("/bin/sh", "sh", "-c", y->task, (char*)NULL);
        
        dup2(CHILD_WRITE_FD, STDOUT_FILENO);
        /* Close fds not required by child. Also, we don't
           want the exec'ed program to know these existed */
        close(CHILD_WRITE_FD);
        close(PARENT_READ_FD);
        // execl("/bin/sh", "sh", "-c", "date", (char*)NULL); 
        execlp("ls","ls",(void*)NULL);
        exit(1);

    } else {
        //wait();
        //write status of job on last line
        //remove from .../at/database
        //insert_job_output_into_db(char* out, char* err, char* status, y->job_number);
        //free(y);
    
        char buffer[100];
        int count;

        /* close fds not required by parent */
        close(CHILD_WRITE_FD);

        // Read from child’s stdout
        count = (int)read(PARENT_READ_FD, buffer, sizeof(buffer)-1);
    //dup2(newfd[0], STDOUT_FILENO);
    //dup2(newfd[1], STDERR_FILENO);
        if (count >= 0) {
            buffer[count] = 0;
            printf("buffer: %s",buffer);
            // P_INFO("Buffer is %s\n", buffer);
            // insert_job_output_into_db(buffer, "stderr", "Job succeeded", 1);
            // print_all_from_db(); 
        } else {
            //printf("IO Error\n");
            // P_INFO_STR("YUCK");
        }


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