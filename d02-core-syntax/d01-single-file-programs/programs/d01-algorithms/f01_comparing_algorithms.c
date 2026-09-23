/*
    ABOUT: Comparing Algorithms

    Big O is used to compare the efficiency of an algorithm.

    The O in `Big O` is the greek letter Omicron.


    The efficiency of an algorithm is measured by how much longer 
    the algorithm takes to complete, as the input size is increased.

    The variable `n` is commonly used for the input size.

    Big O notation is a mathematical tool used to give 
    a rough measure of the rate at which the completion time of 
    the algorithm increases as `n` increases.

    //_________________________________________________________________________
 
    E.g. Looping through an array

    1, 2, 3, 4, 5, 6, 7

    Best case = ??? (Omega aka Big O best case)

    Trying to find 1 is best case. Solving the problem with the smallest
    amount of effort
    
    //_________________________________________________________________________

    Average case 4 (Theta aka Big O average case)

    //_________________________________________________________________________

    Worse case = ??  (Omicron aka Big O)

    Trying to find 7 because it is right at the end.

    Technically Big O is always worse case

    "You application is only as fast as your slowest query"
    
    //_________________________________________________________________________
    
    // SECTION: O(n)

    This is pronounced "Owe of n"

    //_________________________________________________________________________

*/

#include <stdio.h>

// O(n)
// The number of times the function runs = n
// So if there are 10 elements, the function runs ten times.

void print_items(int n) {

    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
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
