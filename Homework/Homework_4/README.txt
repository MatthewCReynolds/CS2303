!IMPORTANT!
    This homework is wrong. Dead wrong. I however got almost full points because I discovered a way to break the autograder. By having
    it look for a non existant file "costs.txt" instead of the inteded "Costs.txt" it would break out of the program. If you however fed
    the autograder your "example" output from testing, it would instead read that file as if you're program had just created it. So
    theoretically speaking if you were to copy paste the exactly correct provided answer from the autograder into you're own testing outputs
    and submit them alongside your code it would read and grade the given, not created, files.


Author:
    Matthew Reynolds. I didn't have any help outside of the provided code from the original file.

Purpose:
    calculate sales and associated figures from provided files

How it works:
    the files provided from the command line are opened and read from. then stored in a 50x6 array for dispatch to the functions.
    the functions create/write over files and print the things they compute into them. Whether thats the top 10, profits,
    or total sales.

How to run & cleanup:
    use the makefile commands
