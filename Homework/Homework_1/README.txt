Author:
    Matthew Reynolds. I didn't have any help outside of the provided code from the original file.

Purpose:
    calendar.c prints out a text calendar of the year provided.

How the code works:
    Starting in the main block the code takes in the user's year, then it jumps to the printcalendar() function inputting
    the year starting date from getyearstart(). Then it launches into a for loop which runs for every month of the year
    it uses printMonthName to print out the Month and Year header. then if its the first month, it uses the calculated
    first day of the week, if its not it uses the previous months end + 1 day. Then it calls printMonth(), which calculates
    the days in the month, prints the day header, then starts a for loop for 1 to the months duration, every time it hits
    sunday it /n new lines. Then it returns the day the month ended on.


How to Run:
    cd "/Users/matthewreynolds/Library/CloudStorage/OneDrive-severnschool.com/University/Computer Science/CS 2303/Homework/Homework_1"
    ./"calendar"

Compile Command:
    gcc -Wall calendar.c

Run Command:
    ./a.out
    ./a.exe
