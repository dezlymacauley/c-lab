/*
    ABOUT: Automatic Storage Duration (declared inside the main function)

    This is a block `{}`

    Automatic storage duration means that a variable will be valid until
    the end of the block `{}` that it was declared in.

    When that block ends, the memory that was assigned for storing 
    the content of that variable will be automatically freed.
*/

#include <stdio.h>

int main(void) {

    int max_health = 10;   // `max_health` is created on this line.
                            // It was created inside the block `{}` of the
                            // function `main`.

                            // The variable `max_health` and its value
                            // of 10 are both stored on the stack.

    printf("size of max_health in bytes: %zu\n", sizeof(max_health));
    // size of max_health in bytes: 4

    // So when `max_health` was declared, 
    // the ?? assigned 4 bytes to store the contents of `max_health`.

    // 1 byte = 8 bits
    // So 4 bytes = 32 bits

    return 0;
}   // `max_health` is no longer valid at this point.
    // In this example, `max_health` was declared in the function `main`.
    // So when this block ends, so does the program.
    // The 4 bytes of memory that were assigned to store the contents of
    // `max_health` will be automatically released back to the operating
    // system.
