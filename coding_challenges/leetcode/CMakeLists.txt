cmake_minimum_required(VERSION 3.10.2)

project(LeetCode)

# name the exact source file to compile
add_executable(${PROJECT_NAME} ./src/sort_arr_freq.cpp)
add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC include)
link_directories(src)
target_link_libraries(${PROJECT_NAME} Solutions)
# add_subdirectory(tests)