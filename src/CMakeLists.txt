set(VEXILLUM_SOURCES
    Vexillum.c
    Vexillum.h
    FlagHandler.c
    FlagHandler.h
    ArgumentHandler.c
    ArgumentHandler.h
    util/LinkedList.c
    util/LinkedList.h
    error/ErrorHandler.c
    error/ErrorHandler.h
    error/ErrorDefinitions.h
    error/ErrorDefinitions.c
)

# Library
add_library(Vexillum
    ${VEXILLUM_SOURCES})

# Test Library
add_library(TestVexillum STATIC
    ${VEXILLUM_SOURCES})
