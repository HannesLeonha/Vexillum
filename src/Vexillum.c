#include "Vexillum.h"

#include <stdbool.h>
#include <stdio.h>

#include "ArgumentHandler.h"
#include "ErrorHandler.h"
#include "StringLinkedList.h"

// Flag registering
struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument) {
    return;
}

struct vexillum_error unregister_flag(char short_format) {
    return;
}

void clear_flags() {
    struct string_list* list = create_string_list_element(" World");
    struct string_list* element = create_string_list_element("Hello");
    struct string_list* element2 = create_string_list_element("!");

    if(list == NULL || element == NULL || element2 == NULL) {
        fprintf(stderr, "Couldn't allocate memory. dud you got issues maaan");
        return;
    }

    prepend_string_list_element(&list, element);
    append_string_list_element(list, element2);
    delete_string_list_element(&list, 1);

    printf("%s%s%s\n", get_string_list_element(list, 0), get_string_list_element(list, 1), get_string_list_element(list, 2));
    printf("Length: %d", string_list_length(list));

    free_string_list(list);
}

// Parse
struct vexillum_error parse_arguments(int argc, char **argv) {
    free_arguments();
    if(argc >= 1) set_program_name_in_usage(argv[0]);

    // add_argument();
}

// Argument and flag querying
int argument_amount() {
    return argument_length();
}

const char* get_argument(const int argument_number) {
    return get_argument_from_list(argument_number);
}

bool is_flag_set(char flag_short_format) {
    return;
}

const char* get_flag_argument(char flag_short_format) {
    return;
}

// Error Handling
void print_usage_message_on_parse_error(bool enabled, char* program_description) {
    enable_usage_message(enabled, program_description);
}

const char* get_error_string(const struct vexillum_error error) {
    return get_error_string_from_struct(error);
}

// Uninitialize library
void free_vexillum() {
    free_arguments();
}
