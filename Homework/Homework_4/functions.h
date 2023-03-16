//function headers
#include <stdio.h>

void get_totals(int rows, int cols, int array[][cols]);
void get_profits(int rows, int cols, int array[rows][cols], float money[rows][2]);
void top_earner(int rows, int cols, int array[rows][cols], float money[rows][2]);
float* readCosts(int);
float* readPurch(int);