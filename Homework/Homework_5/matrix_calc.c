#include <stdlib.h>
#include <stdio.h>
#include "matrix_math.h"

int main(int argc, char *argv[]){
    //open files & save file data to matrix struct
    struct matrix *A = readMatrix(argv[1]);
    struct matrix *B = readMatrix(argv[2]);

    //Check if they are capable of doing the math
    if(A->size != B->size){
        printf("This math cannot be performed.\n");
        return 0;
    }
    
    //Perform calculation
    char *inputLetter = argv[3];
    switch(*inputLetter){
        case 'a': //if addition, add
            addition(*A, *B);
            break;
        case 's': //if subtraction, subtract
            subtraction(*A, *B);
            break;
        default:
            printf("Letter provided was not 'a' or 's'."); // For debugging
            break;
    }

    //delete matrices & free everything
    deleteMatrix(A);
    deleteMatrix(B);
    return 0;
}