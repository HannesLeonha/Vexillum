#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct linked_list {
    struct linked_list* next;
    void* element;
};

struct linked_list* ll_create_list_element(const void* element);
int ll_list_length(const struct linked_list* list);
void* ll_get_list_element(const struct linked_list* list, int index);
int ll_get_element_index(const struct linked_list* list, const void* element, _Bool (*compare_function)(const void*, const void*));
void ll_delete_list_element(struct linked_list** listPointer, int index);
void ll_append_list_element(struct linked_list* list, struct linked_list* element);
void ll_prepend_list_element(struct linked_list** list, struct linked_list* element);
void ll_set_list_element(struct linked_list* list, int index, void* element);
void ll_free_list(struct linked_list* list);

#endif //LINKEDLIST_H
