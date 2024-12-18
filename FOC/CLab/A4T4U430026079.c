/*
=============================================
 Name: A4T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: reverse order
 Assignment 4 Task 4
 ============================================= 
*/
#include <stdio.h>
int main(){
	int num[5];
	printf("Input data: ");
	for(int i = 0;i<5;i++){
		scanf("%d",&num[i]);
	}
	int *p = num;// point to the first element
	printf("Reversed data: ");
	for(int i = 5;i>0;i--){
		printf("%d ",*(p+i-1));// output the value of the pointer
	}
	return 0;
}