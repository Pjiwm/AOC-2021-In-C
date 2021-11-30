#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, size_t LENGTH) {
    _Bool is_sorted = 0;
    while (!is_sorted) {
        is_sorted = 1;
        for (size_t i = 0; i < LENGTH-1; i++) {
            if (arr[i] > arr[i + 1]) {
                size_t temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                is_sorted = 0;
            }
        }
    }
}

void size_t_bubble_sort(size_t* arr, size_t LENGTH) {
    _Bool is_sorted = 0;
    while (!is_sorted) {
        is_sorted = 1;
        for (size_t i = 0; i < LENGTH; i++) {
            if (arr[i] > arr[i + 1]) {
                size_t temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                is_sorted = 0;
            }
        }
    }
}