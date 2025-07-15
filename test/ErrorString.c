#include <stdio.h>
#include <string.h>
#include "Vexillum.h"

int main() {
    struct vexillum_error error = {0};
    if(strcmp(get_error_string(error), "No error") != 0) {
        fprintf(stderr, "FAILED: First error string is wrong (got: %s)\n", get_error_string(error));
        return 1;
    }
    printf("PASSED: First error string\n");

    error.code = (char) 2;
    if(strcmp(get_error_string(error), "Unknown Error") != 0) {
        fprintf(stderr, "FAILED: Error string on boundary is unexpected (got: %s)\n", get_error_string(error));
        return 1;
    }
    printf("PASSED: Error string on boundary is unknown\n");

    error.code = (char) 255;
    if(strcmp(get_error_string(error), "Unknown Error") != 0) {
        fprintf(stderr, "FAILED: Error string outside of bounds is unexpected (got: %s)\n", get_error_string(error));
        return 1;
    }
    printf("PASSED: Error string outside of bounds is unknown\n");

    return 0;
}