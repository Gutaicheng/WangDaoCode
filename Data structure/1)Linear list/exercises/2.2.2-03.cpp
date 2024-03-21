//
// Created by 86187 on 2024/3/21.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
bool T2_2_2_03(SQList &L, int x);

int main() {
    SQList L;
    InitList(L);
    exercisesInit(L);
    PrintList(L);
    T2_2_2_03(L, 3);
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

bool T2_2_2_03(SQList &L, int x) {
    int k =0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k ++;
        }
    }
    L.length = k;
    return true;
}