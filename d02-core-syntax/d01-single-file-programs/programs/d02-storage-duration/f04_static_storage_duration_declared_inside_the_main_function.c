/*
    ABOUT: Static Storage Duration (declared inside the main function)

    Static storage duration means:

    1. A variable is created before the program starts running.

    2. The variable will remain valid for the entire duration of the program,
    regardless of the block that the variable was declared in.
*/

#include <stdio.h>
int main(void) {

    static int total_users = 10; // `total_users` is created here, but
                                 // unlike automatic storage duration,
                                 // this memory for this variable was
                                 // actually assigned before the `main`
                                 // function started running.
                                 // This is because this variable 
                                 // was declared with the `static` keyword.
                                 
    printf("total_users: %d\n", total_users);

    return 0;
} // `total_users` is no longer valid at this point, 
  // because this is where the program ends.
