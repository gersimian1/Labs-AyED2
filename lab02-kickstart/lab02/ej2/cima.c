#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

bool creciente(int x,int y);
bool decreciente(int x,int y);
void array_dump(int a[], int length);

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    int k = 0, j;
    bool b;
    
    while (k < length - 1 && creciente(a[k], a[k + 1]))
    {
        k++;
    }

    j = k;

    while (j < length - 1 && decreciente(a[j], a[j + 1]))
    {
        j++;
    }
    
    b = j == length - 1;

    return b;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {

    int k = 0;

    array_dump(a, length);

    while (k < length - 1 && creciente(a[k], a[k + 1]))
    {
        k++;
    }

    return k;
}

bool creciente(int x,int y) {

    return x < y;
}

bool decreciente(int x, int y) {

    return x > y;
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