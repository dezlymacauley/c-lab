/*
    ABOUT: bool

    Use this for true and false
*/

#include <stdio.h>

int main(void) {
    bool is_logged_in = true;
    bool has_admin_access = false;

    printf("is_logged_in: %s\n", is_logged_in ? "true" : "false");
    printf("has_admin_access: %s\n", has_admin_access ? "true" : "false");
}
