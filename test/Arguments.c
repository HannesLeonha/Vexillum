#include <stdio.h>
#include <string.h>

#include "../src/Vexillum.h"

int main(int argc, char **argv) {
    parse_arguments(argc, argv);

    if(argument_amount() != 2) {
        fprintf(stderr, "FAILED: Wrong amount of arguments (expected: 2; got: %d)\n", argument_amount());
        return 1;
    }
    printf("PASSED: Correct amount of arguments\n");

    if(strcmp(get_argument(0), "loose argument") != 0) {
        fprintf(stderr, "FAILED: First argument is wrong (expected: 'loose argument'; found: '%s')\n", get_argument(0));
        return 1;
    }
    printf("PASSED: First argument is correct\n");

    if(strcmp(get_argument(1), "flag argument") != 0) {
        fprintf(stderr, "FAILED: Second argument is wrong (expected: 'flag argument'; found: '%s')\n", get_argument(1));
        return 1;
    }
    printf("PASSED: Second argument is correct\n");

    return 0;
}
