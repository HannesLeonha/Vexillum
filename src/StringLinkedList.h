#ifndef STRINGLINKEDLIST_H
#define STRINGLINKEDLIST_H

struct string_list {
    struct string_list* next;
    char* string;
};

struct string_list* create_string_list_element(char* string);
int string_list_length(const struct string_list* list);
char* get_string_list_element(const struct string_list* list, int index);
void delete_string_list_element(struct string_list** list, int index);
void append_string_list_element(struct string_list* list, char* string);
void prepend_string_list_element(struct string_list** list, char* string);
void free_string_list(struct string_list* list);

#endif //STRINGLINKEDLIST_H
