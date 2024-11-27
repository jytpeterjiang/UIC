/*
=============================================
 Name: L3T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 3 Task 1
 ============================================= 
*/
#include <stdio.h>
int main() {
  float value1, value2, sum;
  value1 = 15;
  value2 = 30;
  sum = value1 + value2;
  printf("The sum of %.2f and %f is %f\n", value1, value2, sum);
  return 0;
} 
/* 
Put your outputs here.
1.The sum of 15 and 30 is 45
2.The sum of 0 and 0 is 0
3.The sum of 15.000000 and 30.000000 is 45.000000
4.The sum of 15.00 and 30.000000 is 45.000000
*/
