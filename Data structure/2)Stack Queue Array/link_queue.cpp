//
// Created by 86187 on 2024/4/7.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front, *rear;
}LinkQueue;

bool InitLinkQueue(LinkQueue &Q) {
    Q.front = (LinkNode *) malloc(sizeof (LinkNode));
    Q.front->next = NULL;
    Q.rear = Q.front;
    return true;
}

bool isEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) return true;
    return false;
}

bool EnQueue(LinkQueue &Q, int e) {
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p; ///别忘了修改队尾指针
    return true;
}

bool DeQueue(LinkQueue &Q, int &e) {
    if (isEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    ///注意若是删除最后一个元素即队尾，要将Q.rear == Q.front
    ///由于此时Q.front->next == NULL, 所以判断条件有很多
    ///但是以下这个最为直观
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return true;
}

void PrintQueue(LinkQueue Q) {
    LinkNode *p = Q.front->next;
    while (p != NULL) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("\n");
}

void test(LinkQueue &Q) {
    int e;
    EnQueue(Q, 1);
    PrintQueue(Q);
    EnQueue(Q, 2);
    PrintQueue(Q);
    EnQueue(Q, 3);
    PrintQueue(Q);
    EnQueue(Q, 4);
    PrintQueue(Q);

    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);

    EnQueue(Q, 5);
    PrintQueue(Q);
    EnQueue(Q, 6);
    PrintQueue(Q);
    EnQueue(Q, 7);
    PrintQueue(Q);
    EnQueue(Q, 8);
    PrintQueue(Q);

    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);
}

int main() {
    LinkQueue Q;
    InitLinkQueue(Q);
    test(Q);
}