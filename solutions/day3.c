#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <math.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"
#include "../helpers/string_helper.h"

long binary_to_decimal(long binary) {
    long decimal = 0, i = 0, remainder;

    while (binary != 0) {
        remainder = binary % 10;
        decimal = decimal + (remainder * pow(2, i));
        binary = binary / 10;
        ++i;
    }
    return decimal;
}

long part2(char** input, const size_t LENGTH, bool filter_majoriy) {
    String_Node* remaining_options = NULL;
    String_Node* filtered_options = NULL;

    int size = LENGTH;
    char* answer = malloc(sizeof(char) * strlen(input[0]));

    for (size_t i = 0; i < size; i++) {
        str_insert_tail(&remaining_options, input[i]);
    }

    for (size_t i = 0; i < strlen(input[0]) - 2; i++) {

        size_t one_count = 0;
        for (String_Node* curr = remaining_options; curr != NULL; curr = curr->next) {
            if (curr->value[i] == '1') {
                one_count++;
            }
        }

        char filter = '1';
        if (one_count < size / 2 && filter_majoriy) {
            filter = '0';
        }

        if (one_count > size / 2 && !filter_majoriy) {
            filter = '0';
        }

        filtered_options = NULL;
        size = 0;
        for (String_Node* curr = remaining_options; curr != NULL; curr = curr->next) {
            if (curr->value[i] == filter) {
                str_insert_tail(&filtered_options, curr->value);
                size++;
            }
        }

        if (size > 1) {
            str_deallocate(&remaining_options);
            remaining_options = filtered_options;
        }
        else {
            answer = remaining_options->value;
            return binary_to_decimal(atol(answer));
        }
    }

    answer = remaining_options->value;
    str_deallocate(&remaining_options);
    return binary_to_decimal(atol(answer));
}

long part1(char** input, const size_t LENGTH) {
    char* gamma_rate = malloc(sizeof(char) * strlen(input[0]));
    for (size_t i = 0; i < strlen(input[0]); i++) {
        size_t one_count = 0;
        for (size_t j = 0; j < LENGTH; j++) {
            if (input[j][i] == '1') {
                one_count++;
            }
        }
        if (one_count > LENGTH / 2) {
            gamma_rate[i] = '1';
        }
        else {
            gamma_rate[i] = '0';
        }
    }
    gamma_rate[strlen(input[0]) - 1] = '\0';

    char* epsilon_rate = malloc(sizeof(char) * strlen(input[0]));
    for (size_t i = 0; i < strlen(gamma_rate); i++) {
        if (gamma_rate[i] == '0') {
            epsilon_rate[i] = '1';
        }
        else {
            epsilon_rate[i] = '0';
        }
    }
    epsilon_rate[strlen(gamma_rate)] = '\0';

    return binary_to_decimal(atol(gamma_rate)) * binary_to_decimal(atol(epsilon_rate));
}

void day3() {
    printf("day3:\n");
    const size_t LENGTH = 1000;
    char* input[LENGTH];
    file_to_array("inputs/day3.txt", input);
    printf("%ld\n", part1(input, LENGTH));
    printf("%ld\n", part2(input, LENGTH, true) * part2(input, LENGTH, false));
}