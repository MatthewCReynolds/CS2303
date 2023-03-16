/*
    Initialize variables

    Prompt user for value
    Get value from terminal and store in variable

    Loop over all numbers  (x) less than the specified value (v)
     if the v/x is a whole number (hint, use the % operator which returns 
    the remainder of a/b)
        then the value is not prime
        print "This value is not a prime number" to the terminal
        Exit the loop

    If v/x was never a whole number
        print "This value is a prime number" to the terminal
*/


#include <stdio.h>
#include <stdbool.h>

int main(void){
    int variable; // declares the variable that the user's input is set to
    int check = 0; // declares boolean variable for if the number is whole

    printf("Please enter a value:"); // asks user for their input
    scanf("%d", &variable); // records it

    //Check before i = 2
    if(variable == 1 || variable == 0){
        check = 1;
    }

    for(int i = 2; i <= variable / 2; i++){ // Starts at 2 and goes to 1/2 of input
        if( (variable % i) == 0){ // if input % i == 0 then the variable isnt whole
            check = 1; // update "boolean"
            break;
        }
    }

    //printing out correct answer
    if(check == 0) { // check if number is whole
        printf("This value is a prime number\n"); // print it out
    } else {
        printf("This value is not a prime number.\n");
    }

    return 0;
}