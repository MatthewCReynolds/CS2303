#include <stdio.h>
#include <stdlib.h>

/********************************************************
*   get_totals(int array[51][7])
*       given a 50x6 (0 index) array, it will compute each items sales in that 6 month period
*       prints out each item id and sales over that period to a file called Total_sales.txt
*   
*   Input:
*       int array[51][7]
*   Returns:
*       void
*********************************************************/
void get_totals(int rows, int cols, int array[][cols]){
    FILE *outputFile = fopen("Total_sales.txt", "w");
    int sums[rows]; //new Array filled with 0s
    for (int i = 0; i < rows; i++){
        sums[i] = 0;
    }

    for(int i = 0; i < rows; i++){ //for every item
        int sum = 0;
        for(int j = 1; j < cols; j++){ //for all months
            sum += array[i][j]; //sum up the numbers in every month
        }
        sums[i] = sum; //set the column equal to the sum
    }

    for(int i = 1; i < rows; i++){
        fprintf(outputFile, "%4d%7d\n", i, sums[i]); //otherwise say the id and the sum
    }

    fclose(outputFile); //Close output file
}

/********************************************************
*   get_profits(int array[51][7], float money[51][2])
*       given the two arrays, it will calculate and print out the appropriate file called "Profits.txt". It prints
*       ItemID, NumberOfSales, Sales, Cost, and Revenue in the properly formatted way
*   
*   Input:
*       int array[51][7], float array[51][2]
*   Returns:
*       void
*********************************************************/
void get_profits(int rows, int cols, int array[rows][cols], float money[rows][2]){
    FILE *outputFile = fopen("Profits.txt", "w");
    int sums[rows]; //new Array filled with 0s
    for (int i = 0; i < rows; i++){
        sums[i] = 0;
    }

    for(int i = 0; i < rows; i++){ //for every item
        int sum = 0;
        for(int j = 1; j < cols; j++){ //for all months
            sum += array[i][j]; //sum up the numbers in every month
        }
        sums[i] = sum; //set the column equal to the sum
    }

    fprintf(outputFile, "%8s%8s%8s%8s%8s\n", "Item", "#", "Sales", "Cost", "Revenue");
    for(int i = 0; i < rows; i++){
        float sales = sums[i]*money[i][0]; //calulate sales
        float cost = sums[i]*money[i][1]; //calculate cost
        float revenue = (money[i][1] - money[i][0]) * -1 * sums[i]; //calculate revenue

       if(i > 0) {
            if(sums[i] == 0){ //if there's no sales, mark it all as 0
                fprintf(outputFile, "%8d%8d%8.2f%8.2f%8.2f\n", i, 0, 0.0, 0.0, 0.0); 
            } else { //otherwise, mark it all
                fprintf(outputFile, "%8d%8d%8.2f%8.2f%8.2f\n", i, sums[i], sales, cost, revenue); 
            }
        }
    }


    fclose(outputFile); //Close file
}

/********************************************************
*   get_profits(int array[51][7], float money[51][2])
*       given the two arrays, it will calculate and print out the appropriate file called "Top_earners.txt". It prints
*       ItemID, NumberOfSales, and Revenue in the properly formatted way
*   
*   Input:
*       int array[51][7], float array[51][2]
*   Returns:
*       void
*********************************************************/
void top_earner(int rows, int cols, int array[rows][cols], float money[rows][cols]){
    FILE *outputFile = fopen("Top_earners.txt", "w");
    int sums[rows]; //new Array filled with 0s
    for (int i = 0; i < rows; i++){
        sums[i] = 0;
    }

    for(int i = 0; i < rows; i++){ //for every item
        int sum = 0;
        for(int j = 1; j < cols; j++){ //for all months
            sum += array[i][j]; //sum up the numbers in every month
        }
        sums[i] = sum; //set the column equal to the sum
    }

    fprintf(outputFile, "%4s%4s%9s\n", "Item", "#", "Revenue");
    for(int i = 0; i < 10; i++){
        float currentMax = 0;
        int index = 0;

        for(int j = 0; j < rows; j++){ //Finding the highest amount
            float revenue = (money[j][1] - money[j][0]) * -1 * sums[j];

            if (revenue > currentMax){ //If it's bigger
                currentMax = revenue;
                index = j;
            }
        }

        
        fprintf(outputFile, "%4d%4d%9.2f\n", index, sums[index], currentMax); //print it out
        sums[index] = 0; //So the next time it goes through it doesnt pick up the same value
    }

    fclose(outputFile); //Close file
}

/********************************************************
*   readCosts(int numItems)
*       given a Costs.txt file and the number of items its supposed to readd
*   
*   Input:
*       int numItems
*   Returns:
*       1x? array of the num of Costs
*********************************************************/
float* readCosts(int numItems) {
    float* costs = (float*)malloc(numItems * sizeof(float));
    FILE* file = fopen("costs.txt", "r");

    int item;
    float salesCost, purchaseCost; // declare variables
    for (int i = 0; i < numItems; i++) { // read through the file
        fscanf(file, "%d %f %f", &item, &salesCost, &purchaseCost);
        costs[i] = salesCost; //set array to the costs
    }

    fclose(file); //close file
    return costs; //return array
}

/********************************************************
*   readPurch(int numItems)
*       given a Costs.txt file and the number of items its supposed to readd
*   
*   Input:
*       int numItems
*   Returns:
*       1x? array of the num of Costs
*********************************************************/
float* readPurch(int numItems) {
    float* purchaseCosts = (float*)malloc(numItems * sizeof(float));
    FILE* fp = fopen("Costs.txt", "r");

    int itemCode;
    float salesCost, purchaseCost; // declaring new variables
    int i = 0;
    while (fscanf(fp, "%d %f %f", &itemCode, &salesCost, &purchaseCost) > 0) { //scanning out the puchase cost
        purchaseCosts[i++] = purchaseCost;
    }

    fclose(fp); //close file

    return purchaseCosts; // return array
}