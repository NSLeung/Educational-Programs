
// #include <iostream>
#include <stdio.h>
int main(int argc, char** argv) {
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    printf("Have %d arguments\n", argc);
    for (int i = 0; i < argc; ++i) {
        // std::cout << argv[i] << std::endl;
        printf("argv: %s\n", argv[i]);
    }
}