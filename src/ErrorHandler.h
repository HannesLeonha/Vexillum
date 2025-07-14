#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "Vexillum.h"

#define VEXILLUM_NO_ERROR (char) 0
#define VEXILLUM_ERROR_FLAG_NOT_FOUND (char) 1

void set_program_name_in_usage(char* name);
void enable_usage_message(bool enabled, char* description);
struct vexillum_error create_error(char error_code, bool print_usage);
const char* get_error_string_from_struct(struct vexillum_error error);

#endif //ERRORHANDLER_H
