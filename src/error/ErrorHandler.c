#include "ErrorHandler.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../FlagHandler.h"
#include "../util/LinkedList.h"

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
    const int amount_of_flags = ll_list_length(fh_short_flags);

    char* flagString = malloc(sizeof(char) * (amount_of_flags + 1));
    flagString[amount_of_flags] = '\0';

    for(int i = 0; i < amount_of_flags; i++) {
        flagString[i] = *(char*) ll_get_list_element(fh_short_flags, i);
    }

    printf("Usage: %s %s [ARGUMENTS]...\n%s\n", program_name, flagString, program_description);

    for(int i = 0; i < amount_of_flags; i++) {
        char* long_flags = ll_get_list_element(fh_long_flags, i);
        char* description = ll_get_list_element(fh_flag_descriptions, i);

        printf(" -%c%c %-20s %s", flagString[i], long_flags != NULL ? ',' : ' ', long_flags != NULL ? long_flags : "", description != NULL ? description : "");
    }

    free(flagString);
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