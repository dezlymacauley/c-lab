/*
    ABOUT: Function with multiple loops

    When given 10, this function prints out 20 items.

    n = 10

    The function ran 20 times.

    So this function ran `n + n` = 2n

    Therefore `O(2n)`

    You drop the consonant and call it `O(n)`

*/

#include <stdio.h>

void print_items(int n) {

    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
    }
    
    for (int j = 0; j < n; j++) {
        printf("%d\n", j);
    }
}

int main(void) {
    print_items(10);
}

// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
