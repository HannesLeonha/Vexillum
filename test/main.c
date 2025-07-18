#include <stdio.h>
#include "Vexillum.h"

void setup_flags() {
    print_usage_message_on_parse_error(true, "Tests the vexillum library");

    register_flag('d', "--drive", "Determines which drive the program operates on", true);
    register_flag('l', "--length", "Operates on the data lengthwise rather than widthwise", false);
    register_flag('y', "--why-are-you-doing-this-to-me", "Asks the important question of why", false);
}

int main(int argc, char **argv) {
    setup_flags();
    parse_arguments(argc, argv);

    printf("Amount of arguments: %d\n", argument_amount());
    printf("Argument 1: %s\n", get_argument(0));
    printf("Flag d: %s\n", is_flag_set('d') ? "Yes" : "No");
    printf("Flag d argument: %s\n", get_flag_argument('d'));
    printf("Flag l: %s\n", is_flag_set('l') ? "Yes" : "No");
    printf("Flag y: %s\n", is_flag_set('y') ? "Yes" : "No");

    return 0;
}
