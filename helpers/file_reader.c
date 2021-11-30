#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_to_array(char* file_name, char* result[])
{
    FILE* fPointer = fopen(file_name, "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int index = 0;

    while ((read = getline(&line, &len, fPointer)) != -1)
    {
        result[index] = strdup(line);
        index++;
    }

    fclose(fPointer);
    if (line)
    {
        free(line);
    }
}

void file_to_long_long_int_array(char* file_name, long long int result[]) {
    FILE* fPointer = fopen(file_name, "r");
    char* line = NULL;
    size_t len = 0;
    size_t read;

    int index = 0;

    while ((read = getline(&line, &len, fPointer)) != -1)
    {
        result[index] = atoll(strdup(line));
        index++;
    }

    fclose(fPointer);
    if (line)
    {
        free(line);
    }
}

void file_to_int_array(char* file_name, int result[]) {
    FILE* fPointer = fopen(file_name, "r");
    char* line = NULL;
    size_t len = 0;
    size_t read;

    int index = 0;

    while ((read = getline(&line, &len, fPointer)) != -1)
    {
        result[index] = atoi(strdup(line));
        index++;
    }

    fclose(fPointer);
    if (line)
    {
        free(line);
    }
}