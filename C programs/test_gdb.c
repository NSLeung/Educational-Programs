#include <stdio.h>

void func(int arg)
{
  printf("func(%d)\n",arg);
}
int main(int argc, char* argv[]){
  int localVar1 = 1, localVar2=2;
  func(localVar1 + localVar2);
  return 0;
}
