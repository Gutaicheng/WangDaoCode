//
// Created by 86187 on 2024/2/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct declaration
 * The ending must have a semicolon(;)
 */
struct Student {
    int num;
    char name[18];
    char sex;
    float score;
};

/**
 * typedef is equivalent to taking an alias
 * infomation = struct info
 * pi = struct info *
 */
typedef struct info {
    int num;
    char name[20];
    float score;
}infomation, *pi;

int main() {
    /**
     * Struct definition and initialization
     * Similar to Java custom objects,
     * but the object name cannot be the same as the struct name
     */
    struct Student s = {1001, "zhangsan", 'F', 85.5};
    printf("%d %s %c %.2f\n", s.num, s.name, s.sex, s.score);
    struct Student stus[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d %s %c %f", &stus[i].num, stus[i].name, &stus[i].sex, &stus[i].score);
    }
    for (i = 0; i < 3; i++)
    {
        printf("%d %s %c %.2f\n", stus[i].num, stus[i].name, stus[i].sex, stus[i].score);
    }
    /**
     * Struct alignment
     * The size of each member variable must be an integer multiple of
     * the largest member of the non-array,
     * In particular,
     * if the sum of consecutive member variable sizes is less than an integer multiple of the size of the largest member variable,
     * the multiple member variables will be combined
     * (特别是，如果连续成员变量大小的总和小于最大成员变量大小的整数倍，则多个成员变量将被合并)
     *
     * In Struct student ,the largest member of the non-array is 'int',
     * the size of 'int' is 4,
     * char name[18]'s size is 18, if the next is '>2', so actually is 20,
     * because it should be a multiple of 4;
     * but if the next is '<2', like char sex's size is 1, so they will be combined
     * 4 + (18 + 2) + 4 = 28
     */
    struct Student s1;
    printf("The size of struct s is %d\n", sizeof (s1));
    /**
     * Struct pointer and use typedef
     */
    infomation i1 = {1001, "lili", 88.8};
    infomation iList[3] = {1002, "wangwang", 77.7,1003, "liuliu", 88.8, 1004, "zhaozhao", 99.9};
    pi p;
    p = &i1;
    printf("%d %s %.2f\n", p->num, p->name, p->score);
    p = iList;
    for(i = 0; i < 3; i++, p++)
    {
        printf("%d %s %.2f\n", p->num, p->name, p->score);
    }
    return 0;
}
