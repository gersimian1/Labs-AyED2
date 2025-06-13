#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "strfuncs.h"

size_t string_length(const char *str){

    size_t length = 0;

    if (str == NULL)
    {
        return 0;
    }

    while (str[length] != '\0')
    {
        length++; 
    }

    return length;
}

char *string_filter(const char *str, char c){

    int i = 0, j = 0;

    char* str_ptr = NULL;
    str_ptr = malloc(sizeof str);

    while (str[i] != '\0')
    {
        if (str[i] == c) i++;
        else {
            str_ptr[j] = str[i];
            i++;
            j++;
        }
    }
    free(str_ptr);
    
    return str_ptr;
}

bool string_is_symmetric(const char *str){

    size_t length;
    bool res;

    res = true;
    length = string_length(str);

    for (int i = 0; i < (length - i - 1) && res; i++)
    {
        if (str[i] == str[length - i - 1])
        {
            i++;
        } else
        {
            res = false;
        }
    }
    
    return res;
}