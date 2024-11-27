/*
=============================================
 Name: A3T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: operator
 Assignment 3 Task 2
 =============================================
*/
#include "operator.h"
#include <stdio.h>
int main()
{
	int num1,num2,ans;
	char op;
	printf("Enter an expression: ");
	scanf("%d%c%d",&num1,&op,&num2);
	ans = calculate(num1,op,num2);
	if (ans == 0){
		printf("Warning: Invalid operator.\n");
	}else{
		printf("%d%c%d=%d\n",num1,op,num2,ans);
	}
	return 0;
}
