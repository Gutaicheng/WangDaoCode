//
// Created by 86187 on 2024/3/21.
//

#ifndef WANGDAOCODE_SEQUENCE_LIST_DYNAMIC_ALLOCATION_H
#define WANGDAOCODE_SEQUENCE_LIST_DYNAMIC_ALLOCATION_H

#include <stdio.h>
#include <stdlib.h>

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
    printf("触发扩容，当前容量：%d\n", L.maxSize);
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
        printf("%4d", L.data[i]);
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

#endif //WANGDAOCODE_SEQUENCE_LIST_DYNAMIC_ALLOCATION_H
