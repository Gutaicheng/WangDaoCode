//
// Created by 86187 on 2024/4/23.
//
#include "binary_tree.h"

/**
 * �������
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
 * �������
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
 * �������
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
 * ��α���
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
 * ����������������
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
        // TODO ������ pre != NULL ��ֹ��һ��
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            // TODO ע�������� pre ����p
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

/**
 * ��������������������
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
 * Ѱ�� �� p ����������ĵ�һ���ڵ�
 * @param p
 */
ThreadNode *InOrderFirstNode(ThreadNode *p) {
    //TODO ���ﲻ�� p != NULL
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/**
 * ��ȡ�����������һ���ڵ�
 * @param p
 */
ThreadNode *InThreadNextNode(ThreadNode *p) {
    if (p->rtag == 0) return InOrderFirstNode(p->rchild);
        // �� rtag Ϊ 1 ʱ�����غ�̽ڵ�
    else return p->rchild;
}

/**
 * ������������������
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
    // ����������
    BiTree T = buildTree(arr, n);

    printf("���������֤���: \n");
    PreOrder(T);
    printf("\n");

    printf("���������֤���: \n");
    InOrder(T);
    printf("\n");

    printf("���������֤���: \n");
    PostOrder(T);
    printf("\n");

    printf("��α�����֤���: \n");
    LevelOrder(T);
    printf("\n");

    //����������������
    CreateInTheadTree(T);
    //������������������  ��һ Ѱ�� ����
    printf("��������������������֤���: \n");
    InThreadOrder(T);
    return 0;
}