#include <stdio.h>
#include "Vexillum.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Test failed");
        return 1;
    }

    printf("Success: %s\n", argv[1]);

    const struct vexillum_error err = {2};
    printf("Error: %s", get_error_string(err));

    return 0;
}
