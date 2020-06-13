#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#define EXEC_SECTION 2


int main (int argc, char** argv) {
    if( EXEC_SECTION == 0){
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
    }

    //- $ at [YYYY:][MM:][DD:][HH:][mm:]SS <task>
    else if ( EXEC_SECTION == 1){
        int16_t date[6];
        memset(date, 0, sizeof(date));
        uint8_t date_index = 0;
        char* endptr = NULL;

        char* temp = strtok(argv[1], ":");
        while (temp != NULL) {
            printf("date_index: %d\n", date_index);
            date[date_index] = (int16_t) strtol(temp, &endptr, 10);
            date_index++;
            temp = strtok(NULL, ":");
            
        }

        int i = 0;
        for (i = 0; i < 7; i++){
            printf("date [%d]: %d\n", i, date[i]);
        }
    }
    else if(EXEC_SECTION == 2){
        if(!strcmp(argv[1], "info")){
            printf("got it?");
        }
        else{
            printf("nope..");
        }
    }

   return(0);
}