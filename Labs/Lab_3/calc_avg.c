#include <stdio.h>
#include <stdlib.h>

float get_average(float A[], int size);
float* readData(char* filename, int size); // function prototype

int main(int argc, char *argv[]){

    if(argc != 3) { //break out
        printf("not enough values");
        return 0;
    }

    int numVals = atoi(argv[1]);                // store number of data values

    float *data;
    data = readData(argv[2], numVals);        // create array to store values

    printf("Your values are: ");
    for (int i = 0; i < numVals; i++){
        printf("%7.2f ", data[i]);
    }
    printf("\n");

    float thisAv = get_average(data, numVals);
    printf("Your average is %6.2f\n", thisAv);
}

float* readData(char* filename, int size){
    float* data = (float*)malloc(size * sizeof(float));
    FILE* file = fopen(filename, "r");

    float number;
    for (int i = 0; i < size; i++) { // read through the file
        fscanf(file, "%f", &number);
        data[i] = number; //set array to the costs
    }

    return data;
}

float get_average(float A[], int size){
    float total = 0;
    for (int i = 0; i < size; i ++ ){
        total = total + A[i];
    }
    return total/(float)size;
}