#include "ArgumentHandler.h"

#include <stddef.h>

#include "error/ErrorDefinitions.h"
#include "error/ErrorHandler.h"
#include "util/LinkedList.h"

struct linked_list* argument_list = NULL;

struct vexillum_error ah_add_argument(const char* argument) {
    struct linked_list* new_element = ll_create_list_element(argument);

    if(new_element == NULL) {
        return eh_create_error(VEXILLUM_ERROR_NOT_ENOUGH_MEMORY);
    }

    if(argument_list == NULL) {
        argument_list = new_element;
    } else {
        ll_append_list_element(argument_list, new_element);
    }

    return eh_create_error(VEXILLUM_NO_ERROR);
}

int ah_argument_length() {
    return ll_list_length(argument_list);
}

char* ah_get_argument(const int index) {
    return ll_get_list_element(argument_list, index);
}

void ah_free_arguments() {
    ll_free_list(argument_list);
    argument_list = NULL;
}
