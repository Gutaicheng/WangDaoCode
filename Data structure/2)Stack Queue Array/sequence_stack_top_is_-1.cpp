//
// Created by 86187 on 2024/3/30.
//
#include "stdio.h"
#include "stdlib.h"

#define MaxSize 10

typedef struct Stack {
    int data[MaxSize];
    int top;
}SQStack;

void InitStack(SQStack &S);
bool StackEmpty(SQStack S);
bool StackFull(SQStack S);
bool Push(SQStack &S, int e);
bool Pop(SQStack &S, int &e);
bool GetTop(SQStack S, int &e);
bool DestroyStack(SQStack &S);

void InitStack(SQStack &S) {
    S.top = -1;
}

bool StackEmpty(SQStack S) {
    if (S.top == -1) return true;
    return false;
}

bool StackFull(SQStack S) {
    if (S.top == MaxSize - 1) return true;
    return false;
}

bool Push(SQStack &S, int e) {
    if (StackFull(S)) {
        printf("WARN: Stack is Full !\n");
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

bool Pop(SQStack &S, int &e) {
    if (StackEmpty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top--];
    return true;
}

bool GetTop(SQStack S, int &e) {
    if (StackEmpty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top];
    return true;
}

bool DestroyStack(SQStack &S) {
    S.top = -1;
    return true;
}

void PrintStack(SQStack S) {
    for (int i = S.top; i >=0 ; i--) {
        printf("%4d", S.data[i]);
    }
    printf("\n");
}

int main () {
    SQStack S;
    InitStack(S);
    int flag = 0, a, e;
    while (flag == 0) {
        printf("1: 入栈\n");
        printf("2: 出栈\n");
        printf("3: 读栈顶\n");
        printf("4: 输出栈\n");
        printf("5: 是否栈空\n");
        printf("6: 是否栈满\n");
        printf("7: 销毁\n");
        printf("-1: 退出\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                printf("输入入栈值：");
                scanf("%d", &e);
                Push(S, e);
                break;
            case 2:
                if (Pop(S, e)) {
                    printf("出栈值: %d\n", e);
                }
                break;
            case 3:
                if (GetTop(S, e)) {
                    printf("栈顶值: %d\n", e);
                }
                break;
            case 4:
                PrintStack(S);
                break;
            case 5:
                if (StackEmpty(S)) {
                    printf("栈空\n");
                } else printf("栈非空\n");
                break;
            case 6:
                if (StackFull(S)) {
                    printf("栈满\n");
                } else printf("栈非满\n");
                break;
            case 7:
                DestroyStack(S);
                break;
            case -1:
                flag = -1;
                break;
            default:
                printf("error code\n");
                break;
        }
    }
}