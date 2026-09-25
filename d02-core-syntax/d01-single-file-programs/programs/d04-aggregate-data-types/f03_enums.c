/*
    ABOUT: enums

*/

#include <stdio.h>

// Each enum variant is an int. 
// The first enum variant starts at 0
// 0 = fws_spaceship
// 1 = ravdainen_city
// 2 = alderscythe_desert
typedef enum {
    fws_spaceship,      
    ravdainen_city,    
    alderscythe_desert
} AvailableDestinations;

int main() {
    AvailableDestinations selected_destination = 993;
    
    printf("\nselected_destination: %d\n", selected_destination);

    //_________________________________________________________________________

    // EXAMPLE: 1 => Using a switch statement to handle each enum variant

    switch (selected_destination) {
    case fws_spaceship:
        printf("\nselected_destination: fws_spaceship\n\n");
        break;
    case ravdainen_city:
        printf("\nselected_destination: ravdainen_city\n\n");
        break;
    case alderscythe_desert:
        printf("\nselected_destination: alderscythe_desert\n\n");
        break;
    default:
        printf("\nInvalid destination\n\n");
        // If an invalid destination is selected,
        // the function `main` will end and return an int value of 1,
        // to the operating system to indicate that there was an error.
        return 1;
    }

    // This line will only run if a valid destination was entered.
    printf("Travelling to destination\n");

    //_________________________________________________________________________

    return 0;
}
