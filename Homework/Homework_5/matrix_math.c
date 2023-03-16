#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

/********************************************************
*   addition(matrix, matrix)
*       given two matrixes, for every entry, add the corresponding
*       value from the other matrix, print out new matrix
*   
*   Input:
*       matrix, matrix
*   Returns:
*       void, prints out new matrix
*********************************************************/
void addition(struct matrix A, struct matrix B){
    printf("A + B =\n");
    for(int i = 0; i < A.size; i++){
        printf("%8.2f ", (A.data[i] + B.data[i]));
    }
    printf("\n");
}

/********************************************************
*   subtraction(matrix, matrix)
*       given two matrixes, for every entry, subtract the corresponding
*       value from the other matrix, print out new matrix
*   
*   Input:
*       matrix, matrix
*   Returns:
*       void, prints out new matrix
*********************************************************/
void subtraction(struct matrix A, struct matrix B){
    printf("A - B =\n"); // print out header
    for(int i = 0; i < A.size; i++){
        printf("%8.2f ", (A.data[i] - B.data[i])); // go through block by block printing
    }
}

/********************************************************
*   readMatrix(char*)
*       given a char*, read from the file the size, and
*       the values of the new matrix to store in a matrix
*       struct
*   
*   Input:
*       char*
*   Returns:
*       matrix struct pointer
*********************************************************/
struct matrix* readMatrix(char* filename){
    FILE* f1 = fopen(filename, "r");
    struct matrix *newMatrix = malloc(sizeof(struct matrix));

    fscanf(f1, "%d", &(newMatrix->size)); //read size of matrix
    newMatrix->data = malloc(sizeof(float) * newMatrix->size);

    for(int i = 0; i < newMatrix->size; i++){
        fscanf(f1, "%f", &(newMatrix->data[i])); //read matrix entries
    }

    fclose(f1);
    return newMatrix;
}

/********************************************************
*   deleteMatrix(matrix)
*       given a char*, read from the file the size, and
*       the values of the new matrix to store in a matrix
*       struct
*   
*   Input:
*       char*
*   Returns:
*       matrix struct pointer
*********************************************************/
void deleteMatrix(struct matrix *input){
    free(input->data);
    free(input);
}