/*
=============================================
 Name: A4T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: read a string
 Assignment 4 Task 1
 ============================================= 
*/
#include <stdio.h>
#include <string.h>
int main(){
	char str1[50],str2[1],str3[50];
	str3[0] == '\0';// initialize str3 with '\0'
	printf("Input: ");
	scanf("%s %s",str1,str2);
	for(int i = 0;i<strlen(str1);i++){
		if (str1[i] != str2[0]){
			strncat(str3,&str1[i],1);// use strncat to add character in str3
		}
	}
	printf("Output: %s",str3);
	return 0;
}