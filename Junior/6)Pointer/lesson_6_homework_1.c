//
// Created by GuTaicheng on 2024/2/8.
//
#include <stdio.h>

void change(int *p);

int main() {
    int i;
    scanf("%d", &i);
    int *i_p = &i;
    change(i_p);
    printf("%d", i);
    return 0;
}

void change(int *p)
{
    *p = *p /2;
}