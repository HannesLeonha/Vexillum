#include "ErrorHandler.h"

#include <stddef.h>
#include <stdio.h>

const char* VEXILLUM_ERROR_NAMES[] = {
    "No error",
    "Flag not found",
    "Flag got eaten"
};

bool print_usage_enabled = false;
char* program_name = NULL;
char* program_description = NULL;

void print_program_usage();
void print_error(struct vexillum_error error, bool print_usage);

void eh_set_program_name(char* name) {
    program_name = name;
}

void eh_enable_usage_message(const bool enabled, char* description) {
    print_usage_enabled = enabled;
    program_description = description;
}

void print_error(const struct vexillum_error error, const bool print_usage) {
    // TODO: support printing detailed error (like: option e is not recognised)
    printf("%s\n", eh_get_error_string(error));

    if(print_usage) {
        print_program_usage();
    }
}

void print_program_usage() {
    // TODO: get the flags n stuff
    printf("\nUsage: %s\n\n%s", program_name, program_description);
}

struct vexillum_error eh_create_error(const char error_code, const bool print_usage) {
    const struct vexillum_error error = {error_code};

    if(print_usage_enabled && error_code != (char) 0) {
        print_error(error, print_usage);
    }

    return error;
}

const char* eh_get_error_string(const struct vexillum_error error) {
    if(error.code >= sizeof(VEXILLUM_ERROR_NAMES)/sizeof(VEXILLUM_ERROR_NAMES[0])) {
        return "Unknown Error";
    }

    return VEXILLUM_ERROR_NAMES[error.code];
}