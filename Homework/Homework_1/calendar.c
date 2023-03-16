#include <stdio.h>

// Function prototypes
// You may modify these

int get_year_start(int);            // takes year, returns day that year starts on
void printCalendar(int, int);       // takes year and start day, prints 12 months
int printMonth(int, int, int);      // takes year, month and start day of month, prints 1 month, returns start of next month
int printMonthName(int, int);       // takes year and month number, prints header for that month, returns number of days in month

int main(void){
    int inputtedYear = 0;

    printf("Please enter year for this calendar:\n");
    scanf("%i", &inputtedYear);
    printf("***    CALENDAR for %d   ***", inputtedYear);
    printf("\n\n");

    printCalendar(inputtedYear, get_year_start(inputtedYear));

    return 0;
}

/********************************************************
*   get_year_start()
*   Determines the day of the week that the specified
*   year starts on. Uses current calendar rules (ignores calendar changes)
*   Input:
*       year: the year being studied
*   Returns:
*       The day of the week the year starts on
*       0: Sunday, 1: Monday, etc
*   Source:
*       https://stackoverflow.com/questions/478694/what-is-the-easiest-algorithm-to-find-the-day-of-week-of-day-zero-of-a-given-year
*********************************************************/
int get_year_start(int year){
    int year_start =  (((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400) + 1) % 7;
    return year_start;
}

/********************************************************
*   printCalendar(in year, int day)
*   Prints 1 year of a calendar
*   
*   Input:
*       year: the year being studied
*       day: the day of the week that the year starts on
*   Returns:
*       Nothing
*   Calls: printMonth
*********************************************************/
void printCalendar(int year, int day){
    int newStartDay = 0;
    for(int month = 0; month < 12; month++){
        printMonthName(year, month);
        printf("\n");

        if(month == 0){
            newStartDay = printMonth(year, month, day);
        } else{
            newStartDay = printMonth(year, month, newStartDay);
        }
        printf("\n\n");
    }
}

/********************************************************
*   printMonth(int year, int month, int start_day)
*   Prints 1 month of a calendar, returns the start of the next month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*       start_day: the day of the week that the month starts on
*   Returns:
*       The start day of the next month
*   Calls: printMonthName
*********************************************************/
int printMonth(int year, int month, int start_day){

    int daysInMonth = 0;
    switch(month){ // determine number of days in each month, accounting for leap year possibility
        case(0): daysInMonth = 31; break;
        case(1): 
            if((year % 400 == 0)) { // If its a leap year
                daysInMonth = 29;
            } else if(year % 100 == 0) {
                daysInMonth = 28;
            } else if(year % 4 == 0){
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case(2): daysInMonth = 31; break;
        case(3): daysInMonth = 30; break;
        case(4): daysInMonth = 31; break;
        case(5): daysInMonth = 30; break;
        case(6): daysInMonth = 31; break;
        case(7): daysInMonth = 31; break;
        case(8): daysInMonth = 30; break;
        case(9): daysInMonth = 31; break;
        case(10): daysInMonth = 30; break;
        case(11): daysInMonth = 31; break;
    }

    //Print out day header
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    //printing blanks for start of month
    for(int i = 0; i < start_day; i++){
        printf("     ");
    }
    
    int currentDay;
    if(start_day == 7){
        currentDay = 0;
    } else{
        currentDay = start_day;
    }

    for(int i = 1; i <= daysInMonth; i++){ //for every day in the month
        if(currentDay % 7 == 0 && (i != 1)){ // If its 7th day in week (no 0 index), move to new line
            printf("\n%5d", i);
            currentDay = 1;
        } else{
            printf("%5d", i);
            currentDay++;
        }
    }

    if(currentDay == 7){
        return 0;
    }

    return currentDay++;
}

/********************************************************
*   printMonthName(int year, int month)
*   prints header for the month, returns number of days in month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*   Returns:
*       The number of days in the month
*********************************************************/

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