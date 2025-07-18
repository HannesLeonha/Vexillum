#include "ErrorDefinitions.h"

const char* VEXILLUM_ERROR_NAMES[] = {
    "No error",
    "The program has run out of memory",
    "The given flag hasn't been registered",
    "Invalid flag found",
    "Malformed flag found"
};

const bool PRINT_ERROR_AND_PRINT_USAGE_MATRIX[] = {
    false, false, // VEXILLUM_NO_ERROR
    true, false,  // VEXILLUM_ERROR_NOT_ENOUGH_MEMORY
    true, false,  // VEXILLUM_ERROR_FLAG_NOT_REGISTERED
    true, true,  // VEXILLUM_ERROR_NO_FLAG_FOUND
    true, true,  // VEXILLUM_ERROR_INVALID_FLAG
};

const int AMOUNT_OF_ERRORS = 5;
