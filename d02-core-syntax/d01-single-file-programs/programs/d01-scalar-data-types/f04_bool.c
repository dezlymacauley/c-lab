/*
    ABOUT: bool

    Use this for true and false
*/

// This is required for using the macros:
// bool, true, and false
#include <stdbool.h>

#include <stdio.h>


int main(void) {

    bool is_logged_in = true;
    bool has_admin_access = false;

    // bool is a macro for the built-in data type `_Bool`
    // `true` is a macro for the value 1
    // `false` is a macro for the value 0

    //_________________________________________________________________________
    
    // EXAMPLE: 1 => Printing out the values of the macros

    printf("\nis_logged_in: %d\n", is_logged_in);
    printf("has_admin_access: %d\n\n", has_admin_access);

    // is_logged_in: 1
    // has_admin_access: 0

    //_________________________________________________________________________

    // EXAMPLE: 2 => Printing out true and false

    // `%s` is the format specifier for string.
    // This lets C know that you intend to replace %s with a string.

    // `is_logged_in ? "true" : "false"`
    // This means: 
    // If `is_logged_in` = true, then replace `%s` with "true"
    // If `is_logged_in` = false, then replace `%s` with "false"
    printf("is_logged_in: %s\n", is_logged_in ? "true" : "false");
    printf("has_admin_access: %s\n\n", has_admin_access ? "true" : "false");
}
