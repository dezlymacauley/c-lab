/*
    ABOUT: int

    Use this for whole numbers or to express `bool` values

*/

#include <stdio.h>

int main(void) {

    int items_purchased = 28;
    printf("\nitems_purchased: %d\n\n", items_purchased);

    // Prior to C23, C did not have a built-in bool type for true or false.
    // The `int` data type was used to represent `true` and `false`:
    // 1 means true
    // 0 means false
    int is_logged_in = 1;
    int has_admin_access = 0;

    printf("is_logged_in: %s\n", is_logged_in ? "true" : "false");
    printf("has_admin_access: %s\n", has_admin_access ? "true" : "false");
}
