#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);
void array_dump(int a[], int length);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    int izq = 0, der = length - 1, ppiv;

    array_dump(a, length);
    fprintf(stdout, "%d\n", k);
    fprintf(stdout, "%d\n", a[k]);

    ppiv = partition(a, izq, der);

    array_dump(a, length);
    fprintf(stdout, "%d\n", a[ppiv]);
    fprintf(stdout, "%d\n", a[k]);

    while (ppiv != k)
    {
        if (ppiv < k)
        {
            izq = ppiv + 1;
        }
        else
        {
            der = ppiv - 1;
        }
        
        ppiv = partition(a, izq, der);

        array_dump(a, length);
        fprintf(stdout, "%d\n", a[ppiv]);
        fprintf(stdout, "%d\n", a[k]);
        
    }
    
    return a[k];
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void array_dump(int a[], int length) {
    fprintf(stdout, "[");
    for (int i = 0; i < length; i++)
    {
        fprintf(stdout, "%d", a[i]);
        
        if (i < length-1)
        {
            fprintf(stdout, ",");
        }
    }
    fprintf(stdout, "]\n");
}