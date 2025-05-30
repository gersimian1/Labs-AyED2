#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fixstring tmp;

    fstring_set(tmp, a[i]);
    fstring_swap(a[i], a[j]);
    fstring_swap(a[j], tmp);
}

bool goes_before(fixstring x, fixstring y) {
    
    return fstring_less_eq(x, y);
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

bool array_is_sorted_b(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && fstring_length(array[i-1]) <= fstring_length(array[i])) {
        i++;
    }
    return (i >= length);
}