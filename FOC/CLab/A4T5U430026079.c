/*
=============================================
 Name: A4T5U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: read a binary file and print out the records
 Assignment 4 Task 5
 ============================================= 
*/
#include <stdio.h>

struct Student {
    char name[20];
    char ID[10];
    int score;
};
int main() {
    FILE *fp;
    fp = fopen("stuScore.bin", "rb");// open file by using binary mode
    if (fp == NULL) {
        printf("File open failed!\n");
        return 0;
    }
    struct Student stu[2];
    int i = 0;
    while (i < 2 && fread(&stu[i], sizeof(struct Student), 1, fp) == 1) {// read until the end of the file base on the size of the structure
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("%s %s %d\n", stu[j].name, stu[j].ID, stu[j].score);// print out the records
    }
    printf("Totally there are %d students' records in this file.\n", i);
    fclose(fp);// close the file
    return 0;
}