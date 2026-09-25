/*
    ABOUT: Allocated Storage Duration

*/

#include <stdlib.h>

// EXAMPLE: 3 => Allocated storage duration

int main(void) {

    int *total_users = malloc(sizeof(int));  // `*total_users` is created here
                                              // (memory requested from the heap)
    *total_users = 10;

    free(total_users);  // `*total_users` is deleted here — YOU decide when,
                         // not the compiler/scope

    return 0;

} // `main` ends here, but that's irrelevant to when the allocated
  // memory was destroyed — it was already freed above
