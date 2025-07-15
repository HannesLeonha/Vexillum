#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H

struct vexillum_error ah_add_argument(const char* argument);
int ah_argument_length();
char* ah_get_argument(int index);
void ah_free_arguments();

#endif //ARGUMENTHANDLER_H
