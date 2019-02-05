#include <stdlib.h>
#include <stdio.h>

int main(){
  struct Student
  {
    double GPA;
    char name[15];
    char netID[9];
    char major[30];
  };

  struct Student Nayman = {3.5, "Nayman", "661699482", "Electrical Engineering"};
  printf("%d\n", Nayman.name[7]);

  // printf("%ld",sizeof(unsigned int));
  //exit success
  return 0;
}
