#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "Vexillum.h"

#define VEXILLUM_NO_ERROR (char) 0
#define VEXILLUM_ERROR_FLAG_NOT_FOUND (char) 1

void eh_set_program_name(char* name);
void eh_enable_usage_message(bool enabled, char* description);
struct vexillum_error eh_create_error(char error_code, bool print_usage);
const char* eh_get_error_string(struct vexillum_error error);

#endif //ERRORHANDLER_H
