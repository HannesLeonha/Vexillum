#include "LinkedList.h"

#include <stddef.h>
#include <stdlib.h>

struct linked_list* ll_create_list_element(const void* element) {
    struct linked_list* list = malloc(sizeof(struct linked_list));

    if(list != NULL) {
        list->element = element;
        list->next = NULL;
    }

    return list;
}

int ll_list_length(const struct linked_list* list) {
    int length = 1;

    while(list->next != NULL) {
        list = list->next;
        length++;
    }

    return length;
}

void* ll_get_list_element(const struct linked_list* list, const int index) {
    int i = 0;

    do {
        if(i == index) {
            return list->element;
        }

        i++;
    } while((list = list->next) != NULL);

    return NULL;
}

int ll_get_element_index(const struct linked_list* list, const void* element, _Bool (*compare_function)(const void*, const void*)) {
    int i = 0;

    do {
        if((*compare_function)(list->element, element)) {
            return i;
        }

        i++;
    } while((list = list->next) != NULL);

    return -1;
}

void ll_delete_list_element(struct linked_list** listPointer, const int index) {
    if(index == 0) {
        struct linked_list* start = *listPointer;
        *listPointer = (*listPointer)->next;
        free(start);
    } else {
        int i = 0;
        struct linked_list* lastElement = NULL;
        struct linked_list* element = *listPointer;

        do {
            if(i == index) {
                lastElement->next = element->next;
                free(element);
                break;
            }

            i++;
            lastElement = element;
        } while((element = element->next) != NULL);
    }
}

void ll_append_list_element(struct linked_list* list, struct linked_list* element) {
    while(list->next != NULL) { list = list->next; }

    list->next = element;
}

void ll_prepend_list_element(struct linked_list** list, struct linked_list* element) {
    struct linked_list* start = *list;

    *list = element;

    (*list)->next = start;
}

void ll_set_list_element(struct linked_list* list, const int index, void* element) {
    int i = 0;

    do {
        if(i == index) {
            list->element = element;
            break;
        }

        i++;
    } while((list = list->next) != NULL);
}

void ll_free_list(struct linked_list* list) {
    if(list == NULL) return;

    if(list->next != NULL) {
        ll_free_list(list->next);
    }

    free(list);
}
