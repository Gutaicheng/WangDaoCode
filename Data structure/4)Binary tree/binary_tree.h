//
// Created by 86187 on 2024/4/23.
//

#ifndef WANGDAOCODE_LEVEL_QUEUE_H
#define WANGDAOCODE_LEVEL_QUEUE_H

/**
 * 存放二叉树，辅助队列的数据结构和基本操作
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
}BiTNode, *BiTree, ThreadNode, *ThreadTree;

// 创建新节点的函数
BiTNode *createNode(char data) {
    BiTNode *newNode = (BiTNode *)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->ltag = 0;
    newNode->rtag = 0;
    return newNode;
}

// 构建二叉树的函数 不要求掌握
BiTNode *buildTree(char arr[], int size) {
    if (size == 0) return NULL; // 如果数组为空，则返回空指针
    BiTNode *root = createNode(arr[0]); // 创建根节点
    BiTNode *queue[size]; // 使用队列来辅助构建二叉树
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < size) {
        BiTNode *currentNode = queue[front++];
        // 构建当前节点的左子节点
        if (i < size && arr[i] != -1) { // 如果数组中当前位置不是空值
            currentNode->lchild = createNode(arr[i]);
            queue[rear++] = currentNode->lchild;
        }
        i++;
        // 构建当前节点的右子节点
        if (i < size && arr[i] != -1) { // 如果数组中当前位置不是空值
            currentNode->rchild = createNode(arr[i]); // 修正拼写错误
            queue[rear++] = currentNode->rchild;
        }
        i++;
    }
    return root;
}
/**
 * 队列基本操作
 */
typedef struct LevelQueueNode {
    struct BiTNode *data;
    struct LevelQueueNode *next;
}LevelQueueNode;

typedef struct LevelQueue{
    LevelQueueNode *front, *rear;
}LevelQueue;

void InitQueue(LevelQueue &LQ) {
    LQ.front = (LevelQueueNode *) malloc(sizeof (LevelQueueNode));
    LQ.front->next = NULL;
    LQ.rear = LQ.front;
}

bool IsEmptyQueue(LevelQueue LQ) {
    if (LQ.front == LQ.rear) return true;
    return false;
}

bool EnLevelQueue(LevelQueue &LQ, BiTNode *e) {
    LevelQueueNode *q = (LevelQueueNode *) malloc(sizeof (LevelQueueNode));
    q->data = e;
    q->next = NULL;
    LQ.rear->next = q;
    LQ.rear = q;
    return true;
}

bool DeLevelQueue(LevelQueue &LQ, BiTNode *&e) {
    if (IsEmptyQueue(LQ)) return false;
    LevelQueueNode *s = LQ.front->next;
    e = s->data;
    LQ.front->next = s->next;
    if (LQ.rear == s) LQ.rear = LQ.front;
    free(s);
    return true;
}

#endif //WANGDAOCODE_LEVEL_QUEUE_H
