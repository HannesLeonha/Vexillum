#ifndef ERRORDEFINITIONS_H
#define ERRORDEFINITIONS_H

struct vexillum_error {
    char code;
};

#define VEXILLUM_NO_ERROR (char) 0
#define VEXILLUM_ERROR_NOT_ENOUGH_MEMORY (char) 1
#define VEXILLUM_ERROR_NO_FLAG_FOUND (char) 2

const char* VEXILLUM_ERROR_NAMES[] = {
    "No error",
    "The program has run out of memory",
    "The given flag hasn't been registered"
};

const bool PRINT_ERROR_AND_PRINT_USAGE_MATRIX[] = {
    false, false, // VEXILLUM_NO_ERROR
    true, false,  // VEXILLUM_ERROR_NOT_ENOUGH_MEMORY
    true, false,  // VEXILLUM_ERROR_NO_FLAG_FOUND
};

#endif //ERRORDEFINITIONS_H
