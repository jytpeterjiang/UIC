/*
=============================================
 Name: L12T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: exchange 
 Lab 12 Task 1
 ============================================= 
*/
#include<stdio.h>
void exchange(int *x, int *y);// sent the pin in
int main()
{
    int a = 10, b = 20;
    printf("before exchange: a = %d, b = %d\n",a, b);
    exchange(&a, &b);
    printf("after exchange: a = %d, b = %d\n",a, b);
    return 0;
}
void exchange(int *x, int *y){
    int temp;// store *x
    temp = *x;
    *x = *y;// change *x to *y
    *y = temp;// cover *y by *x
}