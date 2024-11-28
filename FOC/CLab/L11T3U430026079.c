/*
=============================================
 Name: L11T3U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: year, month and day
 Lab 11 Task 3
 ============================================= 
*/
#include <stdio.h>
#include <string.h>
struct students {
    char name[100];
    int score;
    char major[100];
};

int main() {
    int n;
    printf("Input the number of students: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Warning! Student number should be positive.\n");
        return 0;
    }

    struct students stu[n];
    printf("Please input students' information:\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", stu[i].name, &stu[i].score, stu[i].major);
    }

    // Use bubble sort to sort list by name
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(stu[j].name,stu[j + 1].name) > 0) {
                // swap
                struct students temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    printf("The student list in ascending order by name is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %s\n", stu[i].name, stu[i].score, stu[i].major);
    }

    return 0;
}