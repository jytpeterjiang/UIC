/*
=============================================
 Name: L3T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 3 Task 3
 ============================================= 
*/
#include <stdio.h>
int main() {
    int percentage, x;
    char ch1, ch2;
    scanf("%d%c%c%d", &percentage, &ch1, &ch2, &x);
    printf("%d%% %c%c %d is %f\n", percentage, ch1, ch2, x, 1.0*x*percentage/100); 
    return 0;
}
/* 
Put outputs and explanations here.
1. 10of100: The output is "10% of 100 is 10.000000", because percentage=10, ch1=o, ch2=f, x=100;
2. 10 of100: The output is "10%  o 407 is 40.700000", because percentage=10, ch1=' ', ch2=o, x=random number;
As for my pelles C, if I don't initialize x with a exact number, it will initialize x with a random number and continue operating. 
3. 10 of 100: The output is "10%  o 645 is 64.500000", because percentage=10, ch1=' ', ch2=o, x=random number;
As for my pelles C, if I don't initialize x with a exact number, it will initialize x with a random number and continue operating.
*/
