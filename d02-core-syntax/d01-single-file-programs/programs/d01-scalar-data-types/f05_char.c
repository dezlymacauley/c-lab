/*
    ABOUT: char

    Use this for storing a single character.
*/

#include <stdio.h>

int main(void) {

    // Always use single quotes when assigning a value to a char.
    char first_letter = 'A';

    //_________________________________________________________________________

    // EXAMPLE: 1 => Printing out the character

    printf("first_letter: %c\n", first_letter);
    // first_letter: A

    //_________________________________________________________________________
    
    // EXAMPLE: 2 => Printing out the numeric value of the character

    // The value 'A', is actually stored as an integer value that represents
    // that character.

    printf("first_letter: %d\n", first_letter);
    // first_letter: 65

    //_________________________________________________________________________
}
