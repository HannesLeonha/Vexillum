#include <stdio.h>
#include <string.h>

#include "Vexillum.h"

void setup_flags() {
    print_usage_message_on_parse_error(true, "Tests the vexillum library", NULL);

    register_flag('d', "--drive", "Determines which drive the program operates on", true);
    register_flag('l', "--length", "Operates on the data lengthwise rather than widthwise", false);
    register_flag('y', "--why-are-you-doing-this-to-me", "Asks the important question of why", false);
}

int main(int argc, char **argv) {
    setup_flags();
    struct vexillum_error error = parse_arguments(argc, argv);

    if(error.code != VEXILLUM_ERROR_FLAG_NOT_SUPPORTED) {
        printf("FAILED: Wrong error after parsing arguments (expected: The given flag is not supported by the program; got: %s)\n", get_error_string(error));
        return 1;
    }
    printf("PASSED: Correct error after parsing arguments\n");

    if(argument_amount() != 1) {
        fprintf(stderr, "FAILED: Wrong amount of arguments (expected: 1; got: %d)\n", argument_amount());
        return 1;
    }
    printf("PASSED: Correct amount of arguments\n");

    if(strcmp(get_argument(0), "loose argument") != 0) {
        fprintf(stderr, "FAILED: Argument is wrong (expected: 'loose argument'; found: '%s')\n", get_argument(0));
        return 1;
    }
    printf("PASSED: Argument is correct\n");

    if(!is_flag_set('d')) {
        fprintf(stderr, "FAILED: Flag of id 'd' is not set\n");
        return 1;
    }
    printf("PASSED: Flag of id 'd' is set\n");

    if(strcmp(get_flag_argument('d'), "flag argument") != 0) {
        fprintf(stderr, "FAILED: Argument of flag with id 'd' is not correct (expected: 'flag argument'; got: %s)\n", get_flag_argument('d'));
        return 1;
    }
    printf("PASSED: Argument of flag with id 'd' is correct\n");

    if(!is_flag_set('l')) {
        fprintf(stderr, "FAILED: Flag of id 'l' is not set\n");
        return 1;
    }
    printf("PASSED: Flag of id 'l' is set\n");

    if(is_flag_set('y')) {
        fprintf(stderr, "FAILED: Flag of id 'y' is set\n");
        return 1;
    }
    printf("PASSED: Flag of id 'y' is not set\n");

    if(is_flag_set('e')) {
        fprintf(stderr, "FAILED: Flag of id 'e' is set even though it has not been registered\n");
        return 1;
    }
    printf("PASSED: Flag of id 'e' is not set\n");

    printf("\nNOTE: The errors bellow should be there\n");

    return 0;
}
