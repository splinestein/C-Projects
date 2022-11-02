/* 
Made by Github user: splinestein
MIT License. 
*/

#include <stdio.h>
#include <stdlib.h>
 
// Add the values into a struct. They can't be defined here.
struct Tuple {
    size_t chars; // Character count. Size of array.
    char *str; // Will be a NULL ptr.
};
 
// Make a tuple so we can return multiple values.
struct Tuple init()
{
    int a = 0; // For getting the character.
    struct Tuple tuple = { 0, NULL }; // Fill the values;

    // MAIN LOGIC:
    while (1) {
        a = getchar();
        if (a != EOF && a != '\n') {
            ++tuple.chars; //++ before is faster than ++ after.
            tuple.str = realloc(tuple.str, sizeof(char)*tuple.chars);
            tuple.str[tuple.chars-1] = a;
            // putchar(a);
        } else {
            // Add a NULL terminator '\0' for the char array. Ya.. I know there's probably a better way to do this.
            printf("\n%ld\n", tuple.chars);
            tuple.str = realloc(tuple.str, sizeof(char)*tuple.chars+1);
            tuple.str[tuple.chars] = '\0'; // Yes technically the character count will be wrong by 1 after this.
            return tuple;
        }
    }
}

// Return multiple values from a function in C
int main(void)
{
    struct Tuple tuple = init();
    size_t said_size = tuple.chars;
    char *str_array = tuple.str;

    printf("You wrote: %s and the letter count in the word is: %ld\n", str_array, said_size);

    // free and null.
    free(tuple.str);
    tuple.str = NULL;

    return 0;
}
