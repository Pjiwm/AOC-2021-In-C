#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../helpers/file_reader.h"
#include "../helpers/linked_list.h"

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

long part2(char** input, const size_t LENGTH) {
    String_Node* remaining_generator_nums = NULL;
    String_Node* remaining_scrubber_nums = NULL;

    int generator_size = LENGTH;
    int scrubber_size = LENGTH;

    // convert to linked list
    for (size_t i = 0; i < generator_size; i++) {
        str_insert_tail(&remaining_generator_nums, input[i]);
    }

    for (size_t i = 0; i < scrubber_size; i++) {
        str_insert_tail(&remaining_scrubber_nums, input[i]);
    }

    for (size_t i = 0; i < strlen(input[0]) - 2; i++) {

        size_t one_count = 0;
        for (String_Node* curr = remaining_generator_nums; curr != NULL; curr = curr->next) {
            if (curr->value[i] == '1') {
                one_count++;
            }
        }

        size_t zero_count = 0;
        for (String_Node* curr = remaining_scrubber_nums; curr != NULL; curr = curr->next) {
            if (curr->value[i] == '0') {
                zero_count++;
            }
        }
        // for generator
        char generator_filter = '1';
        if (one_count < generator_size / 2) {
            generator_filter = '0';
        }
        // for scrubber  
        char scrubber_filter = '0';
        if (zero_count > scrubber_size / 2) {
            scrubber_filter = '1';
        }

        String_Node* new_generator_input = NULL;
        generator_size = 0;
        for (String_Node* curr = remaining_generator_nums; curr != NULL; curr = curr->next) {
            if (curr->value[i] == generator_filter) {
                str_insert_tail(&new_generator_input, curr->value);
                generator_size++;
            }
        }
        if (generator_size > 1) {
            remaining_generator_nums = new_generator_input;
        }


        String_Node* new_scrubber_input = NULL;
        scrubber_size = 0;
        for (String_Node* curr = remaining_scrubber_nums; curr != NULL; curr = curr->next) {
            if (curr->value[i] == scrubber_filter) {
                str_insert_tail(&new_scrubber_input, curr->value);
                scrubber_size++;
            }
        }
        if (scrubber_size > 1) {
            remaining_scrubber_nums = new_scrubber_input;
        }

    }
    return (long)binary_to_decimal(atol(remaining_generator_nums->value)) * (long)binary_to_decimal(atol(remaining_scrubber_nums->value));
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
    printf("%ld\n", part2(input, LENGTH));
}