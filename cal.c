#include<stdio.h>
#define TRUE 1
#define FALSE 0
int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[] =
{
    " ",
    "\n\n\n========================\n\n       January\n\n========================",
    "\n\n\n========================\n\n       February\n\n========================",
    "\n\n\n========================\n\n        March   \n\n========================",
    "\n\n\n========================\n\n        April    \n\n========================",
    "\n\n\n========================\n\n         May      \n\n========================",
    "\n\n\n========================\n\n         June      \n\n========================",
    "\n\n\n========================\n\n       July      \n\n========================",
    "\n\n\n========================\n\n       August\n\n========================",
    "\n\n\n========================\n\n       September\n\n========================",
    "\n\n\n========================\n\n       October\n\n========================",
    "\n\n\n========================\n\n       November\n\n========================",
    "\n\n\n========================\n\n       December\n\n========================",

};

int inputyear(void){
    int year;
    printf("Please enter a year like 2014: ");
    scanf("%d",&year);
    return year;
}
  int determineLeapyear(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){

   daysInMonth[2] = 29;
    return TRUE;

    }else{
      daysInMonth[2] = 28;
      return FALSE;
    }
  }
  int determinedaycode(int year){
    int daycode;
    int d1,d2,d3;
    d1 = (year-1)/4.0;
    d2 = (year-1)/100;
    d3 = (year-1)/400;

    daycode = (year+d1-d2+d3)%7;
    return daycode;
  }
  void calendar(int year, int daycode){
    int month,day;
    // loop of the months
    for(month=1; month<=12; month++){
     printf("%s", months[month]);
     printf("\n\n Sun Mon Tue Wed Thu Fri Sat\n");

     // correct the position for the first date 

     for(day =1; day<=1+daycode*5; day++){
      printf("  ");

      // print all dates for one month

      for(day=1; day<=daysInMonth[month]; day++){
        printf("%3d",day);

        // is day before sat, else start next line sun.

        if((day+daycode)%7 >0)
        printf(" ");
        else
        printf("\n"); 
      }

      // set position for next month

      daycode = (daycode+daysInMonth[month])%7;
     }
    }

  }
  int main(void){
    int year,daycode,leapyear;
    year = inputyear();
    daycode = determinedaycode(year);
    determineLeapyear(year);
    calendar(year,daycode);
    printf("\n");
  }