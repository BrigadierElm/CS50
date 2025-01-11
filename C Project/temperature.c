#include <stdio.h>
#include <cs50.h>

/*  This file will give responses to user input  */
/*  Statically declare the get_response function */
void get_response(int asked, int temp);

int main(void){

    int asked = 0;

    /*  Ask the user for the temperature    */
   int temp = get_int("How cold is it? Tell me in celsius\n");

    get_response(asked, temp);

    /* Let's ask again, and call the function a second time */
    temp = get_int("well, how about tomorrow's temperature?\n");

    get_response(asked, temp);

    /*  End program on new line */
    printf("\n");
}

/*  Based on the temperature given by the user, let's have different responses  */
void get_response(int asked, int temp){

    /*  Depending on how many times we've asked, change the response. Also increment asked  */
    asked++;
    if (asked == 1){
        printf("It's ");
    }
    else if (asked > 1){
        printf("That's going to be ");
    }

    /*  Based on temp, give responses   */
    /*  If it's below 0, say "it's freezing", above 0 but less than 20 "it's chilly", 20 to 100 "It's hot", and then else it must be above 100, say "It's hot! hot! hot! using a loop" */
    if (temp <= 0){
        printf("freezing! ");
    }
    else if (temp > 0 && temp <= 20){
        printf("chilly! ");
    }
    else if (temp > 20 && temp <= 100){
        printf("hot! ");
    }
    else{
        for(int i = 0; i < 3; i++)
        printf("hot! ");
    }
}
