set(VEXILLUM_SOURCES
    Vexillum.c
    Vexillum.h CACHE INTERNAL "")

# Library
add_library(Vexillum
    ${VEXILLUM_SOURCES})

# Test Library
add_library(TestVexillum STATIC
    ${VEXILLUM_SOURCES})
