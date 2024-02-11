//
// Created by GuTaicheng on 2024/2/8.
//
#include <stdio.h>

int step_problem(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", step_problem(n));
    return 0;
}

int step_problem(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    return step_problem(n - 1) + step_problem(n - 2);
}