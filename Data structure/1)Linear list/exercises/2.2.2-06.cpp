//
// Created by 86187 on 2024/3/21.
//
#include "sequence_list_dynamic_allocation.h"

void exercisesInit(SQList &L);
SQList T2_2_2_06_My_Answer(SQList &A, SQList B);
bool T2_2_2_06_Standard_Answer(SQList A, SQList B, SQList &C);

int main() {
    //2.2.2.06_My_Answer
//    SQList A, B;
//    InitList(A);
//    InitList(B);
//    exercisesInit(A);
//    exercisesInit(B);
//    PrintList(A);
//    PrintList(B);
//    T2_2_2_06_My_Answer(A, B);
//    PrintList(A);

    //2.2.2.06_Standard_Answer
    SQList A, B, C;
    InitList(A);
    InitList(B);
    InitList(C);
    exercisesInit(A);
    exercisesInit(B);
    T2_2_2_06_Standard_Answer(A, B, C);
    PrintList(A);
    PrintList(B);
    PrintList(C);
    printf("%d", Length(C));
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

SQList T2_2_2_06_My_Answer(SQList &A, SQList B) {
    //既然是两个有序顺序表重新排序，可以联想到插入排序和选择排序，都是分成一个已经排序，一个未排序
    //我的时间复杂度高，空间复杂度低，答案时间复杂度低，更加复杂度高，答案更佳
    for (int i = 0; i < B.length; ++i) {
        for (int j = A.length - 1; j >= 0 ; j--) {
            if (A.data[j] > B.data[i]) {
                A.data[j + 1] = A.data[j];
            } else {
                A.data[j + 1] = B.data[i];
                A.length ++;
                break;
            }
        }
    }
    return A;
}

bool T2_2_2_06_Standard_Answer(SQList A, SQList B, SQList &C) {
    while (C.maxSize < A.length + B.length) {
        ListExpansion(C, 5);
    }
    int a = 0, b = 0, c = 0;
    while (a < A.length && b < B.length){
        if (A.data[a] < B.data[b]) {
            C.data[c++] = A.data[a];
            a ++;
        } else {
            C.data[c++] = B.data[b];
            b ++;
        }
    }
    while (a < A.length) {
        C.data[c++] = A.data[a++];
    }
    while (b < B.length) {
        C.data[c++] = B.data[b++];
    }
    C.length = c;
    return true;
}
