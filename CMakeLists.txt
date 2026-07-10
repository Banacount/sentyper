cmake_minimum_required(VERSION 4.3.4)
project(sentyper)

add_executable(${PROJECT_NAME} main.c)
add_library(helpers SHARED helpers.c)

# Libraries
target_link_libraries(${PROJECT_NAME} helpers)
