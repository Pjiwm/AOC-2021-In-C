#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/file_reader.h"

void day1() {
    printf("day1:\n");

    const size_t LENGTH = 2000;
    int input[LENGTH];
    size_t increment_count = 0;
    file_to_int_array("inputs/day1.txt", input);
    for(size_t i = 1; i < LENGTH; i++) {
        // printf("%s", input[i]);
        if(input[i] > input[i-1]) {
            increment_count++;
        }
    }
    printf("%ld\n", increment_count);

    size_t increment_of_three = 0;
    for(size_t i = 2; i < LENGTH-1; i++) {
        const size_t firstSum = input[i-2] + input[i-1] + input[i];
        const size_t secondSum = input[i-1] + input[i] + input[i+1];
        if(secondSum > firstSum) {
            increment_of_three++;
        }
    }
    printf("%ld\n", increment_of_three);
}