#ifndef ERRORDEFINITIONS_H
#define ERRORDEFINITIONS_H

#include <stdbool.h>

struct vexillum_error {
    char code;
};

// TODO: Make error names clearer
#define VEXILLUM_NO_ERROR (char) 0
#define VEXILLUM_ERROR_NOT_ENOUGH_MEMORY (char) 1
#define VEXILLUM_ERROR_FLAG_NOT_REGISTERED (char) 2
#define VEXILLUM_ERROR_FLAG_ALREADY_EXISTS (char) 3
#define VEXILLUM_ERROR_NO_FLAG_FOUND (char) 4
#define VEXILLUM_ERROR_INVALID_FLAG (char) 5
#define VEXILLUM_ERROR_NO_ARGUMENT_ASSOCIATED_WITH_FLAG (char) 6
#define VEXILLUM_ERROR_FLAG_NOT_SUPPORTED (char) 7

extern const char* VEXILLUM_ERROR_NAMES[];
extern const bool PRINT_ERROR_AND_PRINT_USAGE_MATRIX[];
extern const int AMOUNT_OF_ERRORS;

#endif //ERRORDEFINITIONS_H
