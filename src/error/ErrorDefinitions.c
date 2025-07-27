#include "ErrorDefinitions.h"

const char* VEXILLUM_ERROR_NAMES[] = {
    "No error",
    "The program has run out of memory",
    "The given flag hasn't been registered",
    "The given short_flag has already been registered",
    "Invalid flag found",
    "Malformed flag found",
    "No argument was found after a flag that needs an argument",
    "The given flag is not supported by the program",
};

const bool PRINT_ERROR_AND_PRINT_USAGE_MATRIX[] = {
    false, false, // VEXILLUM_NO_ERROR
    true, false,  // VEXILLUM_ERROR_NOT_ENOUGH_MEMORY
    true, false,  // VEXILLUM_ERROR_FLAG_NOT_REGISTERED
    true, false,  // VEXILLUM_ERROR_FLAG_ALREADY_EXISTS
    true, true,   // VEXILLUM_ERROR_NO_FLAG_FOUND
    true, true,   // VEXILLUM_ERROR_INVALID_FLAG
    true, true,   // VEXILLUM_ERROR_NO_ARGUMENT_ASSOCIATED_WITH_FLAG
    true, true,   // VEXILLUM_ERROR_FLAG_NOT_SUPPORTED
};

const int AMOUNT_OF_ERRORS = 8;
