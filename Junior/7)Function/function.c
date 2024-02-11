//
// Created by 86187 on 2024/2/8.
//
#include <stdio.h>

/**
 * Functions must be declared first
 *
 * return_type function_name (argument_type argument_name, ....)
 */
int n_factorial(int n);

int main() {
    printf("%d", n_factorial(5));
    return 0;
}

int n_factorial(int n) {
    if (n == 1)
    {
        return 1;
    }
    return n * n_factorial(n - 1);
}