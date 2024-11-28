/*
=============================================
 Name: L8T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: judge if an inputted char is a digit
 Lab 8 Task 4
 =============================================
*/
#include "digit.h"
#include<stdio.h>
int main(){
    char a;
    printf("Enter a character: ");
    scanf("%c",&a);
    printf("%d\n",isDigitChar(a));
	return 0;
}
