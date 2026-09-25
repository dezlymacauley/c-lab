/*
    ABOUT: `for` loop

    A `for loop` is used as a convinient way to perform an action
    for every element in a list.

    ___________________________________________________________________________

    This is syntax:

    size_t first_index_to_iterate = value;
    size_t last_index_to_iterate = value;

    for (size_t i = first_index_to_iterate; i <= last_index_to_iterate; i++) {
        Code that should be run
    }
    
    ___________________________________________________________________________

    E.g.

    size_t first_index_to_iterate = 0;
    size_t last_index_to_iterate = 4;

    for (size_t i = first_index_to_iterate; i <= last_index_to_iterate; i++) {
        Code that should be run
    }

    ___________________________________________________________________________

    `size_t i = 0`

    `i` is a variable used for three things:
    1. To declare what index of the element that the loop should start at
    2. To represent the current index,
    as the `for loop` goes through the list.
    3. To access the value of the element at that index.

    NOTE: You don't have to call this variable `i`

    `i` is just the convention
    ___________________________________________________________________________

    `i++`

    This means "increase the value of `i` by 1", each time the loop runs,
    to move to the next element in the list an repeat the same action.

    This is why the data type of `i` is set to `size_t` to ensure that i
    is large enough the index of the last element in the list.

    It's best practice to use `size_t` for a value that is an index.
    ___________________________________________________________________________

    `i <= last_index_to_iterate`

    The is the condition that is required for the loop to run.

    The loop will run as long as this condition is true.

    ___________________________________________________________________________

*/

#include <stddef.h>
#include <stdio.h>

int main(void) {

    // indexes:             0,  1,  2,  3,  4
    int player_scores[5] = {15, 24, 11, 98, 52};

    size_t first_index_to_iterate = 0;
    size_t last_index_to_iterate = 4;

    for (size_t i = first_index_to_iterate; i <= last_index_to_iterate; i++) {
        printf("The element at index %zu is %d\n", i, player_scores[i]);
    }

    // The element at index 0 is 15
    // The element at index 1 is 24
    // The element at index 2 is 11
    // The element at index 3 is 98
    // The element at index 4 is 52

    return 0;
}
