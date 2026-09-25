/*
    ABOUT: `if statement`

    The syntax of an `if` statement is:

    if (condition) {
        Code that should be run if the condition is satified.
    }

    Please note that an `if statement` does not end with a semicolon. 

    Use case:
    When you want to handle a specific condition.

    ___________________________________________________________________________

    SECTION: Comparison Operators
    
    These are used to declare a condition

    == equal
    != not equal

    > greater than
    >= greater than or equal

    < less than
    <= less than or equal
*/

#include <stdio.h>
int main() {

    int num_apples = 11;

    if (num_apples > 10) {
        printf("\nThere are more than 10 apples\n\n");
    } 

    return 0;
}
