//
// Created by GuTaicheng on 2024/2/8.
//Selection and looping
#include <stdio.h>

int main() {
    int n, a[100], count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &a[i]);
        if (a[i] == 2) count++;
    }
    printf("%d", count);
    return 0;
}