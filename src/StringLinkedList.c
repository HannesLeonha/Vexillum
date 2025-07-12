#include "StringLinkedList.h"

#include <stddef.h>
#include <stdlib.h>

struct string_list* create_string_list_element(char* string) {
    struct string_list* list = malloc(sizeof(struct string_list));

    if(list != NULL) {
        list->string = string;
        list->next = NULL;
    }

    return list;
}

int string_list_length(const struct string_list* list) {
    int length = 0;

    do {
        length++;
    } while((list = list->next) != NULL);

    return length;
}

char* get_string_list_element(const struct string_list* list, const int index) {
    int i = 0;

    while((list = list->next) != NULL) {
        if(i == index) {
            return list->string;
        }

        i++;
    }

    return NULL;
}

void delete_string_list_element(struct string_list** list, const int index) {
    if(index == 0) {
        struct string_list* start = *list;
        *list = (*list)->next;
        free(start);
    } else {
        int i = 0;

        while((*list = (*list)->next) != NULL) {
            if(i == index) {
                free(*list);
            }

            i++;
        }
    }

}

void append_string_list_element(struct string_list* list, struct string_list* element) {
    while((list = list->next) != NULL) {}

    list->next = element;
}

void prepend_string_list_element(struct string_list** list, struct string_list* element) {
    struct string_list* start = *list;

    *list = element;

    (*list)->next = start;
}

void free_string_list(struct string_list* list) {
    if(list->next != NULL) {
        free_string_list(list->next);
    }

    free(list);
}
