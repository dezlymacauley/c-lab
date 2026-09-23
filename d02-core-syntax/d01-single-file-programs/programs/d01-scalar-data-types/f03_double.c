/*
    ABOUT: double

    Use this for numbers with a many decimals,
    and where you want to maximum accuracy.
*/

#include <stdio.h>

int main(void) {
    float interest_rate = 12.526323f;

    // Prints out the number and rounds to 2 decimals
    printf("interest_rate: %.2f\n", interest_rate);
}
