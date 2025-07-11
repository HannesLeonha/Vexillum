#include "Vexillum.h"

#include <stdbool.h>

void enable_usage_message_on_parse_error(char* program_name, char* program_description) {

}

void enable_error_code_on_parse_error() {

}


struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument) {
  return;
}

struct vexillum_error unregister_flag(char short_format) {
  return;
}

void clear_flags() {

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

bool is_flag_set() {
  return;
}

const char* get_flag_argument() {
  return;
}

// Error Handling
const char* VEXILLUM_ERROR_NAMES[] = {
  "Flag not found",
  "Flag got eaten"
};

const char* get_error_string(const struct vexillum_error error) {
  if(error.code >= sizeof(VEXILLUM_ERROR_NAMES)/sizeof(VEXILLUM_ERROR_NAMES[0])) {
    return "Unknown Error";
  }

  return VEXILLUM_ERROR_NAMES[error.code];
}
