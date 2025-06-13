#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t *messi_ptr = NULL;

    messi_ptr = malloc(sizeof(data_t));

    strcpy(messi_ptr->name, "Leo Messi");
    messi_ptr->age = 36;
    messi_ptr->height = 169;

    print_data(*messi_ptr);

    printf( "name-size  : %lu bytes\n"
            "age-size   : %lu bytes\n"
            "height-size: %lu bytes\n"
            "data_t-size: %lu bytes\n", sizeof(messi_ptr->name), sizeof(messi_ptr->age), sizeof(messi_ptr->height), sizeof(messi_ptr));
     
    printf( "address name-size  : %p \n"
            "indice age-size    : %p \n"
            "indice height-size : %p \n"
            "address data_t-size: %p \n", (void *) &messi_ptr->name, (void *) &messi_ptr->age, (void *) &messi_ptr->height,(void *) &messi_ptr);
     
    printf( "name  : %lu \n"
            "age   : %lu \n"
            "height: %lu \n",(uintptr_t) messi_ptr->name, (uintptr_t) messi_ptr->age,(uintptr_t) messi_ptr->height);

    free(messi_ptr);

    return EXIT_SUCCESS;
}