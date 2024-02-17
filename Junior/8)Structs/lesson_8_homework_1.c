//
// Created by GuTaicheng on 2024/2/17.
//
#include <stdio.h>

typedef struct student {
    int num;
    char name[20];
    char sex;
}stu;

int main() {
    stu stu1;
    scanf("%d %s %c", &stu1.num, stu1.name, &stu1.sex);
    printf("%d %s %c", stu1.num, stu1.name, stu1.sex);
    return 0;
}
