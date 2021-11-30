#include <stdio.h>
#include <stdlib.h>
void copy_str_array(char * arr[], char * dup_arr[], const size_t LENGTH) {
    for(size_t i = 0; i < LENGTH; i++) {
        dup_arr[i] = arr[i];
    }
}