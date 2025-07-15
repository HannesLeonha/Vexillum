set(VEXILLUM_SOURCES
    Vexillum.c
    Vexillum.h
    FlagHandler.c
    FlagHandler.h
    ArgumentHandler.c
    ArgumentHandler.h
    LinkedList.c
    LinkedList.h
    ErrorHandler.c
    ErrorHandler.h
)

# Library
add_library(Vexillum
    ${VEXILLUM_SOURCES})

# Test Library
add_library(TestVexillum STATIC
    ${VEXILLUM_SOURCES})
