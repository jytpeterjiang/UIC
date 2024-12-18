/*
=============================================
 Name: A4T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: check sub-string and add a string
 Assignment 4 Task 2
 ============================================= 
*/
#include <stdio.h>
#include <string.h>
int main(){
	char str1[100],str2[50];
	printf("Enter the first string: ");
	gets(str1);// use gets to read the input string with space 
	printf("Enter the second string: ");
	gets(str2);
	if(strstr(str1,str2) == NULL){// use strstr to check whether str2 is a sub-string in str1
		strcat(str1,str2);// add str2 to str1
		printf("After appending, str1 is: %s",str1);
	}else{
		printf("No need to append, str1 is: %s",str1);
	}
	return 0;
}