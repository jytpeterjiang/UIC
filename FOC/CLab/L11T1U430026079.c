/*
=============================================
 Name: L11T1U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: calculate the circumference of the triangle.
 Lab 11 Task 1
 =============================================
*/
#include <stdio.h>
#include <math.h>
struct Point {
    double x, y;
};
struct Triangle{
    struct Point p1,p2,p3;// nested structures
}t;
#define LINE_LENGTH(x1, x2, y1, y2) sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))// the length of the line
int main() {
    double l1, l2, l3;

    printf("Enter the coordinates of the 1st point: ");
    scanf("%lf, %lf", &t.p1.x, &t.p1.y);

    printf("Enter the coordinates of the 2nd point: ");
    scanf("%lf, %lf", &t.p2.x, &t.p2.y);

    printf("Enter the coordinates of the 3rd point: ");
    scanf("%lf, %lf", &t.p3.x, &t.p3.y);
    
    l1 = LINE_LENGTH(t.p1.x, t.p2.x, t.p1.y, t.p2.y);
    l2 = LINE_LENGTH(t.p1.x, t.p3.x, t.p1.y, t.p3.y);
    l3 = LINE_LENGTH(t.p2.x, t.p3.x, t.p2.y, t.p3.y);
    
    printf("the circumference of the triangle is %f.\n", l1 + l2 + l3);
    return 0;
}