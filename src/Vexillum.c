#include "Vexillum.h"

#include <stdbool.h>
#include <stdio.h>

#include "StringLinkedList.h"

// Flag registering
struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument) {
  return;
}

struct vexillum_error unregister_flag(char short_format) {
  return;
}

void clear_flags() {
  struct string_list* list = create_string_list_element(" World");
  struct string_list* element = create_string_list_element("Hello");
  struct string_list* element2 = create_string_list_element("!");

  if(list == NULL || element == NULL || element2 == NULL) {
    fprintf(stderr, "Couldn't allocate memory. dud you got issues maaan");
    return;
  }

  prepend_string_list_element(&list, element);
  append_string_list_element(list, element2);
  delete_string_list_element(&list, -1);

  printf("%s%s%s\n", get_string_list_element(list, 0), get_string_list_element(list, 1), get_string_list_element(list, 2));
  printf("Length: %d", string_list_length(list));

  free_string_list(list);
}

// Parse
struct vexillum_error parse_arguments(int argc, char **argv) {
  return;
}

// Argument and flag querying
int argument_amount() {
  return;
}

const char* get_argument(int argument_number) {
  return;
}

bool is_flag_set(char flag_short_format) {
  return;
}

const char* get_flag_argument(char flag_short_format) {
  return;
}

// Error Handling
const char* VEXILLUM_ERROR_NAMES[] = {
  "Flag not found",
  "Flag got eaten"
};

void enable_usage_message_on_parse_error(char* program_name, char* program_description) {

}

void enable_error_code_on_parse_error() {

}

const char* get_error_string(const struct vexillum_error error) {
  if(error.code >= sizeof(VEXILLUM_ERROR_NAMES)/sizeof(VEXILLUM_ERROR_NAMES[0])) {
    return "Unknown Error";
  }

  return VEXILLUM_ERROR_NAMES[error.code];
}

// Uninitialize library
void free_vexillum() {

}
