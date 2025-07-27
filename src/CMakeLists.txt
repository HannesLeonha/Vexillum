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

# Copy the header into the output
# TODO: Make the configure import the ErrorDefinitions into the header for code separation
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Vexillum.h ${CMAKE_CURRENT_BINARY_DIR}/Vexillum.h COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/error/ErrorDefinitions.h ${CMAKE_CURRENT_BINARY_DIR}/error/ErrorDefinitions.h COPYONLY)

# Test Library
add_library(TestVexillum STATIC
    ${VEXILLUM_SOURCES})
