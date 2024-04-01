//
// Created by 86187 on 2024/3/30.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct StackNode {
    int data;
    struct StackNode *next;
}StackNode, *LinkStack;

void InitStack(LinkStack &S);
bool StackEmpty(LinkStack S);
bool Push(LinkStack &S, int e);
bool Pop(LinkStack &S, int &e);
bool GetTop(LinkStack S, int &e);
bool DestroyStack(LinkStack &S);

void InitStack(LinkStack &S) {
    S = (StackNode *) malloc(sizeof (StackNode));
    S->next = NULL;
}

bool StackEmpty(LinkStack S) {
    if (S->next == NULL) return true;
    return false;
}

bool Push(LinkStack &S, int e) {
    StackNode *p = (StackNode *) malloc(sizeof (StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}

bool Pop(LinkStack &S, int &e) {
    if (StackEmpty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    StackNode *s = S->next;
    e = s->data;
    S->next = s->next;
    free(s);
    return true;
}

bool GetTop(LinkStack S, int &e) {
    if (StackEmpty(S)) {
        printf("WARN: Stack is empty !\n");
        return false;
    }
    e = S->next->data;
    return true;
}

bool DestroyStack(LinkStack &S) {
    StackNode *s, *p = S->next;
    while (p != NULL) {
        s = p;
        p = p->next;
        free(s);
    }
    S->next = NULL;
    return true;
}

void PrintStack(LinkStack S) {
    StackNode *p = S->next;
    while (p != NULL) {
        printf("-->%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main () {
    LinkStack S;
    InitStack(S);
    int flag = 0, a, e;
    while (flag == 0) {
        printf("1: 入栈\n");
        printf("2: 出栈\n");
        printf("3: 读栈顶\n");
        printf("4: 输出栈\n");
        printf("5: 是否栈空\n");
        printf("6: 销毁\n");
        printf("-1: 退出\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                printf("输入入栈值：");
                scanf("%d", &e);
                printf("%d\n",e);
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