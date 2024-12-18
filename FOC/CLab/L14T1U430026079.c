/*
=============================================
 Name: L14T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: Dynamic Memory Allocation
 Lab 14 Task 1
 ============================================= 
*/
#include <stdio.h>
#include <stdlib.h>
struct stuRec{
    char name[20];
    int id; 
    char gender;
};
int main()
{
    struct stuRec *p;
    p = (struct stuRec*)malloc(sizeof(struct stuRec));
    if (p) {
        printf("please input name, id and gender\n");
        scanf("%s%d%*c%c", p->name, &p->id, &p->gender);
        printf("name:%10s,ID:%d,gender:%c\n", p->name,p->id,p->gender);
        free (p);
    }
    return 0;
}
/*
1: This program is supposed to read in a student record and display it.
2: The memory is dynamically allocated.
3: %*c is used to skip the space character between the input id and gender.
4: if %-10s is changed to %10s, there will be 10 spaces before the input name.
5: add a free() function to free the memory to prevent memory leak.
*/