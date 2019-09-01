#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 256
#define var1 1
#define var2 2
#define var3 (var1+var2)*2
int main(){
  printf("Hello, World!\n");
  // int a[3] = {1, 2, 3};
  // char str[4] = "hi";
  // char readStr[40];
  // // printf("%d\n",a[2]);
  // // printf("%p",str[3]);
  //
  // //scanf unsafe
  // // scanf("%s",readStr);
  //
  // //fgets(char* s, int size, FILE* stream)
  // /**
  //  * fgets reads string from stream - stops reading until end of line (generally
  //  * better for parsing IO)
  //  * fscanf reads until white space and does not store
  //  * @param readStr      array of characters to store
  //  * @param MAX_STR_SIZE size of array
  //  * @param stdin        stream to read
  //  */
  // fgets(readStr, MAX_STR_SIZE, stdin);
  // /* Remove trailing newline, if there. */
  //
  //   if ((strlen(readStr) > 0) && (readStr[strlen (readStr) - 1] == '\n'))
  //       readStr[strlen (readStr) - 1] = '\0';
  // printf("%s and %s",readStr, str );
  // printf("%d", var3);
  // printf("Hello, World!\n");
  int a[3] = {1, 2, 3};
  char str[4] = "hi";
  char readStr[40];
  // printf("%d\n",a[2]);
  // printf("%p",str[3]);

  //scanf unsafe
  // scanf("%s",readStr);

  //fgets(char* s, int size, FILE* stream)
  /**
   * fgets reads string from stream - stops reading until end of line (generally
   * better for parsing IO)
   * fscanf reads until white space and does not store
   * @param readStr      array of characters to store
   * @param MAX_STR_SIZE size of array
   * @param stdin        stream to read
   */
  // fgets(readStr, MAX_STR_SIZE, stdin);
  /* Remove trailing newline, if there. */

    if ((strlen(readStr) > 0) && (readStr[strlen (readStr) - 1] == '\n'))
        readStr[strlen (readStr) - 1] = '\0';
  // printf("%s and %s",readStr, str );
  int minutes = 1;
  int seconds = 10;
  sprintf(readstr, "%02d:%02d", minutes, seconds);
  printf(readstr);
  return 0;
}
