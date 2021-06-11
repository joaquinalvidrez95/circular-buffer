cmake_minimum_required(VERSION 3.0.0)
project(circular_buffer VERSION 0.1.0)

add_subdirectory(circular_buffer)
add_executable(circular-buffer-demo main.c)

target_link_libraries(circular-buffer-demo
    circular-buffer
)
