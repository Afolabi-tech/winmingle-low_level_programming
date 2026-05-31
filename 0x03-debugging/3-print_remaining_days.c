#include "main.h"

/**
 *print_remaining_days - prints how many days are left in the year.
 *@month: month
 *@day: day
 *@year: year
 *
 */

void print_remaining_days(int month, int day, int year)
{

    int day_of_year;
    int leap_year = 0;

    if ((year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0))
    {

        leap_year = 1;
    }


    day_of_year = convert_day(month, day, year);

    printf("Date: %02d/%02d/%d\n", month, day, year);

    printf("Day of the year: %d\n", day_of_year);

    printf("Remaining days: %d\n", 
            (365 + leap_year) - day_of_year);

}


