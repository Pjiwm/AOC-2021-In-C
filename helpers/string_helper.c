#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split (const char *str, char delim, char ***token_arr)
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *) str;

    while (*p != '\0') if (*p++ == delim) count += 1;
    t = tklen = calloc (count, sizeof (int));
    for (p = (char *) str; *p != '\0'; p++) *p == delim ? *t++ : (*t)++;
    *token_arr = arr = malloc (count * sizeof (char *));
    t = tklen;
    p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
    while (*str != '\0')
    {
        if (*str == delim)
        {
            p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
            str++;
        }
        else *p++ = *str++;
    }
    free (tklen);
    return count;
}
/*
    char** tokens;
    char delim = ',';
    int count, i;
    const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";

    count = split(str, delim, &tokens);
    for (i = 0; i < count; i++) printf("%s\n", tokens[i]);

    --freeing tokens-- 
    for (i = 0; i < count; i++) free(tokens[i]);
    free(tokens);
*/