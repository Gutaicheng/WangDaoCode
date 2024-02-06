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

    /**
     * 1 byte = 8 bit
     * 1KB = 1024 byte
     * 1MB = 1024 KB
     * 1GB = 1024MB
     *
     * Base Conversion
     * example
     * decimal：123
     * binary：0000 0000 0000 0000 0000 0000 0111 1011
     * hexadecimal：(0111-->7, 1011-->)7b
     * octal：(001-->1, 111-->7, 011-->3)173
     */
    int decimal = 123;
    printf("decimal==>%d\n", decimal);
    printf("hexadecimal==>%x\n", decimal);
    printf("octal==>%o\n", decimal);

    /**
     * scanf("%type", &name)
     */
    int int_scanf;
    char char_scanf;
    scanf("%d", &int_scanf);
    fflush(stdin);
    // This means that the standard input buffer is emptied,
    // and if this line is not added,
    // the second scanf will read the '\n' of the previous line
    // But if the second scanf is no t reading a char type,
    // '\n' will be ignored
    scanf("%c", &char_scanf);
    printf("int_scanf==>%d\n", int_scanf);
    printf("char_scanf==>%c\n", char_scanf);

    /**
     * scanf multiple inputs
     * Spaced with spaces
     */
    int ma, ret;
    float mf;
    char mc;
    ret = scanf("%d %f %c", &ma, &mf, &mc);
    printf("%d, %f, %c, %d", ma, mf, mc, ret);

    return 0;
}
