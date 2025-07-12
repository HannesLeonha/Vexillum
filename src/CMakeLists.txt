set(VEXILLUM_SOURCES
    Vexillum.c
    Vexillum.h
    FlagHandler.c
    FlagHandler.h
    ArgumentHandler.c
    ArgumentHandler.h
    StringLinkedList.c
    StringLinkedList.h
)

# Library
add_library(Vexillum
    ${VEXILLUM_SOURCES})

# Test Library
add_library(TestVexillum STATIC
    ${VEXILLUM_SOURCES})
