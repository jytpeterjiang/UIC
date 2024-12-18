/*
=============================================
 Name: L14T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: Dynamic Memory Allocation
 Lab 14 Task 2
 ============================================= 
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Input the number of the data: ");
    int n;
    scanf("%d",&n);
    if (n < 0){
        printf("Warning! You should input a positive integer!");
        return 0;
    }
    printf("Input %d integer numbers: ",n);
    int *p = (int *)malloc(n*sizeof(int)); // apply n bytes of dynamic memory to store the numbers
    for (int i = 0;i<n;i++){
        scanf("%d",&p[i]);// store the number
    }
    printf("Numbers in reverse order are: ");
    for(int i = n-1;i>=0;i--){// print the numbers in reverse order
        printf("%d ",p[i]);
    }
    return 0;
}