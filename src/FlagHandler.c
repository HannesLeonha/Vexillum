#include "FlagHandler.h"

#include <stdlib.h>
#include <string.h>

#include "error/ErrorDefinitions.h"
#include "error/ErrorHandler.h"
#include "util/LinkedList.h"

struct linked_list* fh_short_flags = NULL;
struct linked_list* fh_long_flags = NULL;
struct linked_list* fh_flag_descriptions = NULL;
struct linked_list* fh_flag_has_argument = NULL;

struct linked_list* fh_is_flag_set_list = NULL;
struct linked_list* fh_flag_argument_list = NULL;

bool compare_short_flags(const void* a, const void* b) {
    return *(char*) a == *(char*) b;
}

bool compare_long_flags(const void* a, const void* b) {
    return strcmp(a, b) == 0;
}

struct vexillum_error fh_register_flag(const char short_format, const char* long_format, const char* flag_description, const bool has_argument) {
    if(fh_short_flags != NULL) {
        const int index = ll_get_element_index(fh_short_flags, &short_format, compare_short_flags);

        if(index != -1) {
            return eh_create_error(VEXILLUM_ERROR_FLAG_ALREADY_EXISTS);
        }
    }

    char* short_format_allocated = malloc(sizeof(char));
    bool* has_argument_allocated = malloc(sizeof(bool));

    if(short_format_allocated == NULL || has_argument_allocated == NULL) {
        return eh_create_error(VEXILLUM_ERROR_NOT_ENOUGH_MEMORY);
    }

    *short_format_allocated = short_format;
    *has_argument_allocated = has_argument;

    struct linked_list* short_element = ll_create_list_element(short_format_allocated);
    struct linked_list* long_element = ll_create_list_element(long_format);
    struct linked_list* description_element = ll_create_list_element(flag_description);
    struct linked_list* has_argument_element = ll_create_list_element(has_argument_allocated);
    struct linked_list* is_flag_set_element = ll_create_list_element(NULL);
    struct linked_list* flag_argument_element = ll_create_list_element(NULL);

    if(short_element == NULL || long_element == NULL || description_element == NULL || has_argument_element == NULL) {
        return eh_create_error(VEXILLUM_ERROR_NOT_ENOUGH_MEMORY);
    }

    if(fh_short_flags != NULL && fh_long_flags != NULL && fh_flag_descriptions != NULL && fh_flag_has_argument != NULL) {
        ll_append_list_element(fh_short_flags, short_element);
        ll_append_list_element(fh_long_flags, long_element);
        ll_append_list_element(fh_flag_descriptions, description_element);
        ll_append_list_element(fh_flag_has_argument, has_argument_element);
        ll_append_list_element(fh_is_flag_set_list, is_flag_set_element);
        ll_append_list_element(fh_flag_argument_list, flag_argument_element);
    } else {
        fh_short_flags = short_element;
        fh_long_flags = long_element;
        fh_flag_descriptions = description_element;
        fh_flag_has_argument = has_argument_element;
        fh_is_flag_set_list = is_flag_set_element;
        fh_flag_argument_list = flag_argument_element;
    }

    return eh_create_error(VEXILLUM_NO_ERROR);
}

struct vexillum_error fh_unregister_flag(const char short_format) {
    if(fh_short_flags == NULL) return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_REGISTERED);

    const int index = ll_get_element_index(fh_short_flags, &short_format, compare_short_flags);

    if(index == -1) {
        return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_REGISTERED);
    }

    ll_delete_list_element(&fh_short_flags, index);
    ll_delete_list_element(&fh_long_flags, index);
    ll_delete_list_element(&fh_flag_descriptions, index);
    ll_delete_list_element(&fh_flag_has_argument, index);
    ll_delete_list_element(&fh_is_flag_set_list, index);
    ll_delete_list_element(&fh_flag_argument_list, index);

    return eh_create_error(VEXILLUM_NO_ERROR);
}

struct vexillum_error fh_parse_argument(const char* argument, char** argument_belongs_to_flag) {
    // Parse arguments which belong to flags
    if(argument[0] != '-') {
        if(*argument_belongs_to_flag == NULL || fh_short_flags == NULL) return eh_create_error(VEXILLUM_NO_ERROR);

        const int index = ll_get_element_index(fh_short_flags, *argument_belongs_to_flag, compare_short_flags);

        if(index == -1) {
            return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_REGISTERED);
        }

        ll_set_list_element(fh_flag_argument_list, index, (void*) argument);

        *argument_belongs_to_flag = NULL;
    }

    if(argument[1] != '-') { // parse short flags
        if(fh_short_flags == NULL) return eh_create_error(VEXILLUM_NO_ERROR);

        for(int i = 1; i < strlen(argument); i++) {
            const int index = ll_get_element_index(fh_short_flags, &argument[i], compare_short_flags);

            if(index == -1) {
                return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_SUPPORTED);
            }

            if(strlen(argument) == 2 && ll_get_list_element(fh_flag_has_argument, index) != NULL) {
                *argument_belongs_to_flag = (char*) &argument[1];
            }

            ll_set_list_element(fh_is_flag_set_list, index, &fh_is_flag_set_list);
        }
    } else { // parse long flags
        if(fh_short_flags == NULL) return eh_create_error(VEXILLUM_NO_ERROR);

        const int index = ll_get_element_index(fh_long_flags, argument, compare_long_flags);

        if(index == -1) {
            return eh_create_error(VEXILLUM_ERROR_FLAG_NOT_SUPPORTED);
        }

        if(ll_get_list_element(fh_flag_has_argument, index) != NULL) {
            *argument_belongs_to_flag = ll_get_list_element(fh_short_flags, index);
        }

        ll_set_list_element(fh_is_flag_set_list, index, &fh_is_flag_set_list);
    }

    return eh_create_error(VEXILLUM_NO_ERROR);
}

int fh_amount_of_flags() {
    if(fh_short_flags == NULL) return 0;

    return ll_list_length(fh_short_flags);
}

bool fh_is_flag_set(const char flag_short_format) {
    if(fh_short_flags == NULL) return false;

    const int index = ll_get_element_index(fh_short_flags, &flag_short_format, compare_short_flags);

    if(index == -1) {
        return false;
    }

    return ll_get_list_element(fh_is_flag_set_list, index) != NULL;
}

const char* fh_get_flag_argument(const char flag_short_format) {
    if(fh_short_flags == NULL) return NULL;

    const int index = ll_get_element_index(fh_short_flags, &flag_short_format, compare_short_flags);

    if(index == -1) {
        return NULL;
    }

    return (char*) ll_get_list_element(fh_flag_argument_list, index);
}

void fh_reset_set_flags() {
    if(fh_short_flags == NULL) return;

    const int length = ll_list_length(fh_short_flags);

    for(int i = 0; i < length; i++) {
        ll_set_list_element(fh_is_flag_set_list, i, NULL);
        ll_set_list_element(fh_flag_argument_list, i, NULL);
    }
}

void fh_free_flags() {
    ll_free_list(fh_short_flags);
    ll_free_list(fh_long_flags);
    ll_free_list(fh_flag_descriptions);
    ll_free_list(fh_flag_has_argument);
    ll_free_list(fh_is_flag_set_list);
    ll_free_list(fh_flag_argument_list);

    fh_short_flags = NULL;
    fh_long_flags = NULL;
    fh_flag_descriptions = NULL;
    fh_flag_has_argument = NULL;
    fh_is_flag_set_list = NULL;
    fh_flag_argument_list = NULL;
}
