//
// Created by 86187 on 2024/2/8.
//
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

void myChange(int *p);

int main(){
    /**
     * Definition and access of Pointers
     */
    int i = 5;
    int *i_pointer = &i;
    printf("i_pointer=%d\n", i_pointer);
    printf("*i_pointer=%d\n", *i_pointer);

    /**
     * Passing Pointers
     */
    printf("before i = %d\n", i);
    myChange(i_pointer);
    printf("after i = %d\n", i);

    /**
     * Pointer offset
     * The address is stored in the array,
     * so the ampersand '&' is not needed
     *
     * *p++, the size of '+' is sizeof(type)
     */
    int a[5] = {1, 2, 3, 4, 5};
    int *a_pointer = a;
    for (int j = 0; j < 5; ++j) {
        printf("%3d", *a_pointer + j);
    }
    printf("\n");
    int *a_p = &a[4];
    for (int j = 0; j < 5; ++j) {
        printf("%3d", *a_p - j);
    }
    printf("\n");

    /**
     * malloc dynamic memory requests
     * the return of malloc is void type pointer
     * Release if no longer in use: free()
     */
    int size;
    scanf("%d", &size);
    char *c_p;
    c_p = (char *) malloc(size);
    strcpy(c_p, "malloc success");
    puts(c_p);
    free(c_p);
    return 0;
}

void myChange(int *p) {
    *p = 10;
}
