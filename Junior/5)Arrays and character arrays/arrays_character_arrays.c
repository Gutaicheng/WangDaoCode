//
// Created by GuTaicheng on 2024/2/7.
//
#include <stdio.h>

void print(int a[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {
    /**
     * array
     * type name[size]
     * Defining the array size requires the use of constants, not variables
     */
    int a[5] = {1, 2, 3, 4, 5};

    /**
     * Access out of bounds
     * Access out of bounds maybe will result in data disorder
     */
    int j = 20;
    int i = 10;
    a[5] = 6;
    a[6] = 7;
    printf("i = %d\n", i);

    /**
     * Transfer array
     * A function that takes an array : function_name (int a[])
     * The number in [] does not pass the array size
     * use function to transfer array, just write function_name(a)
     * if write function_name (a[i]), it just transfer one number not array
     *
     * you can use 'sizeof(a)/sizeof(int)' to get the size of array,
     * but can't use in function, because the array is passed by a pointer, the size of pointer is 8
     */
    print (a, sizeof (a) / sizeof (int));

    /**
     * Character array initialization and output
     * The array size at definition should be one more than the actual number of characters,
     * because the end character '\n' is to be saved
     */
    char b[6] = "hello";
    printf("%s\n", b);

    /**
     * Character array input and output
     * input: gets(c)
     * output: puts(c)
     */
    char c[10];
    gets(c);
    puts(c);
    return 0;
}