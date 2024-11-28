/*
=============================================
 Name: L3T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 3 Task 4
 ============================================= 
*/
#include<stdio.h>
int main(){
    int i;
	float j;
    char ch;
    scanf("%d %f %c", &i, &j, &ch);
    printf("%d is the ASCII code of '%c'.\n",ch,ch);
    printf("The value of i is %d.\n", i);
    printf("The value of j is %.1f.\n", j);
    return 0;
}
