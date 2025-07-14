#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H

struct vexillum_error add_argument(const char* argument);
int argument_length();
char* get_argument_from_list(int index);
void free_arguments();

#endif //ARGUMENTHANDLER_H
