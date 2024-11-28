/*
=============================================
 Name: L4T5U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 4 Task 5
 ============================================= 
*/
#include <stdio.h>
int main (){
	int m, n;
	scanf("%d%d",&m,&n);
	printf("Integer: %d divided by %d is %d\n",m,n,m/n);
	printf("Float: %d divided by %d is %.2f\n",m,n,(float)m/(float)n);
	return 0;
}
