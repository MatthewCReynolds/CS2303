Author:
    Matthew Reynolds. I had no outside help other than the provided psuedocode.

Purpose:
    prime_number.c is a program that determines whether an inputted number is a prime number.
    Meaning no numbers other than itself and 1 can be multiplied to reach it.

How the Code Works:
    It orginially declares two variables, the first being the inputted variable, and a boolean for whether the number
        is a whole number or not. 
    It then asks the user for what number they want to input to be checked.
    The code then starts a for loop starting a 2 (since dividing by 1 is always a correct answer), and goes to 1/2 of the
        inputted value since you dont need to check above that. If the variable mod i is 0, then its a whole number and the
        code returns "This value is not a prime number".    
    If it makes it through the for loop without variable % i == 0, then it does an if loop check on whether the boolean is
        not false. If its not false (aka true) then it prints out "This value is a prime number"

How to Run:
    cd "/Users/matthewreynolds/Library/CloudStorage/OneDrive-severnschool.com/University/Computer Science/CS 2303/Homework/Homework_0"
    ./"prime_number"

Compile Command:
    gcc -Wall prime_number.c

Run Command:
    ./a.out
    ./a.exe