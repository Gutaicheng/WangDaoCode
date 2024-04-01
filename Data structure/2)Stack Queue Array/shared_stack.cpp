//
// Created by 86187 on 2024/3/30.
//
#include "stdio.h"
#include "stdlib.h"

#define MaxSize 10

typedef struct Stack {
    int data[MaxSize];
    int top0;
    int top1;
}SQStack;

void InitStack(SQStack &S);
bool Stack0Empty(SQStack S);
bool Stack1Empty(SQStack S);
bool StackFull(SQStack S);
bool Push0(SQStack &S, int e);
bool Push1(SQStack &S, int e);
bool Pop0(SQStack &S, int &e);
bool Pop1(SQStack &S, int &e);
bool GetTop0(SQStack S, int &e);
bool GetTop1(SQStack S, int &e);
bool DestroyStack(SQStack &S);

void InitStack(SQStack &S) {
    S.top0 = -1;
    S.top1 = MaxSize;
}

bool Stack0Empty(SQStack S) {
    if (S.top0 == -1) return true;
    return false;
}

bool Stack1Empty(SQStack S) {
    if (S.top1 == MaxSize) return true;
    return false;
}

bool StackFull(SQStack S) {
    if (S.top1 - S.top0 == 1 ) return true;
    return false;
}

bool Push0(SQStack &S, int e) {
    if (StackFull(S)) {
        printf("WARN: Stack is Full !\n");
        return false;
    }
    S.data[++S.top0] = e;
    return true;
}

bool Push1(SQStack &S, int e) {
    if (StackFull(S)) {
        printf("WARN: Stack is Full !\n");
        return false;
    }
    S.data[--S.top1] = e;
    return true;
}

bool Pop0(SQStack &S, int &e) {
    if (Stack0Empty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top0--];
    S.data[S.top0 + 1] = -1;
    return true;
}

bool Pop1(SQStack &S, int &e) {
    if (Stack1Empty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top1++];
    S.data[S.top1 - 1] = -1;
    return true;
}

bool GetTop0(SQStack S, int &e) {
    if (Stack0Empty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top0];
    return true;
}

bool GetTop1(SQStack S, int &e) {
    if (Stack1Empty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S.data[S.top1];
    return true;
}

bool DestroyStack(SQStack &S) {
    S.top0 = -1;
    S.top1 = MaxSize;
    return true;
}

void PrintStack(SQStack S) {
    if (Stack0Empty(S)) {
        printf("Õ»0¿Õ\n");
    } else {
        for (int i = S.top0; i >= 0; i --) {
            printf("%4d", S.data[i]);
        }
        printf("\n");
    }
    if (Stack1Empty(S)) {
        printf("Õ»1¿Õ\n");
    } else {
        for (int i = S.top1; i < MaxSize; i++) {
            printf("%4d", S.data[i]);
        }
        printf("\n");
    }
}

int main () {
    SQStack S;
    InitStack(S);
    int flag = 0, a, e;
    while (flag == 0) {
        printf("10: ÈëÕ»0\n");
        printf("11: ÈëÕ»1\n");
        printf("20: ³öÕ»0\n");
        printf("21: ³öÕ»1\n");
        printf("30: ¶ÁÕ»0¶¥\n");
        printf("31: ¶ÁÕ»1¶¥\n");
        printf("4: Êä³öÕ»\n");
        printf("50: ÊÇ·ñÕ»0¿Õ\n");
        printf("51: ÊÇ·ñÕ»1¿Õ\n");
        printf("6: ÊÇ·ñÕ»Âú\n");
        printf("7: Ïú»Ù\n");
        printf("-1: ÍË³ö\n");
        scanf("%d", &a);
        switch (a) {
            case 10:
                printf("ÊäÈëÈëÕ»0Öµ£º");
                scanf("%d", &e);
                Push0(S, e);
                break;
            case 11:
                printf("ÊäÈëÈëÕ»1Öµ£º");
                scanf("%d", &e);
                Push1(S, e);
                break;
            case 20:
                if (Pop0(S, e)) {
                    printf("³öÕ»0Öµ: %d\n", e);
                }
                break;
            case 21:
                if (Pop1(S, e)) {
                    printf("³öÕ»1Öµ: %d\n", e);
                }
                break;
            case 30:
                if (GetTop0(S, e)) {
                    printf("Õ»0¶¥Öµ: %d\n", e);
                }
                break;
            case 31:
                if (GetTop1(S, e)) {
                    printf("Õ»1¶¥Öµ: %d\n", e);
                }
                break;
            case 4:
                PrintStack(S);
                break;
            case 50:
                if (Stack0Empty(S)) {
                    printf("Õ»0¿Õ\n");
                } else printf("Õ»0·Ç¿Õ\n");
                break;
            case 51:
                if (Stack1Empty(S)) {
                    printf("Õ»1¿Õ\n");
                } else printf("Õ»1·Ç¿Õ\n");
                break;
            case 6:
                if (StackFull(S)) {
                    printf("Õ»Âú\n");
                } else printf("Õ»·ÇÂú\n");
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