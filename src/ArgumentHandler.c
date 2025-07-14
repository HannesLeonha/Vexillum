#include "ArgumentHandler.h"

#include <stddef.h>

#include "ErrorHandler.h"
#include "StringLinkedList.h"

struct string_list* argument_list = NULL;

struct vexillum_error add_argument(const char* argument) {
    struct string_list* new_element = create_string_list_element(argument);

    if(new_element == NULL) {
        return create_error(VEXILLUM_ERROR_FLAG_NOT_FOUND, false);
    }

    if(argument_list == NULL) {
        argument_list = new_element;
    } else {
        append_string_list_element(argument_list, new_element);
    }

    return create_error(VEXILLUM_NO_ERROR, false);
}

int argument_length() {
    return string_list_length(argument_list);
}

char* get_argument_from_list(const int index) {
    return get_string_list_element(argument_list, index);
}

void free_arguments() {
    free_string_list(argument_list);
    argument_list = NULL;
}

