#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;

    array_dump(a, der);

    while (goes_before(i, j))
    {
        if (goes_before(a[i], a[ppiv]))
        {
            i = i + 1;
        } 
        else if (goes_before(a[ppiv], a[j]))
        {
           j = j - 1;     
        }
        else if (a[i] > a[ppiv] && a[j] < a[ppiv])
        {
            swap(a, i, j);
            i = i + 1;
            j = j - 1; 
        }
    }

    swap(a, ppiv, j);

    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;

    if (der > izq)
    {
        ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0) ? 0 : ppiv-1);
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}