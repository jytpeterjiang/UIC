/*
=============================================
 Name: A4T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: calculate the total days until the input date in this year
 Assignment 4 Task 3
 ============================================= 
*/
#include <stdio.h>
struct input_date{// use structure type
	int year;
	int month;
	int day;
}date;
int main(){
	printf("Input date: ");
	scanf("%d %d %d",&date.year,&date.month,&date.day);
	int com_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};// set the days of the months in common year
	if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)){// check if the input year is leap year
		com_month[1] = 29; // if the input year is leap year, change the days in February into 29
	}
	int month_day = 0;
	for(int i = 0;i<date.month-1;i++){// first calculate the total days before the input month
		month_day += com_month[i];
	}
	printf("The total days in this year until the input date: %d\n",month_day+date.day);// add the input days and the total days before
	return 0;
}