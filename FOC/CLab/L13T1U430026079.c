/*
=============================================
 Name: L13T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: file
 Lab 13 Task 1
 ============================================= 
*/
#include<stdio.h>
#include<string.h>

int fileCopy(char *destFileName, char *resFileName){
	FILE *res,*dest;
	char str[256];
	res = fopen(resFileName,"r+");
	dest = fopen(destFileName,"r+");
	if (res == NULL || dest == NULL){
		return 0;
	}
	while(fgets(str,256,res) != NULL){
		fputs(str,dest);
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
    flag = fileCopy(fileName2, fileName1);
    if (flag == 1) 
        printf("Success"); 
    else 
        printf ("Failure");
    return 0;
}