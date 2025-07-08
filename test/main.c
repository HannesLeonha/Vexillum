#include <stdio.h>
#include "library.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Test failed");
        return 1;
    }

    printf("Success: %s", argv[1]);
    hello();

    return 0;
}
