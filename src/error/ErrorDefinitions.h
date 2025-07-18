#ifndef ERRORDEFINITIONS_H
#define ERRORDEFINITIONS_H

#include <stdbool.h>

struct vexillum_error {
    char code;
};

#define VEXILLUM_NO_ERROR (char) 0
#define VEXILLUM_ERROR_NOT_ENOUGH_MEMORY (char) 1
#define VEXILLUM_ERROR_FLAG_NOT_REGISTERED (char) 2
#define VEXILLUM_ERROR_NO_FLAG_FOUND (char) 3
#define VEXILLUM_ERROR_INVALID_FLAG (char) 4

extern const char* VEXILLUM_ERROR_NAMES[];
extern const bool PRINT_ERROR_AND_PRINT_USAGE_MATRIX[];
extern const int AMOUNT_OF_ERRORS;

#endif //ERRORDEFINITIONS_H
