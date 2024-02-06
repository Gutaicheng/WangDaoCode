//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    if(year%4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("yes");
    } else{
        printf("no");
    }
    return 0;
}