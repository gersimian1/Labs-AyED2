#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int length = 0;

    while (s[length] != '\0')
    {
        length++; 
    }

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool res = false;
    int i = 0;

    if (fstring_length(s1) == fstring_length(s2))
    {
        res = true;

        while (s1[i] != '\0' && res)
        {
            if (s1[i] != s2[i])
            {
                res = false;        
            }
            
            i++;
        }
    }
    
    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i = i + 1; 
    }
    
    return s1[i] <= s2[i];
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}
