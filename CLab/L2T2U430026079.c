/*
=============================================
 Name: L2T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 2 Task 2
 ============================================= 
*/
#include <stdio.h>
int main (){
    short int x, y, z;
    x = 32767;
    y = 3;
    z = x + y;
    printf("%d + %d = %d\n", x, y, x + y); //print x+y
    printf("%d + %d = %d\n", x, y, z); //print z
    return 0;
}

/* 
For line 1, the output is 32770, which is right. However, the line 2 is -32766, which is "wrong".
First, the short type only have 2 bytes(16 bits), ranging from -32768 to 32767.
So if I need to output the right answer of x+y(32770), I need to change its range to a bigger range like "int".
In here, I use %d to change x,y and x+y to "int" type. So it can output the right answer "32770".
But for z = x + y, z keeps its "short" type until output. So z keeps operating normally, which is out of the range of "short".
So it is overflowing. The computer will strictly output the answer within the range of "short".
As 32767+3 in binary, it will become negetive number -32766. So it output -32766.
That's my explanation of this program. Thanks for your reading!
*/
