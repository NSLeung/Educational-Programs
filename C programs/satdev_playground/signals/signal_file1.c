#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
// #include <ctype.h>
/*
Signals are software generated interrupts that can be used to transfer information across processes
*/

/**
 * Use Cases:
 * A program error such as dividing by zero or issuing an address outside the valid range.
A user request to interrupt or terminate the program. Most environments are set up to let a user suspend the program by typing C-z, or terminate it with C-c. Whatever key sequence is used, the operating system sends the proper signal to interrupt the process.
The termination of a child process.
Expiration of a timer or alarm.
A call to kill or raise by the same process.
A call to kill from another process. Signals are a limited but useful form of interprocess communication.
An attempt to perform an I/O operation that cannot be done. Examples are reading from a pipe that has no writer (see Pipes and FIFOs), and reading or writing to a terminal in certain situations (see Job Control).
**/

/**
 * SIGNAL lifecycle
 * 1) Generation:
 * a) Errors (usually synchronous with respect to internal process, though somme can definitely be async) 
 * - program has done something invalid and cannot continue execution (ex: divide by zero, page fault)
 * b) external events -  I/O or other processes - arrival of input, expiration of a time, termination of a child process
 * c) explicit requests - library function like kill (generates signal)
 * 
 * 2) Delivery
 * After signal generation, it becomes pending (usually just for a short time), then it is delivered
 * if blocked (sigprocmask for process/single-threaded program vs sigaction.sa_mask for signal handler)
 *  - remains pending until unblocked 
 * Program can accept default action, 
 * 
 */

/**
 * Signal function vs specifying sigaction struct
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
 * signal() doesn't block other signals from arriving while the current handler is running
 */
static uint8_t first_message = 0;
//quick function declaration (don't need if defined?)
// void sighandler(int signum);
void sighandler(int signum){
    printf("Caught signal %d, coming out..\n", signum);
    // exit(1);
    first_message = 1;

}
int main(){
    struct sigaction act;
    printf("size in bytes of act: %ld \n", sizeof(act));
    memset(&act, 0, sizeof(act));
    act.sa_handler = sighandler;
    sigaction(SIGINT, &act, NULL); // is this how to handle a signal for one thread? can also just set all other threads to ignore the signal
    while (!first_message) {
        // sleep(600); // sleep 10 min
        printf("Going to sleep for 2 seconds...\n");
        sleep(2);   //sleep 2 seconds
    }

    //C standard signal function (usually recommended to use sigaction)
    /*
    //function definition:
    //sighandler_t signal(int signum, sighandler_t handler);
    signal(SIGINT, sighandler); //SIGINT comes from ctrl-c
    while(1){
        printf("Going to sleep for a second..\n");
        sleep(1);

    }
    */

    return 0;
}



