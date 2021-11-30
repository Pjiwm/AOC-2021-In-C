#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/file_reader.h"

void day7() {
    const size_t LENGTH = 1;
    char* input[LENGTH];
    file_to_array("inputs/day1.txt", input);
    for(size_t i = 0; i < LENGTH; i++) {
        printf("%s\n", input[i]);
    }
}