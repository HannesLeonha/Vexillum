#include "Vexillum.h"

#include <stdbool.h>
#include <stdio.h>

#include "ArgumentHandler.h"
#include "error/ErrorHandler.h"
#include "FlagHandler.h"
#include "util/LinkedList.h"

// Flag registering
struct vexillum_error register_flag(const char short_format, char* long_format, char* flag_description, const bool has_argument) {
    return fh_register_flag(short_format, long_format, flag_description, has_argument);
}

struct vexillum_error unregister_flag(const char short_format) {
    return fh_unregister_flag(short_format);
}

void clear_flags() {
    fh_free_flags();
}

// Parse
struct vexillum_error parse_arguments(const int argc, char **argv) {
    ah_free_arguments();
    if(argc >= 1) eh_set_program_name(argv[0]);

    for(int i = 0; i < argc; i++) {
        if(fh_parse_argument(argv[i])) {

        }
        // add_argument();
    }
}

// Argument and flag querying
int argument_amount() {
    return ah_argument_length();
}

const char* get_argument(const int argument_number) {
    return ah_get_argument(argument_number);
}

bool is_flag_set(const char flag_short_format) {
    return fh_is_flag_set(flag_short_format);
}

const char* get_flag_argument(const char flag_short_format) {
    return fh_get_flag_argument(flag_short_format);
}

// Error Handling
void print_usage_message_on_parse_error(const bool enabled, char* program_description) {
    eh_enable_usage_message(enabled, program_description);
}

const char* get_error_string(const struct vexillum_error error) {
    return eh_get_error_string(error);
}

// Uninitialize library
void free_vexillum() {
    ah_free_arguments();
    fh_free_flags();
}
