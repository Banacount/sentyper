cmake_minimum_required(VERSION 4.3.4)
project(sentyper)

add_executable(${PROJECT_NAME} main.c)
add_library(helpers SHARED helpers.c)
add_library(config SHARED config.c)

# Libraries
target_link_libraries(${PROJECT_NAME} helpers)
target_link_libraries(${PROJECT_NAME} config)
