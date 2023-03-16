#include <stdio.h>
#include "functions.h"

int main(void){

    float returnedF;
    int programInput, itemNumber, returned = 0;
    char AppendOverwrite[10];
    char fileName[50];
    

    printf("Which program would you like to run: (1) Calculate overall revenue, (2) Calculate register balance, or (3) Calculate sales for an item.\n");
    scanf("%i", &programInput);

    printf("Please enter an input file:\n");
    scanf("%s", fileName);
    FILE *inputFile = fopen(fileName, "r");
    
    switch(programInput){
        case(1): returnedF = overall_revenue(inputFile); printf("%.2f\n", returnedF); break;
        case(2): returnedF = balance(inputFile); printf("%.2f\n", returnedF); break;
        case(3): 
            printf("Which item to analyze?\n");
            scanf("%i", &itemNumber);

            printf("What is the output file?\n");
            scanf("%s", fileName);

            printf("Enter A for Append or O for over-write.\n");
            scanf("%s", AppendOverwrite);

            if(*AppendOverwrite == 'A'){
                returned = tally(inputFile, itemNumber);
                FILE *outputFile = fopen(fileName, "a");
                fprintf(outputFile, "%3d%4d\n", itemNumber, returned);
            } else if(*AppendOverwrite == 'O'){
                FILE *outputFile = fopen(fileName, "w");
                returned = tally(inputFile, itemNumber);
                fprintf(outputFile, "%3d%4d\n", itemNumber, returned);
                
            } else{
                printf("This option is not valid.\n"); break;
            }
            

            break;
        default: printf("This option is not valid.\n"); break;
    }
    

    return 0;
}