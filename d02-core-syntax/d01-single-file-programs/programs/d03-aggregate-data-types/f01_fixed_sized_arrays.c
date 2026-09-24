/*
    ABOUT: fixed-sized arrays

    An array stores multiple elements contiguously in memory.
    All of the elements of an array must be of the same data type.

*/

#include <stdio.h>
int main() {

    int player_scores[4] = {12, 24, 50, 16};
   
    printf("\n");
    printf("The first element is %d\n", player_scores[0]);
    printf("The second element is %d\n", player_scores[1]);
    printf("The third element is %d\n", player_scores[2]);
    printf("The fourth element is %d\n", player_scores[3]);
    printf("\n");

    // The first element is 12
    // The second element is 24
    // The third element is 50
    // The fourth element is 16
}
