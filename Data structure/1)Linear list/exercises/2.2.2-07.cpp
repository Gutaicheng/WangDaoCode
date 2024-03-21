//
// Created by 86187 on 2024/3/21.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
void T2_2_2_07(SQList A, int m, int n);
void Reverse(SQList &A, int left, int right);

int main() {
    SQList L;
    InitList(L);
    exercisesInit(L);
    PrintList(L);
    T2_2_2_07(L, 1, 9);
    PrintList(L);
}

void exercisesInit(SQList &L) {
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 6);
    ListInsert(L, 7, 7);
    ListInsert(L, 8, 8);
    ListInsert(L, 9, 9);
    ListInsert(L, 10, 10);
}

void T2_2_2_07(SQList A, int m, int n) {
    Reverse(A, 0, m+n-1);
    Reverse(A, 0, n-1);
    Reverse(A, n, m+n-1);
}

void Reverse(SQList &A, int left, int right){
    int mid = (left + right) / 2;
    int temp;
    for (int i = left; i <= mid; ++i) {
        temp = A.data[i];
        A.data[i] = A.data[right];
        A.data[right--] = temp;
    }
}