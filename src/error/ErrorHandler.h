#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>

#include "ErrorDefinitions.h"

void eh_set_program_name(char* name);
void eh_enable_usage_message(bool enabled, char* description);
struct vexillum_error eh_create_error(char error_code);
const char* eh_get_error_string(struct vexillum_error error);

#endif //ERRORHANDLER_H
