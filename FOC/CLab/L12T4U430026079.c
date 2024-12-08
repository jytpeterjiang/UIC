/*
=============================================
 Name: L12T4U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: pointers
 Lab 12 Task 4
 ============================================= 
*/
//sum.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int i, sum = 0;
	for (i = 1; i < argc; i++){
		sum = sum + atoi(argv[i]);
		printf("The sum is %d\n",sum);
	}
	return 0;
}