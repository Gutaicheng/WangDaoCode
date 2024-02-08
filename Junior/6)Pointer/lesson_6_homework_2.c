//
// Created by GuTaicheng on 2024/2/8.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);
    char *str, c;
    str = (char *) malloc(size);
    scanf("%c",&c);//Note that scanf("%c",&c) is used between scanf and gets to remove line breaks
    fgets(str, size, stdin);
    puts(str);
    free(str);
    return 0;
}
