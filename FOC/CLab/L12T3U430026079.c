/*
=============================================
 Name: L12T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: pointers
 Lab 12 Task 3
 ============================================= 
*/
#include <stdio.h>
void stringCombine(char* dest, char* src);
int main()
{
    char str1[256], str2[256];
    gets(str1);
    gets(str2);
    stringCombine(str1, str2);
    puts(str1);
    return 0;
}
void stringCombine(char *dest, char *src){
	while(*dest != '\0'){
		dest++;
	}
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}