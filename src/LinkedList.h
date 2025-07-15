#ifndef STRINGLINKEDLIST_H
#define STRINGLINKEDLIST_H

struct string_list {
    struct string_list* next;
    void* string;
};

struct string_list* sll_create_string_list_element(const void* element);
int sll_string_list_length(const struct string_list* list);
void* sll_get_string_list_element(const struct string_list* list, int index);
void sll_delete_string_list_element(struct string_list** listPointer, int index);
void sll_append_string_list_element(struct string_list* list, struct string_list* element);
void sll_prepend_string_list_element(struct string_list** list, struct string_list* element);
void sll_free_string_list(struct string_list* list);

#endif //STRINGLINKEDLIST_H
