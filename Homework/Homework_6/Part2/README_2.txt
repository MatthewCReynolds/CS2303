Author:
    Matthew Reynolds. I didn't have any help on this assignment outside of the provided code.

Purpose:
    To explore inhertience and make a Cat.cpp file that can do very similar functions to the dog.cpp file.

How it works:
    It inherits from Cat.h, then I define all functions inside the Cat.cpp same as the dog.cpp file. Then when they're called
    in test_cat.cpp it make a new Cat object and calls its methods

How to run & cleanup:
    use the commands from the makefile, make & clean.

    make command is this:
    g++ -Wall -lm -o runCat test_cat.cpp Cat.cpp Animal.cpp

    clean command is this:
    rm runCat