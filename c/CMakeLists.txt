cmake_minimum_required(VERSION 3.0.0)
project(circular-buffer-demo VERSION 0.1.0)

add_subdirectory(circular_buffer)
add_executable(circular-buffer-demo-c main.c)
target_compile_options(circular-buffer-demo-c PRIVATE -Wall -Wextra -pedantic -Werror)

target_link_libraries(circular-buffer-demo-c
    circular-buffer
)
