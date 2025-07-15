#include "../ErrorHandler.h"

#include <stddef.h>
#include <stdio.h>

bool print_usage_enabled = false;
char* program_name = NULL;
char* program_description = NULL;

void print_usage();
void print_error(struct vexillum_error error);

void eh_set_program_name(char* name) {
    program_name = name;
}

void eh_enable_usage_message(const bool enabled, char* description) {
    print_usage_enabled = enabled;
    program_description = description;
}

void print_error(const struct vexillum_error error) {
    // TODO: support printing detailed error (like: option e is not recognised)
    printf("%s\n", eh_get_error_string(error));
}

void print_usage() {
    // TODO: get the flags n stuff
    printf("Usage: %s\n\n%s\n", program_name, program_description);
}

struct vexillum_error eh_create_error(const char error_code) {
    const struct vexillum_error error = {error_code};

    if(print_usage_enabled) {
        const bool should_print_error = PRINT_ERROR_AND_PRINT_USAGE_MATRIX[(int)error_code*2];
        const bool should_print_usage = PRINT_ERROR_AND_PRINT_USAGE_MATRIX[(int)error_code*2+1];

        if(should_print_error) {
            print_error(error);
        }

        if(should_print_error && should_print_usage) {
            printf("\n");
        }

        if(should_print_usage) {
            print_usage();
        }
    }

    return error;
}

const char* eh_get_error_string(const struct vexillum_error error) {
    if(error.code >= sizeof(VEXILLUM_ERROR_NAMES)/sizeof(VEXILLUM_ERROR_NAMES[0])) {
        return "Unknown Error";
    }

    return VEXILLUM_ERROR_NAMES[error.code];
}