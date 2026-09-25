/*
    ABOUT: Static Storage Duration

*/

// EXAMPLE: 1 => Static storage duration

int total_users = 10;   // `total_users` is created when the program starts
                        // The variable and the value of 10 are stored
                        // in the data segment (not the stack)
                        // This happens before the `main` function runs.

int main(void) {

    return 0;

} // `main` ends here, but `total_users` is NOT deleted yet

// `total_users` is deleted only when the whole program exits
