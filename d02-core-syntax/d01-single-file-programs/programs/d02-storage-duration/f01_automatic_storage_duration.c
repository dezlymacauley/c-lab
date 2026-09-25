/*
    ABOUT: Storage Duration

    In C, storage duration refers to how long an object remains in memory,
    from the time the object is created until the object is deleted.

    There are 4 storage durations:
    1. automatic
    2. static
    3. allocated
    4. thread

*/

int main(void) {

    // EXAMPLE: 1 => Automatic storage duration

    int total_users = 10;   // `total_users` is created on this line
                            // The variabble the value of 10 are stored 
                            // on the stack

    return 0;
} // `total_users` is deleted here. The `main` function ends at this line.
