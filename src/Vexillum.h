#ifndef VEXILLUM_LIBRARY_H
#define VEXILLUM_LIBRARY_H

#include <stdbool.h>

struct vexillum_error_code {
    char code;
};

void enable_usage_message_on_parse_error(char* program_name, char* program_description);
void enable_error_code_on_parse_error();

struct vexillum_error_code register_flag(char short_format, char* long_format, char* flag_description, bool has_argument);
struct vexillum_error_code unregister_flag(char short_format);
void clear_flags();

struct vexillum_error_code parse_arguments(int argc, char **argv);

int argument_amount();
char* get_argument(int argument_number);
bool is_flag_set();
char* get_flag_argument();

char* get_error_string(struct vexillum_error_code error_code);

#endif //VEXILLUM_LIBRARY_H