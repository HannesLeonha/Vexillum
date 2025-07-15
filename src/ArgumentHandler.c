#include "ArgumentHandler.h"

#include <stddef.h>

#include "ErrorHandler.h"
#include "StringLinkedList.h"

struct string_list* argument_list = NULL;

struct vexillum_error ah_add_argument(const char* argument) {
    struct string_list* new_element = sll_create_string_list_element(argument);

    if(new_element == NULL) {
        return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_FOUND, false);
    }

    if(argument_list == NULL) {
        argument_list = new_element;
    } else {
        sll_append_string_list_element(argument_list, new_element);
    }

    return eh_create_error(VEXILLUM_NO_ERROR, false);
}

int ah_argument_length() {
    return sll_string_list_length(argument_list);
}

char* ah_get_argument(const int index) {
    return sll_get_string_list_element(argument_list, index);
}

void ah_free_arguments() {
    sll_free_string_list(argument_list);
    argument_list = NULL;
}

