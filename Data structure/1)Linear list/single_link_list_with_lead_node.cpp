//
// Created by 86187 on 2024/3/22.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitLinkList(LinkList &L);
int Length(LinkList L);
LNode *GetElem(LinkList L, int i);
LNode *LocalElem(LinkList L, int e);
bool InsertNextLNode(LNode *p, int e);
bool ListInsert_NodeNext(LinkList &L, int i, int e);
bool InsertBeforeLNode(LNode *p, int e);
bool ListInsert_NodeBefore(LinkList &L, int i, int e);
bool DeleteLNode_1(LNode *p, int &e);
bool DeleteLNode_2(LNode *p, int &e);
bool ListDelete(LinkList &L, int i, int &e);
void ListPrint(LinkList L);
LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);
void Test();

bool InitLinkList(LinkList &L) {
    L = (LNode *) malloc(sizeof (LNode));
    L->next = NULL;
    return true;
}

int Length(LinkList L) {
    LNode *p = L->next;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

LNode *GetElem(LinkList L, int i) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocalElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

bool InsertNextLNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *q = (LNode *) malloc(sizeof (LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool ListInsert_NodeNext(LinkList &L, int i, int e) {
    //如果是无头节点的单链表，i = 1 时要额外判断
    LNode *p = GetElem(L, i - 1);
    return InsertNextLNode(p, e);
}

bool InsertBeforeLNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof (LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListInsert_NodeBefore(LinkList &L, int i, int e) {
    LNode *p = GetElem(L, i);
    return InsertBeforeLNode(p, e);
}

bool DeleteLNode_1(LNode *p, int &e) {
    //这里的 p 是前驱节点，所以->next 才是要删除的节点，为空删除失败
    if (p == NULL || p->next == NULL) return false;
    LNode *s = p->next;
    p->next = s->next;
    e = s->data;
    free(s);
    return true;
}

bool DeleteLNode_2(LNode *p, int &e) {
    //此方法有局限性
    if (p == NULL || p->next == NULL) return false;
    LNode *s = p->next;
    p->data = p->next->data;
    p->next = s->next;
    free(s);
    return true;
}

bool ListDelete(LinkList &L, int i, int &e) {
    LNode *p = GetElem(L, i - 1);
    return DeleteLNode_1(p, e);
//    LNode *p = GetElem(L, i);
//    return DeleteLNode_2(p, e);
}

void ListPrint(LinkList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d-->", p->data);
        p = p->next;
    }
}

LinkList List_HeadInsert(LinkList &L) {
    L->next = NULL;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int i = 0;
    LNode *s;
    while (i < 10) {
        s = (LNode *) malloc(sizeof (LNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
        i ++;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    L->next = NULL;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    LNode *s, *r = L;
    int i = 0;
    while (i < 10) {
        s = (LNode *) malloc(sizeof (LNode));
        s->data = a[i];
        r->next = s;
        r = s;
        i++;
    }
    // 一定要注意尾指针置空，不然有脏数据
    r->next = NULL;
    return L;
}

int main () {
    Test();
//    LinkList L;
//    InitLinkList(L);
//    List_HeadInsert(L);
//    ListPrint(L);
//    printf("\n");
//    List_TailInsert(L);
//    ListPrint(L);
    return 0;
}

void Test() {
    LinkList L;
    InitLinkList(L);
    ListInsert_NodeNext(L, 1, 1);
    ListInsert_NodeNext(L, 2, 3);
    ListInsert_NodeNext(L, 3, 5);
    ListInsert_NodeNext(L, 4, 7);
    ListInsert_NodeNext(L, 5, 9);
    ListPrint(L);
    printf("\n");
    ListInsert_NodeBefore(L, 2, 2);
    ListInsert_NodeBefore(L, 4, 4);
    ListInsert_NodeBefore(L, 6, 6);
    ListInsert_NodeBefore(L, 8, 8);
    ListPrint(L);
    printf("\n");
    printf("%d\n", Length(L));
    int i;
    ListDelete(L, 2,i);
    ListDelete(L, 3,i);
    ListDelete(L, 4,i);
    ListDelete(L, 5,i);
    ListPrint(L);
    printf("\n");
    printf("%d\n", Length(L));
    printf("%d", LocalElem(L, 9)->data);
}