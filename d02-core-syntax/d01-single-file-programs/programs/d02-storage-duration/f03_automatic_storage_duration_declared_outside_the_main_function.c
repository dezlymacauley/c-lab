/*
    ABOUT: Automatic Storage Duration (declared outside the main function)

*/

#include <stddef.h>
#include <stdio.h>

// Unlike the `main` function,
// The variable `total_users` will only be created when this function
// is called.
void print_total(void) {

    int total_users = 10; // `total_users` will be created on this line
                          // when the `print_total` function is called.

    // The variable `total_users` and its value
    // of 10 are both stored on the stack.

    printf("total_users: %d\n", total_users);

} // Once the function call of the `print_total` function ends
  // the variable `total_users` will no longer be valid.
  // So the 4 bytes that were assigned to `total_users` are released back
  // to the program.
  // However these 4 bytes will not be released back to the operating
  // system because this is not the `main` function.

int main(void) {

    print_total(); // `total_users` will be invalid after this function
                   // has been called. The 4 bytes assigned to `total_users`
                   // will be released back to the program,
                   // but not back to the operating system because the
                   // end of `print_total` is not the end of the program.

    return 0;
} // The `main` block ends here, and since this is the end of the program,
  // all memory used by the program is released back to the operating
  // system.
