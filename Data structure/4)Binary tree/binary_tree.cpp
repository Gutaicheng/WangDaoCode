//
// Created by 86187 on 2024/4/23.
//
#include "binary_tree.h"

/**
 * 先序遍历
 * @param T
 */
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/**
 * 中序遍历
 * @param T
 */
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}

/**
 * 后序遍历
 * @param T
 */
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

/**
 * 层次遍历
 * @param T
 */
void LevelOrder(BiTree T) {
    LevelQueue LQ;
    InitQueue(LQ);
    BiTNode *p;
    EnLevelQueue(LQ, T);
    while (!IsEmptyQueue(LQ)) {
        DeLevelQueue(LQ, p);
        printf("%c", p->data);
        if (p->lchild != NULL) EnLevelQueue(LQ, p->lchild);
        if (p->rchild != NULL) EnLevelQueue(LQ, p->rchild);
    }
}

/**
 * 中序线索化二叉树
 * @param p
 * @param pre
 */
void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        // TODO 别忘了 pre != NULL 防止第一个
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            // TODO 注意这里是 pre 不是p
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

/**
 * 创建中序线索化二叉树
 * @param T
 */
void CreateInTheadTree(ThreadTree &T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        if (pre ->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

/**
 * 寻找 树 p 的中序遍历的第一个节点
 * @param p
 */
ThreadNode *InOrderFirstNode(ThreadNode *p) {
    //TODO 这里不是 p != NULL
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/**
 * 获取中序遍历的下一个节点
 * @param p
 */
ThreadNode *InThreadNextNode(ThreadNode *p) {
    if (p->rtag == 0) return InOrderFirstNode(p->rchild);
        // 当 rtag 为 1 时，返回后继节点
    else return p->rchild;
}

/**
 * 中序线索二叉树遍历
 * @param T
 */
void InThreadOrder(ThreadTree T) {
    for (ThreadNode *p = InOrderFirstNode(T); p != NULL; p = InThreadNextNode(p)) {
        printf("%c", p->data);
    }
}

int main() {
    char arr[] = {'1', '2', '3', '4', '5', '6', '7'};
    int n = sizeof(arr) / sizeof(arr[0]);
    // 构建二叉树
    BiTree T = buildTree(arr, n);

    printf("先序遍历验证结果: \n");
    PreOrder(T);
    printf("\n");

    printf("中序遍历验证结果: \n");
    InOrder(T);
    printf("\n");

    printf("后序遍历验证结果: \n");
    PostOrder(T);
    printf("\n");

    printf("层次遍历验证结果: \n");
    LevelOrder(T);
    printf("\n");

    //中序线索化二叉树
    CreateInTheadTree(T);
    //中序线索二叉树遍历  找一 寻后 遍历
    printf("中序线索二叉树遍历验证结果: \n");
    InThreadOrder(T);
    return 0;
}