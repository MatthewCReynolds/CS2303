#include <stdio.h>

/********************************************************
*   overall_revenue(FILE *f1)
*       calculates the revenue, the sum - starting
*   
*   Input:
*       file: the file
*   Returns:
*       float for total revenue
*********************************************************/
float overall_revenue(FILE *f1){
    float itemNum = 0;
    float itemCost = 0;
    float totalRev = 0;


    while(fscanf(f1, "%f", &itemNum) == 1 && fscanf(f1, "%f", &itemCost) == 1){ // keeps going while there are more numbers to read
        //printf("%.2f, %.2f\n", itemNum, itemCost);
        if(itemNum != 0){
            totalRev += itemCost;
        }
    }
    return totalRev;

}

/********************************************************
*   balance(FILE *f1)
*       calculates the balance at that time
*   
*   Input:
*       file: the file
*   Returns:
*       float for the balance
*********************************************************/
float balance(FILE *f1){
    float shopBal = 0;
    float itemNum = 0;
    float itemCost = 0;

    while(fscanf(f1, "%f", &itemNum) == 1 && fscanf(f1, "%f", &itemCost) == 1){ // keeps going while there are more numbers to read
        //printf("%.2f, %.2f\n", itemNum, itemCost);
            shopBal += itemCost;
    }
    
    return shopBal;
}

/********************************************************
*   tally(FILE *f1, int item, char AorO, char[] name)
*   calculates number of times an item appears and its total value of sales
*   
*   Input:
*       file: the file
*       item: what item we're looking for
*       AorO: append or overwrite, A for append O for overwrite
*       name: name of file
*   Returns:
*       int for num of things sold
*********************************************************/
int tally(FILE *f1, int item){
    float itemNum = 0;
    float itemCost = 0;
    int numSold = 0;
    float itemRev = 0;

    while(fscanf(f1, "%f", &itemNum) == 1 && fscanf(f1, "%f", &itemCost) == 1){ // keeps going while there are more numbers to read
        //printf("%.2f, %.2f\n", itemNum, itemCost);
        if(itemNum == item){
            numSold++;
            itemRev += itemCost;
        }
    }

    return numSold;
}