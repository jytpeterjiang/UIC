/*
=============================================
 Name: L7T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 7 Task 2
 =============================================
*/
#include <stdio.h>
int main()
{
    int n=0;
    int arr[50];
    int x;
    printf("Please input a sequence of integers (end with -1): ");
    for(int i = 0;i < 50;i++) {
        scanf("%d",&x);
        if(x == -1){
            break;
        }
        arr[n++] = x;
    }
    if(n == 0) {
        printf("Array is empty.\n");
        return 0;
    }
    printf("Enter the number you want to search: ");
    scanf("%d" , &x);
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == x) {
            printf("The index of %d in the array is %d.\n" , x , i);
            return 0;
        }
    }
    printf("%d Not found.\n" , x);
    return 0;
}
