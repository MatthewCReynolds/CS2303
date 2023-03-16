#include <stdio.h>

// function prototypes
int printMonthName(int, int);

int main(void){

    int year = 2024;
    int num_days;
    // loop over all months
    for (int i = 0; i < 12; i ++){
        // call printMonthName for each month
        num_days = printMonthName(year, i);
        printf("This month has %d days\n", num_days);
    }
    return 0;
}

/*********************************************************************
* int printMonthName(int year, int month)
*
* Prints the month name and year to the terminal 
*
* Input:
*	year: the year being printed
*	month: the month to be printed (0 indexed)
*
* Returns: The number of days in this month
*
* Output: Prints the month name and year to the terminal
*
*********************************************************************/	
int printMonthName(int year, int month){
    int days = 0;

    switch(month){
        case(0): printf("%s", "January"); days = 31; break;
        case(1): printf("%s", "February");
            if((year % 400 == 0)) { // If its a leap year
                days = 29;
            } else if(year % 100 == 0) {
                days = 28;
            } else if(year % 4 == 0){
                days = 29;
            } else {
                days = 28;
            }
            break;
        case(2): printf("%s", "March"); days = 31; break;
        case(3): printf("%s", "April"); days = 30; break;
        case(4): printf("%s", "May"); days = 31; break;
        case(5): printf("%s", "June"); days = 30; break;
        case(6): printf("%s", "July"); days = 31; break;
        case(7): printf("%s", "August"); days = 31; break;
        case(8): printf("%s", "September"); days = 30; break;
        case(9): printf("%s", "October"); days = 31; break;
        case(10): printf("%s", "November"); days = 30; break;
        case(11): printf("%s", "December"); days = 31; break;
    }

    printf(" %d\n", year);

    return days;
}
