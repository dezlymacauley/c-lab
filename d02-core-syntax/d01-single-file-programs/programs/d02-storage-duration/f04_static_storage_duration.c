/*
    ABOUT: Static Storage Duration

    Static storage duration means:

    1. A variable is created before the program starts running.

    2. The variable will remain valid for the entire duration of the program,
    regardless of the block that the variable was declared in.
*/

#include <stdio.h>

void use_fireball_attack(void) {

    // Because this variable was created with the `static` keyword,
    // it will exist before program starts.
    // In other words, it will be created before the `main` function
    // starts, and befor the `use_fireball_attack` function is called.

    // This is a variable that will keep track of how many times the
    // `use_fireball_attack` function has been used for the duration 
    // of the program.

    // The `static` keyword also means that `fireballs_launched` will 
    // continue to exist even after this function ends. 
    // So this means that this variable can be used to keep track of how
    // many times this function was called, until the program ends.

    static int fireballs_launched = 0;

    // This will increase the value of `fireballs_launched` by 1
    fireballs_launched++;

    printf("\n🔥 Fireballs launched: %d\n", fireballs_launched);
}

int main(void) {

    use_fireball_attack(); // `fireballs_launched` will be valid even after
                           // this function ends.

    // The next function calls will have access to the
    // current value of `fireballs_launched`
    use_fireball_attack(); 
    use_fireball_attack(); 
    use_fireball_attack(); 
    use_fireball_attack(); 
    use_fireball_attack(); 

    return 0;
} // When the program ends at this line,
  // the memory that was assigned to `fireballs_launched` will be released
  // back to the program.
