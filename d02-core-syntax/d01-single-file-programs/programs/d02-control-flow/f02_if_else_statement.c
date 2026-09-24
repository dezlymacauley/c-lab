/*
    ABOUT: `if else` statement

    The syntax of an `if else` statement is:

    if (condition) {
        Code that should be run if the condition is satified.
    } else {
        Code that should be run if the condition is not satified.
    }

    Please note that an `if else` statement does not end with a semicolon. 

    Use case:
    When you want to handle 2 potential outcomes.

*/

#include <stdio.h>
int main() {

    int num_apples = 10;

    if (num_apples > 10) {
        printf("\nThere are more than 10 apples\n\n");
    } else {
        printf("\nThere are less than 10 apples\n\n");
    }

    return 0;
}
