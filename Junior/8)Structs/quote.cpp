//
// Created by 86187 on 2024/2/17.
//
#include <stdio.h>

/**
 * 这里的'&'不再是取地址，而是引用
 * 子函数修改主函数的变量
 */
void modify_num(int &j)
{
    j += 1;
}
/**
 * 子函数修改主函数的一级指针变量
 */
void modify_pointer(int *pp, int *&qq)
{
    qq = pp;
}

int main (){
    int i = 10;
    printf("before modify_num i = %d\n", i);
    modify_num(i);
    printf("after modify_num i = %d\n", i);

    int *p = &i, *q;
    printf("before modify_pointer *p = %d\n", *p);
    modify_pointer(p, q);
    printf("after modify_pointer *p = %d *q = %d\n", *p, *q);
    return 0;
}