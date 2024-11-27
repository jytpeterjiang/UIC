/*
=============================================
 Name: L4T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: The size of types
 Lab 4 Task 1
 ============================================= 
*/
#include <stdio.h>
int main() {
	int m, n;
	scanf("%d%d",&m,&n);
	printf("%d + %d = %d\n",m,n,m+n);
	printf("%d - %d = %d\n",m,n,m-n);
	printf("%d * %d = %d\n",m,n,m*n);
	printf("%d / %d = %d\n",m,n,m/n);
	printf("%d %% %d = %d\n",m,n,m%n);
	printf("float(%d) / %d = %f\n",m,n,(float)m/n);
	return 0;
}
