/*
    ABOUT: ternary operator

    Use this when you have only two potential outcomes.

*/

#include <stdbool.h>
#include <stdio.h>

int main() {

    int age = 18;

    // If age is greater than or equal to 18, 
    // the value of can_sign_up will be set to true, 
    // otherwise it will be set to false.
    bool can_sign_up = (age >= 18) ? true : false;

    printf("age: %d\n", age);
    printf("can_sign_up: %s\n", can_sign_up ? "true" : "false");

    return 0;
}
