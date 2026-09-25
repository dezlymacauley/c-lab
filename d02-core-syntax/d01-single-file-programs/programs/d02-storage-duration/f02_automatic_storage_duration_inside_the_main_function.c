/*
    ABOUT: Automatic Storage Duration (Inside the main function)

    Automatic storage duration means that a variable will be valid until
    the end of the block `{}` that it was declared in.

    After that point, the memory assigned to that variable will 
    be automatically freed (made available to be re-assigned).

    If the variable was declared in the `main` function,
    then when the main function ends, so does the program,
    and the memory assigned to the variable will be handed back 
    to the operating system.
*/

int main(void) {

    int total_users = 10;   // `total_users` is created on this line.
                            // It was created inside the block `{}` of the
                            // function `main`.

                            // The variable `total_users` and its value
                            // of 10 are both stored on the stack.

    return 0;
} // `total_users` is no longer valid at this point.
  // The stack space it used is now free to be re-assigned.
  // However in this case, the end of the function `main` is the end of the
  // program, so the memory assigned to `total_users`, will be given back
  // to the operating system.
