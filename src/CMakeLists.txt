add_library(Vexillum SHARED
        library.c
        library.h)

target_include_directories(Vexillum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})