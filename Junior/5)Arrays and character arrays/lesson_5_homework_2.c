//
// Created by GuTaicheng on 2024/2/8.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100]={0};//must sure array have something
    char str2[100]={0};
    gets(str1);
    int strLength = strlen(str1);
    int i, j;
    for (i = strLength - 1, j = 0; i >= 0 ; i--, j++) {
        str2[j] = str1[i];
    }
    int result = strcmp(str1, str2);
    if (result == 0)
    {
        printf("0");
    } else {
        if (result > 0)
            printf("1");
        else
            printf("-1");
    }
    return 0;
}