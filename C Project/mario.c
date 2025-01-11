#include <cs50.h>
#include <stdio.h>

/*
    Pseudocode:

    i = 0;

    For each row (pyramid.height)
        For each col (pyramid.width)
            i++
            Print whitespace (Pyramid width - i)
            Print hashes (i)
            Print whitespace (Pyramid width - i)
*/

/*  Structures   */
typedef struct
{
    int height; // Store height
    int gap; // Store gap
} dimensions;   // create structure "dimensions"

/*  Prototype Functions    */
dimensions get_input(); // new function that processes dimensions structures
void print_whitespace(int n);
void print_block(int n);
void print_pyramid(int row, int gap);

/*  Main    */
int main(void)
{
    dimensions pyramid =
        get_input(); // Returns "pyramid" structure with user defined "height" and "width" variables
    printf("Height: %i\n", pyramid.height); // Write the dimensions to screen
    print_pyramid(pyramid.height, pyramid.gap);          // Print pyramid based on given dimensions
}

/*  Functions   */
dimensions get_input()
{
    int i = 0;
    int j = 0;
    dimensions p; // temporary struct
    do            // While varaiables entered are less than 1, keep asking
    {
        i = get_int("Enter your pyramid height: ");
        j = get_int("Enter your pyramid gap: ");
    }
    while ((i < 1 || i > 8) && (j < 1 || j > 8));
    p.height = i; // write to temp struct
    p.gap = j;
    return p;     // return temp to main "Pyramid" struct
}

void print_whitespace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_block(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void print_pyramid(int row, int gap)
{
    int increment = 0;
    for (int i = 0; i < row; i++)
    {
        increment++;
        print_whitespace(row - increment);  // Print left to right ascending pyramid
        print_block(increment);

        print_whitespace(gap);                       // Print the gap

        print_block(increment);             // Print right to left ascending pyramid
        print_whitespace(row - increment);
        printf("\n");
    }
}
