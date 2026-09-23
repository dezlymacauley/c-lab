/*
    ABOUT: Multiple loops and nested loops

    ___________________________________________________________________________

    There are 10 items in the array
    So... n = 10
    ___________________________________________________________________________

    nested for loop ran 100 times
    To get from 10 to 100, what do you need to do?
    n x n (which 10 x 10 = 100)
    or
    n^2 (which is 10^2 = 100)
    
    ___________________________________________________________________________

    second for loop ran 10 times
    Total number of operations = O(n^2) + O(n)
    = O(n^2 + n)

    n^2 is the dominant term, and n is the non-dominant term.

    I.e. n^2 has a greater effect than `n`

    So `O(n^2 + n)` can be simplified to:

    O(n^2)
    ___________________________________________________________________________


*/

#include <stdio.h>

void print_items(int n) {

    // 100 times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%d\n", i, j);
        }
    }

    // 10 times (0 to 10, excluding 10)
    for (int k = 0; k < n; k++) {
        printf("%d\n", k);
    }
}

int main(void) { print_items(10); }

// 00
// 01
// 02
// 03
// 04
// 05
// 06
// 07
// 08
// 09
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// 20
// 21
// 22
// 23
// 24
// 25
// 26
// 27
// 28
// 29
// 30
// 31
// 32
// 33
// 34
// 35
// 36
// 37
// 38
// 39
// 40
// 41
// 42
// 43
// 44
// 45
// 46
// 47
// 48
// 49
// 50
// 51
// 52
// 53
// 54
// 55
// 56
// 57
// 58
// 59
// 60
// 61
// 62
// 63
// 64
// 65
// 66
// 67
// 68
// 69
// 70
// 71
// 72
// 73
// 74
// 75
// 76
// 77
// 78
// 79
// 80
// 81
// 82
// 83
// 84
// 85
// 86
// 87
// 88
// 89
// 90
// 91
// 92
// 93
// 94
// 95
// 96
// 97
// 98
// 99
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
