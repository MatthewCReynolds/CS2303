#include <iostream>
#include <string>
#include <iomanip>

#include "Matrix.h"

Matrix::Matrix(int l1){
    length = l1;
    data = new float[length];
    
}

Matrix::Matrix(){
    length = 0;
    data = NULL;
    
}

int Matrix::getLength(){
    return length;
 }


float* Matrix::getData(){
    return data;
}

void Matrix::readMatrix(string fileName) {
    ifstream input;
    input.open(fileName);
    
    for (int i = 0; i < length; i++){
        input >> data[i];
    }
    input.close();
}

/*******************************************************************************
* void print(Matrix& A){
*
* Output:
*   Prints A to the screen
********************************************************************************/

void Matrix::print(){

   // print values to screen
    for (int i = 0; i < length; i++){
       cout << std::setw(8) << data[i];  
    }
    printf("\n");

}

/*******************************************************************************
* Matrix::~Matrix()
*
* Deconstructor for Matrix object
********************************************************************************/
Matrix::~Matrix(){
    delete data;
}

/*******************************************************************************
* Matrix + operand overload
*
*   takes in an input and has the data from the other one, makes a new matrix of
*   the same length, and then index by index adds the two together
*
* return: a new matrix object
********************************************************************************/
Matrix operator+(float f, const Matrix& input) {
    Matrix newMatrix(input.length); //Make new matrix of same length to return

    for (int i = 0; i < input.length; i++) {
        newMatrix.data[i] = f + input.data[i]; //adds every index of both matrices together
    }

    return newMatrix;
}

/*******************************************************************************
* Matrix << operand overload
*
*   takes in an input and has the data from the other one, makes a new matrix of
*   the same length, and then index by index adds the two together
*
* return: a new matrix object
********************************************************************************/
std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    os << "[";

    for (int i = 0; i < mat.length; i++) {
        os << mat.data[i];

        if (i < mat.length - 1) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

/*******************************************************************************
* Matrix + operand overload
*
*   takes in an input and has the data from the other one, makes a new matrix of
*   the same length, and then for every index adds the input to it
*
* return: a new matrix object
********************************************************************************/
Matrix Matrix::operator+(float input) {
    Matrix newMatrix(length); //make new Matrix to return

    for (int i = 0; i < length; i++) {
        newMatrix.data[i] = data[i] + input; // add the input to every index
    }

    return newMatrix;
}

Matrix Matrix::operator+(Matrix &B){
    Matrix C(length);
    for (int i = 0; i < length; i ++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
}