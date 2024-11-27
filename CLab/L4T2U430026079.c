/*
=============================================
 Name: L4T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 4 Task 2
 ============================================= 
*/
#include <stdio.h>
#define square_sum(a,b) (a*a+b*b);
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	int square_sum = square_sum(a,b);
	printf("Square sum is %d\n",square_sum);
	return 0;
}
