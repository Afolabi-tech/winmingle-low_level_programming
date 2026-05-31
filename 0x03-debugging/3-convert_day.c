/**
 *Convert_day - converts day of the year to remaining days
 *@month: month
 *@day: day
 *
 *Return: day of the year
 */

int convert_day(int month, int day, int year)
{


     int days_in_month[] = {31, 28, 31, 30, 31, 30,
         31, 31, 30, 31, 30, 31};
     int i, day_of_year = 0;

     
    /* leap year check*/                                      
     if ((year % 4 == 0 && year % 100 != 0) ||                           (year % 400 == 0))                               
    
     {
       days_in_month[1] = 29;
     }


     for (i = 0; i < month - 1; i++)                              
     {

         day_of_year += days_in_month[i];           
     }                                                                                                                   
     day_of_year += day;
     
     return (day_of_year);

}
