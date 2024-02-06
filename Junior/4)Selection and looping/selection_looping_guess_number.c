//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int guessNum,num,continueFlag;
    num = rand() % 100 + 1;
    while (scanf("%d", &guessNum))
    {
        if (guessNum != num)
        {
            if(guessNum > num)
                printf("big\n");
            else
                printf("small\n");
        } else {
            printf("you are right\n");
            printf("Enter 0 to stop. Enter 1 to continue.\n");
            scanf("%d", &continueFlag);
            if (continueFlag == 1)
            {
                num = rand() % 100;
                continue;
            } else break;
        }
    }
}