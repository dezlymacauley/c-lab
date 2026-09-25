/*
    ABOUT: fixed-sized arrays

    An array stores multiple elements contiguously in memory.
    All of the elements of an array must be of the same data type.

*/

#include <stddef.h>
#include <stdio.h>
int main() {

    int player_scores[4] = {12, 24, 50, 16};

    printf("\n");
    printf("The first element is %d\n", player_scores[0]);
    printf("The second element is %d\n", player_scores[1]);
    printf("The third element is %d\n", player_scores[2]);
    printf("The fourth element is %d\n", player_scores[3]);

    // The first element is 12
    // The second element is 24
    // The third element is 50
    // The fourth element is 16

    //_________________________________________________________________________

    // EXAMPLE: 1 => How to get the number of elements in an fixed-sized array

    size_t number_of_elements_in_player_scores =
        sizeof(player_scores) / sizeof(player_scores[0]);

    printf("\nnumber_of_elements_in_player_scores: %zu\n\n",
           number_of_elements_in_player_scores);

    //_________________________________________________________________________
}
