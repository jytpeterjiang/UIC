/*
=============================================
 Name: L2T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 2 Task 1
 ============================================= 
*/
#include <stdio.h>
int main(){
    printf("Number of bytes used to store a char type variable is %d\n",sizeof(char));
    printf("Number of bytes used to store a short int type variable is %d\n",sizeof(short int));
    printf("Number of bytes used to store an int type variable is %d\n",sizeof(int));
    printf("Number of bytes used to store a float type variable is %d\n",sizeof(float));
    printf("Number of bytes used to store a long int type variable is %d\n",sizeof(long int));
    printf("Number of bytes used to store a double type variable is %d\n",sizeof(double));
    return 0;
}
