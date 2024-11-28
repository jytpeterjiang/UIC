/*
=============================================
 Name: L11T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: enum
 Lab 11 Task 4
 ============================================= 
*/
#include<stdio.h>
enum year{Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
int main()
{
    int i;
    for (i=Jan; i<=Dec; i++)     
        printf("%d ", i);
    return 0;
}
/*
Original output: 0 1 2 3 4 5 6 7 8 9 10 11
enum default starts from 0, and add one to the next element
so we just need to change Jan = 1 and get the correct output
*/