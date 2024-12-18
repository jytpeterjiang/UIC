/*
=============================================
 Name: L13T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: file
 Lab 13 Task 3
 ============================================= 
*/
#include<stdio.h>
#include<string.h>

int main()
{
	FILE *n;
	n = fopen("sample.bin","r+");
	if (n == NULL){
		return 0;
	}
	
	float num1,num2;
	fseek(n,sizeof(float)*4,SEEK_SET);
	fread(&num1,sizeof(float),1,n);

	fseek(n,sizeof(float)*6,SEEK_SET);
	fread(&num2,sizeof(float),1,n);

	printf("num1 is %f\n",num1);
	printf("num2 is %f\n",num2);
    return 0;
}