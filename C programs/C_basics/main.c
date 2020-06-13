#include <stdio.h>
#include <string.h>
//c throws warning for implicit declaration
int add(int a, int b);  //function prototype declared here
void foo(void);
void strcpy2(char* s, char* t);
int main(int argc, char** argv){
    // int a = 3;
    // int b = 2;
    // int c;
    // c = add(a, b);
    // printf("result: %d", c);

    // foo();

    // unsigned int compzero = 0xFFFF;
    // unsigned int compzero = ~0;
    // printf("compzero: %x", compzero);
    // printf("sizeof unsigned int: %ld", sizeof(unsigned int));

    char a[10] = "hello";
    char b[10] = "hellol";
    char c[10] = "hi"" fans";
    // strcpy2(a, b);
    // printf("string: %s", a);

    // printf("%s",c);

    //url parsing
    // const char text[] = "http://hostname:8888/servlet/rece";
    // char text[200];
    // strcpy(text,argv[1]);
    char ip[100];
    int port = 80;
    char page[100];

    // sscanf(text, "http://%99[^:]:%99d/%99[^\n]", ip, &port, page);
    // printf("ip = \"%s\"\n", ip);
    // printf("port = \"%d\"\n", port);
    // printf("page = \"%s\"\n", page);

    char tmp_source[] = "http://hostname/servlet/rece";
    int succ_parsing = 0;
    

    // Parsing the tmp_source char*
    if (sscanf(tmp_source, "http://%99[^:]:%i/%199[^\n]", ip, &port, page) == 3) { succ_parsing = 1;}
    else if (sscanf(tmp_source, "http://%99[^/]/%199[^\n]", ip, page) == 2) { succ_parsing = 1;}
    else if (sscanf(tmp_source, "http://%99[^:]:%i[^\n]", ip, &port) == 2) { succ_parsing = 1;}
    else if (sscanf(tmp_source, "http://%99[^\n]", ip) == 1) { succ_parsing = 1;}

    printf("tmp_source = \"%s\"\n", tmp_source);
	printf("*ip = \"%s\"\n", ip);
	printf("*page = \"%s\"\n", page);
	printf("*port = \"%d\"\n", port);

    return 0;
}
int add(int a, int b){
    return a + b;
}

//signed and unsigned expressions force signed to promote to unsigned
void foo(void){

    unsigned int a = 6;
    int b = -20;

    (a+b > 6) ? puts("> 6") : puts("<= 6");

}

void strcpy2(char* s, char* t){
    while((*s++ = *t++) != '\0');
}