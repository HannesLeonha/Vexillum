#include "Vexillum.h"

#include <stdbool.h>

void enable_usage_message_on_parse_error(char* program_name, char* program_description) {
  return;
}

void enable_error_code_on_parse_error() {

}


struct vexillum_error_code register_flag(char short_format, char* long_format, char* flag_description, bool has_argument) {
  return;
}

struct vexillum_error_code unregister_flag(char short_format) {
  return;
}

void clear_flags() {
  return;
}


struct vexillum_error_code parse_arguments(int argc, char **argv) {
  return;
}


int argument_amount() {
  return;
}

char* get_argument(int argument_number) {
  return;
}

bool is_flag_set() {
  return;
}

char* get_flag_argument() {
  return;
}


char* get_error_string(struct vexillum_error_code error_code) {
  return;
}
