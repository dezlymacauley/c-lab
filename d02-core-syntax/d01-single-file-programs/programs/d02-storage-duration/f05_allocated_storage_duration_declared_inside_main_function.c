/*
    ABOUT: Allocated Storage Duration (declared inside the main function)

    Allocated storage duration is used when you want to create a variable
    and store its contents on the heap.

    You do this by making a request to the heap allocator to receive memory
    from the heap that is large enough to store the content of the variable.

    This is done using the `malloc` keyword
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    //_________________________________________________________________________

    // STEP: 1 => Figure out how much memory you want to store on the heap

    // I want to create a variable called `player_score`,
    // which is an int, and I want its contents stored on the heap.

    // The size of an int in bytes
    size_t int_size_in_bytes = sizeof(int);

    printf("The int data type is: %zu bytes\n", int_size_in_bytes);
    printf("This is the same as: %zu bits\n", int_size_in_bytes * 8);
    // The int data type is: 4 bytes
    // This is the same as: 32 bits
    
    //_________________________________________________________________________

    // STEP: 2 => Make the request to the heap allocator using malloc

    int* player_score = malloc(int_size_in_bytes);
    
    //_________________________________________________________________________
    
    // STEP: 3 => Check that the request for memory was succesful

    if (player_score == NULL) {
        printf("Error: malloc failed to allocate memory\n");
        printf("The player_score pointer can't be used.\n");
        return 1;
    }

    printf("The contents of player_score are stored at:\n");
    printf("Memory address: %p on the heap\n", (void *)&player_score);
    // Memory address: 0x7ffd5f119948 on the heap

    //_________________________________________________________________________

    *player_score = 10;
    
    //_________________________________________________________________________

    printf("player_score is: %d\n", *player_score);
    // player_score is: 10
    
    //_________________________________________________________________________
   
    // STEP: 3 => Cleanup
    
    free(player_score);
    player_score = NULL;

    //_________________________________________________________________________

    return 0;
} 
