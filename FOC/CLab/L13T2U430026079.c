/*
=============================================
 Name: L13T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: file
 Lab 13 Task 2
 ============================================= 
*/
#include<stdio.h>
#include<string.h>

int fileCombine(char *destFileName, char *resFileName){
	FILE *res,*dest;
	char str[256];
	res = fopen(resFileName,"r");
	dest = fopen(destFileName,"a");
	if (res == NULL || dest == NULL){
		return 0;
	}
	fputs("\n",dest);
	while(fgets(str, sizeof(str), res) != NULL){
		fputs(str, dest);
	}
	fclose(res);
	fclose(dest);
	return 1;
}

int main()
{
	char fileName1[20], fileName2[20];
    int flag;
	strcpy(fileName1, "a.txt");
    strcpy(fileName2, "b.txt");
    flag = fileCombine(fileName2, fileName1);
    if (flag == 1) 
        printf("Success"); 
    else 
        printf ("Failure");
    return 0;
}