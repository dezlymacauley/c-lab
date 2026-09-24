/*
    ABOUT: `while` loop

    A `while loop` is used to repeatedly perform an action
    as long as a condition is true.

    ___________________________________________________________________________

    This is the syntax:

    size_t first_index_to_iterate = value;
    size_t last_index_to_iterate = value;

    size_t i = first_index_to_iterate;

    while (i <= last_index_to_iterate) {
        Code that should run

        i++;
    }
    ___________________________________________________________________________

    E.g.

    size_t first_index_to_iterate = 0;
    size_t last_index_to_iterate = 4;

    size_t i = first_index_to_iterate;

    while (i <= last_index_to_iterate) {
        Code that should run

        i++;
    }

    ___________________________________________________________________________

    NOTE: Differences between the for loop and the while loop

    The value of `i` is set outside the loop.

    `i++` is declared as the last line inside the loop
    ___________________________________________________________________________

*/

#include <stddef.h>
#include <stdio.h>

int main(void) {

    // indexes:             0,  1,  2,  3,  4
    int player_scores[5] = {15, 24, 11, 98, 52};

    size_t first_index_to_iterate = 0;
    size_t last_index_to_iterate = 4;

    size_t i = first_index_to_iterate;

    while (i <= last_index_to_iterate) {
        printf("The element at index %zu is %d\n", i, player_scores[i]);

        i++;
    }

    // The element at index 0 is 15
    // The element at index 1 is 24
    // The element at index 2 is 11
    // The element at index 3 is 98
    // The element at index 4 is 52

    return 0;
}
