/*
    ABOUT: Automatic Storage Duration (created in the main function)

    This is a block `{}`

    Automatic storage duration means that a variable will be valid until
    the end of the block `{}` that it was declared in.

    When that block ends, the memory that was assigned for storing 
    the content of that variable will be automatically freed.
*/

#include <stdio.h>

int main(void) {

    int total_users = 10;   // `total_users` is created on this line.
                            // It was created inside the block `{}` of the
                            // function `main`.

                            // The variable `total_users` and its value
                            // of 10 are both stored on the stack.

    printf("size of total_users in bytes: %zu\n", sizeof(total_users));
    // size of total_users in bytes: 4

    // So when `total_users` was declared, 
    // the ?? assigned 4 bytes to store the contents of `total_users`.

    // 1 byte = 8 bits
    // So 4 bytes = 32 bits

    return 0;
}   // `total_users` is no longer valid at this point.
    // In this example, `total_users` was declared in the function `main`.
    // So when this block ends, so does the program.
    // The 4 bytes of memory that were assigned to store the contents of
    // `total_users` will be automatically released back to the operating
    // system.
