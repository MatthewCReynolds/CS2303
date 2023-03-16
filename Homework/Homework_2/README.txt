Author:
    Matthew Reynolds. I didn't have any help outside of the provided code from the original file.

Purpose:
    coffee_shop.c and its helper functions reads from a given txt file and calculates sales, cash in register, or appends/overwrites

How it works:
    It starts off by asking the user what they want to do. Then it asks for the file. it opens the file and saves it,.
    then it goes to the switch case. it switches based off function its given. 1) calls overall_revenue function which
    gets the sum of all values in the second row without the 0 id. 2) gets the balance at the end of the day which is
    the 0 id entry + sum of all entries. 3) asks several other questions. 

How to run & cleanup:
    use the makefile commands

