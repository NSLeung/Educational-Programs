#include <stdio.h>
// #include <string.h>
//declare fns to be used in struct
void printDog(char* dogType);
void printCat(char* catType);
void hi();
//define fns
void printDog(char* dogType){
  printf("%s\n",dogType);
}
void printCat(char* catType){
  printf("%s\n",catType);
}
void hi(){
  printf("hi\n");
}


//define struct
typedef struct fn_table{
  void (*printDog)(char* dogType);
  void (*printCat)(char* catType);
  void (*hi)();
} fn_table;


//main function
int main(int argc, char* argv[]){
  //intialize ftable
  fn_table ftable = {printDog, printCat, hi};
  // ftable.printDog("yorkie");
  // ftable.printCat("tabby");
  ftable.hi();
  return 0;
}
