#include <stdio.h>
#include <stdlib.h>

#define CHUNK 2

static const int32_t max_word_len = 500;

//enum for exit conditions
enum {
  EXIT_SUCCEED = 0,
  EXIT_FAIL = 1,
  EXIT_BAD_ARGS = 2,
  EXIT_PANIC = 3
};

int main(int argc, char** argv){
  FILE* in_file;
  // char buf[max_word_len + 1]; //current word
  char buf[CHUNK];
  char* write;
  int32_t word_len;
  // int32_t a_char;
  int c;
  size_t nread;

  //need an argument after executing function
  if(2 != argc){
    //print error
    fprintf(stderr, "syntax: %s <file name>\n", argv[0]);
    return EXIT_BAD_ARGS;
  }
  /* Open the file for reading. */
  if (NULL == (in_file = fopen (argv[1], "r"))) {
  /* fopen failed: print an error message to stderr. */
      perror ("open file");
      return EXIT_FAIL;
   }

   //else, file is clear for reading
   write = buf;
   //initialize length to 0
   word_len = 0;
   //METHOD 1: read characters until we find end of input
   //do shortcut coding with expression inside conditional
   //a_char gets 1 character at a time from the input stream
   // while(EOF != (c = getc(in_file))){
   //   //write character into buffer
   //   // *(write++) = c;
   //   putchar(c);
   // }


   //METHOD 2: read file in chunks using size_t fread (void* ptr, size_t size, size_t n_elt,FILE* stream);
   // while ((nread = fread(buf, 1, sizeof buf, in_file)) > 0)
   //      fwrite(buf, 1, nread, stdout);

   
   //close stream
   fclose(in_file);
}
