//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>

int main() {
    int i, j, k, flag = 1;
    scanf("%d", &i);
    k = i;
    while (i)
    {
        j = j * 10 + i % 10;
        i /= 10;
    }
    if (j == k)
        printf("yes");
    else
        printf("no");
//    int i, j, k, flag = 1;
//    int a[100];
//    scanf("%d", &i);
//    for (j = 0; i != 0; j++)
//    {
//        a[j] = i % 10;
//        i /= 10;
//    }
//    j--;
//    for (k = 0; k <= j; k++, j--)
//    {
//        if (a[k] == a[j])
//        {
//            continue;
//        } else {
//            flag = 0;
//            break;
//        }
//    }
//    if (flag == 0)
//        printf("no");
//    else
//        printf("yes");
    return 0;
}