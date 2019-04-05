cmake_minimum_required(VERSION 3.13)
project(accumulate)
add_compile_options(
    -fsanitize=thread
    -g)
include_directories(.)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread)
