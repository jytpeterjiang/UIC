/*
=============================================
 Name: L4T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 4 Task 3
 ============================================= 
*/
#include <stdio.h>
int main (){
    int x = 50, y = 25;
    int temp1, temp2;
    temp1 = x/++y;
    printf("temp1= %d\ty= %d\n", temp1, y);
    y=25;
    temp2 = x/y++;
    printf("temp2= %7d\ty= %d\n", temp2, y);
    return 0;
}
/* 
Output of
(1)	%7d: 
temp1= 1        y= 26
temp2=       2  y= 26
(2)	%-7d:
temp1= 1        y= 26
temp2= 2        y= 26
Explanation: 
(1)	difference between temp1 and temp2:
For temp1 = x/++y: 
First, y will be added by 1 and y = 26.
Second, x is divided by y equals 1, so temp1 = 1.
For temp2 = x/y++:
First, x is divided by y equals 2.
Second, y is added by 1.
Finally, temp2 = 2.
(2)	difference between %7d and %-7d:
%7d produces right-aligned 7 characters output.
%-7d produces left-aligned 7 characters output.
*/
