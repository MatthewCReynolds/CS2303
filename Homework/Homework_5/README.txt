Author:
    Matthew Reynolds. I didn't have any help on this assignment.

Purpose:
    perform basic arithmetic on provided 

How it works:
    Reads the data from the files provided from the command line. They're stored into to two matrix structs, one for each
    file. They're checked to see if they are of equivalent size to see if they're capable of doing the math. Then depending
    on which letter was fed into the command line, it will either subtract or add the matrices together.

How to run & cleanup:
    use the commands from the makefile, make & clean.

    make command is this:
    gcc -Wall matrix_calc.c matrix_math.c -o matrixCalc

    clean command is this:
    rm matrixCalc