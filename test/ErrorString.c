#include <stdio.h>
#include <string.h>
#include "Vexillum.h"

int main() {
    struct vexillum_error err = {0};
    if(strcmp(get_error_string(err), "Flag not found") != 0) {
        fprintf(stderr, "FAILED: First error string is wrong\n");
        return 1;
    }
    printf("PASSED: First error string\n");

    err.code = 2;
    if(strcmp(get_error_string(err), "Unknown Error") != 0) {
        fprintf(stderr, "FAILED: Error string on boundary is unexpected\n");
        return 1;
    }
    printf("PASSED: Error string on boundary is unknown\n");

    err.code = 255;
    if(strcmp(get_error_string(err), "Unknown Error") != 0) {
        fprintf(stderr, "FAILED: Error string outside of bounds is unexpected\n");
        return 1;
    }
    printf("PASSED: Error string outside of bounds is unknown\n");

    return 0;
}