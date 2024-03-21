//
// Created by 86187 on 2024/3/20.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
bool T2_2_2_01(SQList &L, int &e);

int main() {
    SQList L;
    InitList(L);
    exercisesInit(L);
    int min;
    if (T2_2_2_01(L,min)) {
        PrintList(L);
        printf("min = %d", min);
    }
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

bool T2_2_2_01(SQList &L, int &e) {
    if (L.length <= 0) return false;
    int min = L.data[0];
    int pot = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < min) {
            min = L.data[i];
            pot = i;
        }
    }
    L.data[pot] = L.data[L.length - 1];
    e = min;
    L.length --;
    return true;
}