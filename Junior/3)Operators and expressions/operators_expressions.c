//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>

int main() {
    /**
     * Arithmetic operators
     * +
     * -
     * *
     * / divide and integer
     * % modulo, can only be used with two int types
     */
    printf("4+5*3-6/4%3 = %d\n", 4+5*3-6/4%3);

    /**
     * Relational operator
     * >,<,==,>=,<=,!=
     * calculate from left to right, false is 0, true is 1
     * for example 3<-5<10 == 1
     *
     * Logical operator
     * &&,||,! and,or,not
     */
    int year;
    scanf("%d", &year);
    if(year%4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("%d is leap year\n", year);
    } else{
        printf("%d is not leap year\n", year);
    }

    /**
     * Assign
     * left value must be a single variable
     * a+=3  ---> a = a + 3
     */
    int a,b=5;
    a = b + 25;
    a /= 6;
    printf("a = %d\n", a);

    /**
     * sizeof is also an operator, not a function
     */
    int i = 0;
    printf("i size is: %d\n", sizeof(i));
    return 0;
}