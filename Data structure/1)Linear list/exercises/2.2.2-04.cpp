//
// Created by 86187 on 2024/3/21.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
bool T2_2_2_04(SQList &L, int s, int t);

int main() {
    SQList L;
    InitList(L);
    exercisesInit(L);
    PrintList(L);
    T2_2_2_04(L, 2,5);
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

bool T2_2_2_04(SQList &L, int s, int t) {
    if (s > t || L.length == 0) return false;
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >=s && L.data[i] <= t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}