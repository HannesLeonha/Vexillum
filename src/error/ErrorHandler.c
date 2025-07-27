#include "ErrorHandler.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../FlagHandler.h"
#include "../util/LinkedList.h"

bool print_usage_enabled = false;
char* program_name = NULL;
char* program_description = NULL;
char* program_arguments_text = NULL;

bool stack_errors = false;
bool stack_print_usage = false;

void print_error(struct vexillum_error error);

void eh_set_program_name(char* name) {
    if(name == NULL) return;

    char* name_start = strrchr(name, '\\');

    if(name_start != NULL) {
        program_name = &name_start[1];
    } else {
        program_name = name;
    }
}

void eh_enable_usage_message(const bool enabled, char* description, char* argument_text) {
    print_usage_enabled = enabled;

    if(!enabled) {
        program_description = NULL;
        program_arguments_text = NULL;
    } else {
        program_description = description;
        program_arguments_text = argument_text;
    }
}

void print_error(const struct vexillum_error error) {
    // TODO: support printing detailed errors (like: option e is not recognised)
    fprintf(stderr, "ERROR: %s\n", eh_get_error_string(error));
}

void eh_print_usage() {
    int amount_of_flags = fh_amount_of_flags();

    char* flagString = NULL;

    if(amount_of_flags != 0) {
        flagString = malloc(sizeof(char) * (amount_of_flags + 1));

        if(flagString == NULL) {
            amount_of_flags = 0;
        } else {
            flagString[amount_of_flags] = '\0';

            for(int i = 0; i < amount_of_flags; i++) {
                flagString[i] = *(char*) ll_get_list_element(fh_short_flags, i);
            }
        }
    }

    printf("Usage: %s%s%s %s\n%s\n", program_name, amount_of_flags != 0 ? " -" : "", amount_of_flags != 0 ? flagString : "", program_arguments_text != NULL ? program_arguments_text : "[ARGUMENTS]...", program_description);

    for(int i = 0; i < amount_of_flags; i++) {
        char* long_flags = ll_get_list_element(fh_long_flags, i);
        char* description = ll_get_list_element(fh_flag_descriptions, i);

        printf(" -%c%c %-20s  %s\n", flagString[i], long_flags != NULL ? ',' : ' ', long_flags != NULL ? long_flags : "", description != NULL ? description : "");
    }

    printf("\n");

    free(flagString);
}

struct vexillum_error eh_create_error(const char error_code) {
    const struct vexillum_error error = {error_code};

    if(!print_usage_enabled) {
        return error;
    }

    const bool should_print_error = PRINT_ERROR_AND_PRINT_USAGE_MATRIX[(int)error_code*2];
    const bool should_print_usage = PRINT_ERROR_AND_PRINT_USAGE_MATRIX[(int)error_code*2+1];

    if(should_print_error) {
        print_error(error);
    }

    if(should_print_error && should_print_usage && !stack_errors) {
        printf("\n");
    }

    if(should_print_usage && !stack_errors) {
        eh_print_usage();
    }

    if(stack_errors && should_print_usage) {
        stack_print_usage = true;
    }

    return error;
}

const char* eh_get_error_string(const struct vexillum_error error) {
    if(error.code >= AMOUNT_OF_ERRORS || error.code < 0) {
        return "Unknown Error";
    }

    return VEXILLUM_ERROR_NAMES[error.code];
}

void eh_start_error_stacking() {
    stack_errors = true;
}

void eh_stop_error_stacking() {
    if(stack_print_usage) {
        printf("\n");
        eh_print_usage();
    }

    stack_errors = false;
    stack_print_usage = false;
}
