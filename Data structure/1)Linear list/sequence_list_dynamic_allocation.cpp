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
    printf("�������ݣ���ǰ������%d", L.maxSize);
    free(p);
}

int Length(SQList L) {
    return L.length;
}

bool ListInsert(SQList &L, int i, int e) {
    if (i < 0 || i > L.length + 1) {
        printf("����λ�ò��Ϸ�\n");
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
        printf("����λ�ò��Ϸ�\n");
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
        printf("����λ�ò��Ϸ�\n");
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
        printf("1.��ȡ��\n");
        printf("2.��������\n");
        printf("3.ɾ������\n");
        printf("4.��ֵɾ��\n");
        printf("5.��λ����\n");
        printf("6.��ֵ����\n");
        printf("7.������Ա�\n");
        printf("8.�������Ա�\n");
        printf("���빦�ܺţ�");
        scanf("%d", &a);
        switch (a) {
            case 1 :
                printf("%d\n", Length(L));
                break;
            case 2:
                printf("�������λ�ã�\n");
                scanf("%d", &i);
                printf("�������ֵ��\n");
                scanf("%d", &e);
                ListInsert(L,i,e);
                break;
            case 3:
                printf("����ɾ��λ�ã�\n");
                scanf("%d", &i);
                ListDelete(L, i, e);
                printf("��ɾ����ֵΪ: %d\n", e);
                break;
            case 4:
                printf("����ɾ��ֵ��\n");
                scanf("%d", &e);
                ListDelete_LocateElem(L, e);
                break;
            case 5:
                printf("�������λ�ã�\n");
                scanf("%d", &i);
                printf("�����ҵ�ֵΪ: %d\n", GetElem(L, i));
                break;
            case 6:
                printf("�������ֵ��\n");
                scanf("%d", &e);
                printf("�����ҵ�ֵ��λ��Ϊ: %d\n", LocateElem(L, e));
                break;
            case 7:
                PrintList(L);
                break;
            case 8:
                DestroyList(L);
                break;
            default:
                printf("��Ч���ܺ�");
                flag = -1;
                break;
        }
    }
    return 0;
}