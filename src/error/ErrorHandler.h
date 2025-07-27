#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>

#include "ErrorDefinitions.h"

void eh_set_program_name(char* name);
void eh_enable_usage_message(bool enabled, char* description, char* argument_text);
struct vexillum_error eh_create_error(char error_code);
const char* eh_get_error_string(struct vexillum_error error);
void eh_print_usage();

void eh_start_error_stacking();
void eh_stop_error_stacking();

#endif //ERRORHANDLER_H
