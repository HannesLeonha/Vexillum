#ifndef VEXILLUM_LIBRARY_H
#define VEXILLUM_LIBRARY_H

#include <stdbool.h>

#include "error/ErrorDefinitions.h"

struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument);
struct vexillum_error unregister_flag(char short_format);
void clear_flags();

struct vexillum_error parse_arguments(int argc, char **argv);

int argument_amount();
const char* get_argument(int argument_number);
bool is_flag_set(char flag_short_format);
const char* get_flag_argument(char flag_short_format);

void print_usage_message_on_parse_error(bool enabled, char* program_description);
const char* get_error_string(struct vexillum_error error);

void free_vexillum();

#endif //VEXILLUM_LIBRARY_H