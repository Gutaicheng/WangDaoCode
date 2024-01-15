//
// Created by GuTaicheng on 2024/1/14.
//
#include <stdio.h>

#define PI 3 + 2

int main() {
    printf("**************************\n");
    /**
     * symbolic constant: PI
     * Equivalent to direct replacement
     * PI * 2 ==> 3 + 2 * 2
     * The output result is 7 instead of 10
     */
    int i = PI * 2;
    printf("i = %d\n", i);
    printf("**************************\n");
    /**
     * float
     * me-n represent m*10^n
     */
    float _float = 3e-3;
    printf("'3e-3' = %f\n", _float);
    printf("**************************\n");

    /**
     * char
     * Define with ''
     * Each character has a corresponding number: ASCII Code
     * For example A ==> 65; a ==> 97
     */
    char _char = 'A';
    printf("A's ASCII Code is %d\n", _char);
    printf("'A' + 32 = %c\n", _char + 32);
    printf("a's ASCII Code is %d\n", 'a');
    printf("**************************\n");

    /**
     * string
     * Define with ""
     */
     char str[15] = "Hello,World!";
    printf("string is %s\n", str);
    printf("**************************\n");

    /**
     * Bytes occupied
     */
    printf("_integer size is: %d\n", sizeof(i));
    printf("_float size is: %d\n", sizeof(_float));
    printf("_char size is: %d\n", sizeof(_char));
    printf("**************************\n");

    /**
     *Type cast
     */
    int a = 5;
    float b = a / 2;
    printf("b = %f\n", b);
    b = (float) i / 2;
    printf("b = %f\n", b);
    printf("**************************\n");

    /**
     * printf
     * %d == int
     * %c == char
     * %f == float
     * %5.2f == occupies 5 characters, keep 2 decimal places
     * %s == char[]
     */
    int age = 21;
    float weight = 65.5;
    char name[5] = "Bob";
    char gender = 'F';
    printf("%s's age is %d, weight is %5.2f, gender is %c\n", name, age, weight, gender);
    printf("**************************\n");
    return 0;
}
