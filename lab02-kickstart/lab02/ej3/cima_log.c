#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

int cima_log_rec (int a[], int lft, int rgt, int length);
bool es_cima (int a[], int i, int length);
bool cima_der(int a[], int i, int length);
bool cima_izq(int a[], int i, int length);
void array_dump(int a[], int length);

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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
int cima_log(int a[], int length) {

    return cima_log_rec(a, 0, length - 1, length);
}

int cima_log_rec (int a[], int lft, int rgt, int length)
{
    int res;
    int mid = (lft + rgt) / 2;

    array_dump(a, length);

    if (es_cima(a, mid, length))
    {
        res = mid;
    }
    else if (cima_izq(a, mid, length))
    {
        res = cima_log_rec(a, lft, mid - 1, length);
    }   
    else if (cima_der(a, mid, length))
    {
        res = cima_log_rec(a, mid + 1, rgt, length);
    }

    return res;
}

bool es_cima (int a[], int i, int length) 
{
    return (i == 0 || a[i] > a[i - 1]) && (i == length - 1 || a[i] > a[i + 1]);
}

bool cima_der(int a[], int i, int length)
{
    return (i < length - 1 && a[i] < a[i + 1]);
}

bool cima_izq(int a[], int i, int length)
{
    return (i > 0  && a[i] < a[i - 1]);
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