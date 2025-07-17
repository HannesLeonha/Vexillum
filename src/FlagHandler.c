#include "FlagHandler.h"

#include "error/ErrorDefinitions.h"
#include "error/ErrorHandler.h"
#include "util/LinkedList.h"

struct linked_list* is_flag_set = NULL;
struct linked_list* flag_argument = NULL;

bool compare_short_flags(void* a, void* b) {
    return *(char*) a == *(char*) b;
}

struct vexillum_error fh_register_flag(const char short_format, const char* long_format, const char* flag_description, const bool has_argument) {
    struct linked_list* short_element = ll_create_list_element(&short_format);
    struct linked_list* long_element = ll_create_list_element(long_format);
    struct linked_list* description_element = ll_create_list_element(flag_description);
    struct linked_list* has_argument_element = ll_create_list_element(&has_argument);
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
        ll_append_list_element(is_flag_set, is_flag_set_element);
        ll_append_list_element(flag_argument, flag_argument_element);
    } else {
        fh_short_flags = short_element;
        fh_long_flags = long_element;
        fh_flag_descriptions = description_element;
        fh_flag_has_argument = has_argument_element;
        is_flag_set = is_flag_set_element;
        flag_argument = flag_argument_element;
    }

    return eh_create_error(VEXILLUM_NO_ERROR);
}

struct vexillum_error fh_unregister_flag(const char short_format) {
    const int index = ll_get_element_index(fh_short_flags, (const void*) short_format, compare_short_flags);

    if(index == -1) {
        return eh_create_error(VEXILLUM_ERROR_NO_FLAG_FOUND);
    }

    ll_delete_list_element(&fh_short_flags, index);
    ll_delete_list_element(&fh_long_flags, index);
    ll_delete_list_element(&fh_flag_descriptions, index);
    ll_delete_list_element(&fh_flag_has_argument, index);
    ll_delete_list_element(&is_flag_set, index);
    ll_delete_list_element(&flag_argument, index);

    return eh_create_error(VEXILLUM_NO_ERROR);
}

bool fh_parse_argument(const char* argument) {


    return argument[0] == '-';
}

bool fh_is_flag_set(const char flag_short_format) {
    const int index = ll_get_element_index(fh_short_flags, (const void*) flag_short_format, compare_short_flags);

    if(index == -1) {
        return false;
    }

    return (bool) ll_get_list_element(is_flag_set, index);
}

const char* fh_get_flag_argument(char flag_short_format) {
    const int index = ll_get_element_index(fh_short_flags, (const void*) flag_short_format, compare_short_flags);

    if(index == -1) {
        return NULL;
    }

    return (char*) ll_get_list_element(flag_argument, index);
}

void free_flags() {
    ll_free_list(fh_short_flags);
    ll_free_list(fh_long_flags);
    ll_free_list(fh_flag_descriptions);

    fh_short_flags = NULL;
    fh_long_flags = NULL;
    fh_flag_descriptions = NULL;
}

