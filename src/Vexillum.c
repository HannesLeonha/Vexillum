#include "Vexillum.h"

#include <stdbool.h>
#include <stdio.h>

#include "ArgumentHandler.h"
#include "ErrorHandler.h"
#include "LinkedList.h"

// Flag registering
struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument) {
    return;
}

struct vexillum_error unregister_flag(char short_format) {
    return;
}

void clear_flags() {
    struct string_list* list = sll_create_string_list_element(" World");
    struct string_list* element = sll_create_string_list_element("Hello");
    struct string_list* element2 = sll_create_string_list_element("!");

    if(list == NULL || element == NULL || element2 == NULL) {
        fprintf(stderr, "Couldn't allocate memory. dud you got issues maaan");
        return;
    }

    sll_prepend_string_list_element(&list, element);
    sll_append_string_list_element(list, element2);
    sll_delete_string_list_element(&list, 1);

    printf("%s%s%s\n", sll_get_string_list_element(list, 0), sll_get_string_list_element(list, 1), sll_get_string_list_element(list, 2));
    printf("Length: %d", sll_string_list_length(list));

    sll_free_string_list(list);
}

// Parse
struct vexillum_error parse_arguments(int argc, char **argv) {
    ah_free_arguments();
    if(argc >= 1) eh_set_program_name(argv[0]);

    // add_argument();
}

// Argument and flag querying
int argument_amount() {
    return ah_argument_length();
}

const char* get_argument(const int argument_number) {
    return ah_get_argument(argument_number);
}

bool is_flag_set(char flag_short_format) {
    return;
}

const char* get_flag_argument(char flag_short_format) {
    return;
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
}
