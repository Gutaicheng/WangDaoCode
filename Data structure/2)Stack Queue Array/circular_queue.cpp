//
// Created by 86187 on 2024/4/1.
//
#include "stdio.h"

#define MaxSize 6

typedef struct CQueue {
    int data[MaxSize];
    int rear,front;
    int size;
    int tag;
}CQueue;

void InitQueue_front_is_0(CQueue &Q);
bool isEmpty(CQueue Q);
bool isFull_leisure_one_node(CQueue Q);
bool isFull_use_tag(CQueue Q);
bool isFull_use_size(CQueue Q);
int length(CQueue Q);
bool EnQueue_full_leisure_one_node(CQueue &Q, int e);
bool EnQueue_full_use_tag(CQueue &Q, int e);
bool EnQueue_full_use_size(CQueue &Q, int e);
bool DeQueue(CQueue &Q, int &e);
void PrintQueue(CQueue Q);
void test_leisure_one_node(CQueue &Q);
void test_use_size(CQueue &Q);
void test_use_tag(CQueue &Q);

void InitQueue_front_is_0(CQueue &Q) {
    Q.rear = Q.front = 0;
    Q.size = 0;
}

bool isEmpty(CQueue Q) {
    if (Q.rear == Q.front) return true;
    return false;
}

bool isFull_leisure_one_node(CQueue Q) {
    if ((Q.rear + 1) % MaxSize == Q.front) return true;
    return false;
}

bool isFull_use_tag(CQueue Q) {
    if (Q.rear == Q.front && Q.tag == 1) {
        return true;
    }
    // 如果使用tag， 判空时，需要(Q.rear == Q.front && Q.tag == -1)
    return false;
}

bool isFull_use_size(CQueue Q) {
    if (Q.rear == Q.front && Q.size == MaxSize) return true;
    return false;
}

int length(CQueue Q) {
    // 空闲一个节点才能用这个表达式
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

bool EnQueue_full_leisure_one_node(CQueue &Q, int e) {
    if (isFull_leisure_one_node(Q)) return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    Q.size++;
    return true;
}

bool EnQueue_full_use_tag(CQueue &Q, int e) {
    if (isFull_use_tag(Q)) return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    Q.size++;
    return true;
}

bool EnQueue_full_use_size(CQueue &Q, int e) {
    if (isFull_use_size(Q)) return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    Q.size++;
    return true;
}

bool DeQueue(CQueue &Q, int &e) {
    if (isEmpty(Q)) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = -1;
    Q.size--;
    return true;
}

void PrintQueue(CQueue Q) {
    int temp = Q.front;
    for (int i = 0; i < Q.size; ++i) {
        printf("%d-->", Q.data[temp]);
        temp = (temp + 1) % MaxSize;
    }
    printf("\n");
}

void test_leisure_one_node(CQueue &Q) {
    int e;

    EnQueue_full_leisure_one_node(Q, 1);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 2);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 3);
    PrintQueue(Q);

    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);

    EnQueue_full_leisure_one_node(Q, 4);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 5);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 6);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 7);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 8);
    PrintQueue(Q);
    EnQueue_full_leisure_one_node(Q, 9);
    PrintQueue(Q);
}

void test_use_size(CQueue &Q) {
    int e;

    EnQueue_full_use_size(Q, 1);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 2);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 3);
    PrintQueue(Q);

    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);

    EnQueue_full_use_size(Q, 4);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 5);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 6);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 7);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 8);
    PrintQueue(Q);
    EnQueue_full_use_size(Q, 9);
    PrintQueue(Q);
}

void test_use_tag(CQueue &Q) {
    int e;

    EnQueue_full_use_tag(Q, 1);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 2);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 3);
    PrintQueue(Q);

    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);

    EnQueue_full_use_tag(Q, 4);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 5);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 6);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 7);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 8);
    PrintQueue(Q);
    EnQueue_full_use_tag(Q, 9);
    PrintQueue(Q);

    //如果使用tag， 判空时，需要(Q.rear == Q.front && Q.tag == -1)
    //如下代码则不会删除
    DeQueue(Q, e);
    PrintQueue(Q);
    DeQueue(Q, e);
    PrintQueue(Q);
}

int main() {
    CQueue Q;
    InitQueue_front_is_0(Q);
}