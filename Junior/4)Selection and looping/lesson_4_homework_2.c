//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>

int main() {
    int n, i=1;
    scanf("%d", &n);
    while (n>0)
    {
        i *= n;
        n--;
    }
    printf("%d", i);
    return 0;
}