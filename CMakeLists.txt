cmake_minimum_required(VERSION 3.31)
project(Vexillum VERSION 0.1 LANGUAGES C)

enable_testing()

set(CMAKE_C_STANDARD 11)

# Config
set(BUILD_SHARED_LIBS ON)

add_subdirectory(src)
add_subdirectory(test)
