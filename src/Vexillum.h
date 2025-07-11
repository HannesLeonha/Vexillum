#ifndef VEXILLUM_LIBRARY_H
#define VEXILLUM_LIBRARY_H

#include <stdbool.h>

#define SOME_ERROR 0

struct vexillum_error {
    char code;
};

void enable_usage_message_on_parse_error(char* program_name, char* program_description);
void enable_error_code_on_parse_error();

struct vexillum_error register_flag(char short_format, char* long_format, char* flag_description, bool has_argument);
struct vexillum_error unregister_flag(char short_format);
void clear_flags();

struct vexillum_error parse_arguments(int argc, char **argv);

int argument_amount();
const char* get_argument(int argument_number);
bool is_flag_set();
const char* get_flag_argument();

const char* get_error_string(struct vexillum_error error);

#endif //VEXILLUM_LIBRARY_H