#ifndef FLAGHANDLER_H
#define FLAGHANDLER_H

#include <stdbool.h>
#include <stddef.h>

extern struct linked_list* fh_short_flags = NULL;
extern struct linked_list* fh_long_flags = NULL;
extern struct linked_list* fh_flag_descriptions = NULL;
extern struct linked_list* fh_flag_has_argument = NULL;

struct vexillum_error fh_register_flag(char short_format, const char* long_format, const char* flag_description, bool has_argument);
struct vexillum_error fh_unregister_flag(char short_format);
bool fh_parse_argument(const char* argument);
bool fh_is_flag_set(char flag_short_format);
const char* fh_get_flag_argument(char flag_short_format);
void fh_free_flags();

#endif //FLAGHANDLER_H
