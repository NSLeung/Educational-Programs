#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//remember to link with gcc -lpthread so linker can find symbols in pthread library during linking stage

void *print_message_fn(void *ptr);

/*threads have no awareness of another, they act independently
* intuitively: independent stream of instructions that can be scheduled to run by the OS
* different than PROCESS - process contains information about pid, pgid, uid, gid, 
* environment, registers, stack, heap, file descriptions, signal actions, shared libraries, etc
* 
* THREADS - scheduled by OS and are run as independent entities because duplicate only bare
* essential resources that enable them to exist as executable code
* - exists within a process and uses its resources
* - has independent flow of control
* - dies if parent process dies
* - 'lightweight' since process takes up main overhead (compare fork to pthread_create)
* -- changes made by one thread to shared system resources are visible to all threads
* APPLICATIONS
* - efficient communication/data exchange - MPI - message passing interface 
* - parallel programming
* - overapping CPU work with I/O
* - priority scheduling
* - load balancing
* - communications
* - data dependencies
* - synchronization and race conditions
* - memory issues, I/O issues
* - program complexity


*/

/**
 * P_THREADS API
 * 1) thread management - creating, detaching, joining
 * 2) mutexes - controlling shared resources
 * 3) condition variables - create, destroy, wait and signal based on specified variable values
 * 4) synchronizers - routines that manage read/write locks
 * 
**/
int main(){
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;
    /* create independent threads of each of which will execute function */
    /**
     * pthread_create function signature:
     * int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void*(*start_routine) (void *), void *arg)
     **/
    iret1 = pthread_create(&thread1, NULL, print_message_fn, (void*) message1);
    iret2 = pthread_create(&thread1, NULL, print_message_fn, (void*) message2);

    /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

    /**
     * pthread_join function signature
     * int pthread_join(pthread_t thread, void **retval);
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 
    **/
     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}   //end of main

void *print_message_fn( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}   //end of print_message_function

