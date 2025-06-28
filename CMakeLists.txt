cmake_minimum_required(VERSION 3.31)

project(Vexillum VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_library(Vexillum SHARED src/library.c)
