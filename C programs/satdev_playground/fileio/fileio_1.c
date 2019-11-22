#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PATH_MAX 500
int main(){
    // FILE* file = fopen("");
    char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }


   FILE* file = fopen(strcat(cwd, "/files/database"), "a+");
   if(file!=NULL){
        ssize_t read;
        size_t len = 0;
        char* line[2048];

        while ((read = getline(line, &len, file)) != -1) {
            printf("%s\n", *line);

            //do string parsing here
            int job_number = atoi(line[0]);
            // if(job)
            printf("the job number is %d\n",job_number);
        }
        // printf("we done reading the file\n");
        fclose(file);
   }
   else{
       printf("file is NULL :(");
       return 1;
   }
   return 0;
}