#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义教室的结构体
typedef struct {
    char id[10];
    int size;
} Classroom;

// 函数声明
void loadClassrooms(Classroom** classrooms, int* count);
int findAvailableClassroom(Classroom* classrooms, int count, int size);
void continuePrompt();

int main() {
    Classroom* classrooms = NULL;
    int classroomCount = 0;

    loadClassrooms(&classrooms, &classroomCount);

    int size;
    while (1) {
        printf("Input the size of classroom: ");
        scanf("%d", &size);

        int index = findAvailableClassroom(classrooms, classroomCount, size);
        if (index != -1) {
            printf("Available classroom: %s\n", classrooms[index].id);
        } else {
            printf("No available room!\n");
        }

        continuePrompt();
    }

    // 释放内存
    free(classrooms);
    return 0;
}

// 从文件加载教室信息
void loadClassrooms(Classroom** classrooms, int* count) {
    FILE* file = fopen("classroom_info.txt", "r");
    if (!file) {
        perror("Failed to open classroom_info.txt");
        exit(1);
    }

    // 计算教室数量
    char buffer[50];
    while (fgets(buffer, 50, file)) {
        (*count)++;
    }
    rewind(file);

    // 动态分配内存
    *classrooms = (Classroom*)malloc(sizeof(Classroom) * (*count));
    if (!*classrooms) {
        perror("Failed to allocate memory");
        exit(1);
    }

    // 读取教室数据
    for (int i = 0; i < *count; i++) {
        fscanf(file, "%s %d", (*classrooms)[i].id, &(*classrooms)[i].size);
    }
    fclose(file);
}

// 查找可用的教室
int findAvailableClassroom(Classroom* classrooms, int count, int size) {
    for (int i = 0; i < count; i++) {
        if (classrooms[i].size >= size) {
            return i;
        }
    }
    return -1;
}

// 继续提示
void continuePrompt() {
    char choice;
    printf("Continue (y/n)? ");
    scanf(" %c", &choice);

    if (choice == 'n' || choice == 'N') {
        printf("Exiting...\n");
        exit(0);
    }
}