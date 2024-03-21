//
// Created by 86187 on 2024/3/21.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
void T2_2_2_08(SQList &L, int x);

int main() {
    SQList L;
    InitList(L);
    exercisesInit(L);
    PrintList(L);
    T2_2_2_08(L, 0);
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

void T2_2_2_08(SQList &L, int x) {
    int left = 0, right = L.length - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (L.data[middle] == x) break;
        if (L.data[middle] > x) {
            right = middle - 1;
        } else left = middle + 1;
    }
    if (L.data[middle] == x && middle != L.length - 1) {
        int temp = L.data[middle];
        L.data[middle] = L.data[middle + 1];
        L.data[middle + 1] = temp;
    }
    if (left > right) {
        int i;
        for (i = L.length - 1; i > right; --i) {
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.length++;
    }
}