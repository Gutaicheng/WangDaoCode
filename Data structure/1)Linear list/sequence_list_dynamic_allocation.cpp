//
// Created by 86187 on 2024/3/3.
//
#include "stdio.h"
#include "stdlib.h"

#define InitSize 5

typedef struct sequeneList {
    int *data;
    int maxSize;
    int length;
}SQList;

void InitList(SQList &L);
int Length(SQList L);
bool ListInsert(SQList &L, int i, int e);
void ListExpansion(SQList &L, int size);
bool ListDelete(SQList &L, int i, int &e);
bool ListDelete_LocateElem(SQList &L, int e);
void PrintList(SQList L);
int GetElem(SQList L, int i);
int LocateElem(SQList L, int e);

void InitList(SQList &L) {
    L.maxSize = InitSize;
    L.length = 0;
    L.data = (int *) malloc(sizeof (int) * L.maxSize);
}

void ListExpansion(SQList &L, int size) {
    int *p = L.data;
    L.maxSize = L.maxSize + size;
    L.data = (int *) malloc(sizeof (int) * L.maxSize);
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }
    printf("触发扩容，当前容量：%d", L.maxSize);
    free(p);
}

int Length(SQList L) {
    return L.length;
}

bool ListInsert(SQList &L, int i, int e) {
    if (i < 0 || i > L.length + 1) {
        printf("输入位置不合法\n");
        return false;
    }
    if (L.length >= L.maxSize) {
        ListExpansion(L, 5);
    }
    for (int j = L.length; j >= i ; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SQList &L, int i, int &e) {
    if (i < 0 || i > L.length) {
        printf("输入位置不合法\n");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

bool ListDelete_LocateElem(SQList &L, int e) {
    int i = LocateElem(L, e);
    if (i)
        return ListDelete(L, i, e);
    return true;
}

void PrintList(SQList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int GetElem(SQList L, int i) {
    if (i < 0 || i > L.length) {
        printf("输入位置不合法\n");
        return -1;
    }
    return L.data[i - 1];
}

int LocateElem(SQList L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
    }
    return -1;
}

void DestroyList(SQList &L) {
    free(L.data);
    L.maxSize = 0;
    L.length = 0;
}

int main() {
    SQList L;
    InitList(L);
    int flag = 1, a, i, e;
    while (flag == 1) {
        printf("1.获取表长\n");
        printf("2.插入数据\n");
        printf("3.删除数据\n");
        printf("4.按值删除\n");
        printf("5.按位查找\n");
        printf("6.按值查找\n");
        printf("7.输出线性表\n");
        printf("8.销毁线性表\n");
        printf("输入功能号：");
        scanf("%d", &a);
        switch (a) {
            case 1 :
                printf("%d\n", Length(L));
                break;
            case 2:
                printf("输入插入位置：\n");
                scanf("%d", &i);
                printf("输入插入值：\n");
                scanf("%d", &e);
                ListInsert(L,i,e);
                break;
            case 3:
                printf("输入删除位置：\n");
                scanf("%d", &i);
                ListDelete(L, i, e);
                printf("被删除的值为: %d\n", e);
                break;
            case 4:
                printf("输入删除值：\n");
                scanf("%d", &e);
                ListDelete_LocateElem(L, e);
                break;
            case 5:
                printf("输入查找位置：\n");
                scanf("%d", &i);
                printf("被查找的值为: %d\n", GetElem(L, i));
                break;
            case 6:
                printf("输入查找值：\n");
                scanf("%d", &e);
                printf("被查找的值的位置为: %d\n", LocateElem(L, e));
                break;
            case 7:
                PrintList(L);
                break;
            case 8:
                DestroyList(L);
                break;
            default:
                printf("无效功能号");
                flag = -1;
                break;
        }
    }
    return 0;
}