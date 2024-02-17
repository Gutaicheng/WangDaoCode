//
// Created by GuTaicheng on 2024/2/17.
//
#include <stdio.h>
#include <stdlib.h>
void get_str(char *&p)
{
    int size = 100;
    p = (char *)malloc (size);
    fgets(p, size, stdin);
}

int main() {
    char *p;
    get_str(p);
    puts(p);
    return 0;
}
