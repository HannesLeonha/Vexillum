#include "FlagHandler.h"

#include <stddef.h>

#include "error/ErrorDefinitions.h"
#include "error/ErrorHandler.h"
#include "util/LinkedList.h"

struct linked_list* short_flags = NULL;
struct linked_list* long_flags = NULL;
struct linked_list* flag_descriptions = NULL;
struct linked_list* flag_has_argument = NULL;

struct linked_list* arguments = NULL;

bool compare_short_flags(void* a, void* b) {
    return *(char*) a == *(char*) b;
}

struct vexillum_error fh_register_flag(const char short_format, const char* long_format, const char* flag_description, const bool has_argument) {
    struct linked_list* short_element = ll_create_list_element(&short_format);
    struct linked_list* long_element = ll_create_list_element(long_format);
    struct linked_list* description_element = ll_create_list_element(flag_description);
    struct linked_list* has_argument_element = ll_create_list_element(&has_argument);

    if(short_element == NULL || long_element == NULL || description_element == NULL || has_argument_element == NULL) {
        return eh_create_error(VEXILLUM_ERROR_NOT_ENOUGH_MEMORY);
    }

    if(short_flags != NULL && long_flags != NULL && flag_descriptions != NULL && flag_has_argument != NULL) {
        ll_append_list_element(short_flags, short_element);
        ll_append_list_element(long_flags, long_element);
        ll_append_list_element(flag_descriptions, description_element);
        ll_append_list_element(flag_has_argument, has_argument_element);
    } else {
        short_flags = short_element;
        long_flags = long_element;
        flag_descriptions = description_element;
        flag_has_argument = has_argument_element;
    }

    return eh_create_error(VEXILLUM_NO_ERROR);
}

struct vexillum_error fh_unregister_flag(const char short_format) {
    const int index = ll_get_element_index(short_flags, (const void*) short_format, compare_short_flags);

    if(index == -1) {
        return eh_create_error(VEXILLUM_ERROR_NO_FLAG_FOUND);
    }

    ll_delete_list_element(&short_flags, index);
    ll_delete_list_element(&long_flags, index);
    ll_delete_list_element(&flag_descriptions, index);
    ll_delete_list_element(&flag_has_argument, index);

    return eh_create_error(VEXILLUM_NO_ERROR);
}

bool fh_parse_argument(char* argument) {

}

bool fh_is_flag_set(char flag_short_format) {
    return false;
}

const char* fh_get_flag_argument(char flag_short_format) {
    return "ah";
}

void free_flags() {
    ll_free_list(short_flags);
    ll_free_list(long_flags);
    ll_free_list(flag_descriptions);

    short_flags = NULL;
    long_flags = NULL;
    flag_descriptions = NULL;
}

