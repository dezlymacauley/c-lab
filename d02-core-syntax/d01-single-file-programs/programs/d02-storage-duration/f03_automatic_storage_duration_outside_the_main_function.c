/*
    ABOUT: Automatic Storage Duration (outside the `main` function)

*/

void create_active_users_variable(void) {

    // The variable `active_users` will be created
    // on this line, when this function is called.

    // The variable `active_users` and its
    // value of `5` are both stored on the stack.
    int active_users = 5;
}

int main(void) {

    create_active_users_variable(); // The variable `active_users` will not
                                    // be valid after this line.

                                    // The memory assigned to `active_users`
                                    // is freed for reuse within the program.

                                    // However the memory assigned to
                                    // `active_users`, will not be released 
                                    // to the operating system yet, 
                                    // because `main` hasn't ended.
    return 0;
}   // The program ends here, and all memory is given back
    // to the operating system.
