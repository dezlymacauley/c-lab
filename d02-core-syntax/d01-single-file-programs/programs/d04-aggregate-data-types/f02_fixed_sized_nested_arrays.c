/*
    ABOUT: fixed-sized nested arrays

*/

#include <stddef.h>
#include <stdio.h>
int main() {

    double weekly_expenses[3][7] = {
        // Inner List indexes:
        // 0      1      2      3     4       5      6
        //                                                 Outer List indexes:
        {11.10, 12.20, 13.30, 14.40, 15.50, 16.60, 17.70}, // 0
        {18.80, 19.90, 29.15, 21.20, 22.30, 23.40, 24.50}, // 1
        {25.60, 26.70, 27.80, 28.90, 29.00, 89.10, 31.20}  // 2
    };

    printf(
        "The element at Outer List index 1, Inner List index 5 is: %.2f\n",
            weekly_expenses[1][5]
    );
}
