//
// Created by GuTaicheng on 2024/2/6.
//
#include <stdio.h>

int main() {
    int i=0, ten, five, two, one;
    for (ten = 1; ten <=10; ten++)
    {
        for (five = 1; five <= 20; five++)
        {
            for (two = 1; two <= 40; two++)
            {
                for (one = 1; one <= 40; one++)
                {
                    if (five + ten + two + one == 40 &&
                    five *5 + ten * 10 + two * 2 + one == 100)
                        i++;
                }
            }
        }
    }
    printf("%d", i);
    return 0;
}