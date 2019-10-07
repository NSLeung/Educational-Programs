# test_stack : main.o
# 	clang++ main.o -o test_stack
# main.o : main.cpp
# 	clang++ -c main.cpp
# clean :
# 	rm test_stack *.o

# test_substring : substring_test.o
# 	clang++ substring_test.o -o test_substring
# substring_test.o : substring_test.cpp
# 	clang++ -c substring_test.cpp

# -strd=c++0x
dset_program : dset_height.o main_dset.o
	clang++ -std=c++11 dset_height.o main_dset.o -o  dset_program
dset_height.o : dset_height.cpp
	clang++ -c dset_height.cpp
main_dset.o : main_dset.cpp
	clang++ -std=c++11 -c main_dset.cpp
clean :
	rm dset_program *.o
