#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/file_reader.h"

void day2() {
    printf("day2:\n");
    const size_t LENGTH = 1000;
    char* input[LENGTH];
    file_to_array("inputs/day2.txt", input);

    // part 1 variables
    int forward = 0;
    int depth = 0;
    // part 2 variables
    int aim = 0;
    int new_depth = 0;

    for (size_t i = 0; i < LENGTH; i++) {
        int increment = input[i][strlen(input[i]) - 2] - '0';
        if (input[i][0] == 'f') {
            // part 1
            forward += increment;
            // part 2
            new_depth += aim * increment;
        }
        else if (input[i][0] == 'd') {
            // part 1
            depth += increment;
            // part 2
            aim += increment;
        }
        else if (input[i][0] == 'u') {
            // part 1
            depth -= increment;
            // part 2
            aim -= increment;
        }
        else {
            printf("something went wrong\n");
        }
    }
    
    printf("%d\n", forward * depth);
    printf("%d\n", forward * new_depth);
}