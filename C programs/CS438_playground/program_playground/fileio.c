#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "extern_def.h"
extern int id;

int main(int argc, char** argv){
    printf("%d\n",id);
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("no such file\n");
        printf("you gave %s\n", argv[1]);
        exit(1);
    }
    char line[256];
    const char s[2] = " ";
    char* nodeid_str;
    char* nodecost_str;
    int nodeid, nodecost;
    int i = 0;
    
    while(fgets(line, sizeof(line), fp)){
        // printf("%s", line);
        // if(i == 0){
            //get first token
            nodeid_str = strtok(line, s);
            nodeid = atoi(nodeid_str);
        // }

        // while(token != NULL){
            printf("%d\n", nodeid); 
            nodecost_str = strtok(NULL, s);
            nodecost = atoi(nodecost_str);
            printf("%d\n", nodecost);
        // }
        // i++;
    }
    fclose(fp);
    return 0;
}