/*
=============================================
 Name: L4T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 4 Task 4
 ============================================= 
*/
#include <stdio.h>
int main (){
	int i = 10, j = 5;
	float x = 5.0, y;
	//I use printf("%f",y) to output the value of y
	//y = x / i; y = 0.500000; x is float and i is integer, so y is float and y = 0.500000;
	//y = j / i; y = 0.000000; j is integer and i is integer, so y is integer and y = 0;
	y = (float)j / i; //y = 0.500000; we change the result of j / i into a float type, so y = 0.500000;
}
