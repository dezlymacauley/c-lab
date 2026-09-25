/*
    ABOUT: `if, else if, else` statement

    The syntax of an `if, else if, else` statement is:

    if (condition) {
        Code that should be run if the condition is satified.
    } else if (another condition) {
        Code that should be run if the condition is satified.
    } else {
        Code that should be run if none of the other condition are satified.
    }

    Please note that an `if, else if, else ` statement does not
    end with a semicolon.

    Use case:
    When you want to handle 3 or more potential outcomes.

*/

#include <stdio.h>
int main() {

    int num_apples = 9;

    if (num_apples == 10) {
        printf("\nThere are exactly 10 apples\n\n");
    } else if (num_apples > 10) {
        printf("\nThere are more than 10 apples\n\n");
    } else {
        printf("\nThere are less than 10 apples\n\n");
    }

    return 0;
}
