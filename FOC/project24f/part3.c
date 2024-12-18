
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ������ҽṹ��
typedef struct Classroom {
    int id;
    int size;
    int isAvailable[9];  // ���ڼ�¼ÿ��ʱ��εĿ����ԣ�9��ʱ��ζ�Ӧ9��Ԫ��
    char reservedBy[9][50];  // ��¼Ԥ��ÿ��ʱ��ε��û���
} Classroom;

// �����˻��ṹ��
typedef struct Account {
    char username[50];
    char password[50];
} Account;

// ȫ�ֱ������洢���Һ��˻���Ϣ
Classroom classrooms[100];  // �������100������
Account accounts[100];  // �������100���˻�
int numClassrooms = 0;
int numAccounts = 0;

// ��������
void loadAccounts();
void loadClassrooms();
void saveClassroomStatus(Classroom *classroom);
void displayAvailableSlots(int option);
int findAvailableClassroom(int size);

int main() {
    loadAccounts();
    loadClassrooms();

    // �����Ѿ���ɵ�¼��ֱ�ӽ���ѡ��ʱ������̣��������ѡ����죨�ɸ���ʵ������޸ģ�
    displayAvailableSlots(1);

    return 0;
}

// ���ļ������˻���Ϣ
void loadAccounts() {
    FILE *fp;
    fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("�޷����˻��ļ���\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", accounts[numAccounts].username, accounts[numAccounts].password) == 2) {
        numAccounts++;
    }

    fclose(fp);
}

// ���ļ����ؽ�����Ϣ����ʼ��������
void loadClassrooms() {
    FILE *fp;
    fp = fopen("classroom_info.txt", "r");
    if (fp == NULL) {
        printf("�޷��򿪽�����Ϣ�ļ���\n");
        exit(1);
    }

    while (fscanf(fp, "%*s %d", &classrooms[numClassrooms].size) == 1) {
        classrooms[numClassrooms].id = numClassrooms + 1;
        for (int i = 0; i < 9; i++) {
            classrooms[numClassrooms].isAvailable[i] = 1;  // ��ʼ��Ϊ����
            classrooms[numClassrooms].reservedBy[i][0] = '\0';  // ��ʼ��Ԥ���û���Ϊ���ַ���
        }
        numClassrooms++;
    }

    fclose(fp);
}

// �������Ԥ��״̬���ļ�
void saveClassroomStatus(Classroom *classroom) {
    char filename[10];
    sprintf(filename, "C%d.txt", classroom->id);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("�޷��򿪽���״̬�ļ���\n");
        exit(1);
    }

    for (int i = 0; i < 9; i++) {
        fprintf(fp, "%d %s\n", classroom->isAvailable[i], classroom->reservedBy[i]);
    }

    fclose(fp);
}

// ��ʾ����ʱ���
void displayAvailableSlots(int option) {
    int currentHour, currentMinute;
    time_t current_time;
    struct tm *tblock;

    time(&current_time);
    tblock = localtime(&current_time);

    currentHour = tblock->tm_hour;
    currentMinute = tblock->tm_min;

    printf("\n===== ��Ԥ��ʱ��� =====\n");
    for (int i = 0; i < 9; i++) {
        int startHour = 9 + i;
        if (option == 1 && (startHour < currentHour || (startHour == currentHour && 0 <= currentMinute && currentMinute < 50))) {
            continue;  // ����ǽ�����ʱ����ѹ�������ʾ
        }
        printf("%d. %02d:00 - %02d:50\n", i + 1, startHour, startHour);
    }
    printf("��ѡ��: \n");
	printf("�˳��밴9");

    int slot;
    scanf("%d", &slot);

    if (slot >= 1 && slot <= 8) {
        // ���������Ѿ���ȡ�����û������Ԥ�ڽ��Ҵ�С��ʵ��Ӧ���û������ȡ������Ϊ�򻯴���ֱ�Ӽ���Ϊ30�����޸ģ�
        int size = 30;
        int classroomIndex = findAvailableClassroom(size);
        if (classroomIndex == -1) {
            printf("û�п��õĽ��ң�\n");
        } else {
            Classroom *selectedClassroom = &classrooms[classroomIndex];
            selectedClassroom->isAvailable[slot - 1] = 0;  // ���ø�ʱ���Ϊ������
            // ���赱ǰ��¼�û�Ϊ��һ���˻��û���ʵ��Ӧ���ݵ�¼����޸�
            strcpy(selectedClassroom->reservedBy[slot - 1], accounts[0].username);

            printf("���ѳɹ�Ԥ������ %d��ʱ���Ϊ��%02d:00 - %02d:50\n", selectedClassroom->id, 9 + slot - 1, 9 + slot - 1);

            saveClassroomStatus(selectedClassroom);
        }
    } else if (slot == 9) {
        // �������ӷ�����һ���˵����˳�ϵͳ���߼���Ϊ�򻯴�����ʱ��ʵ��
        printf("�˳�ѡ��ʱ��Ρ�\n");
    } else {
        printf("��Ч��ѡ�����������롣\n");
        displayAvailableSlots(option);
    }
}

// ���ҿ��ý���
int findAvailableClassroom(int size) {
    for (int i = 0; i < numClassrooms; i++) {
        if (classrooms[i].size >= size && classrooms[i].isAvailable[0]) {  // �����Ȳ��ҵ�һ��ʱ��ο��õĽ��ң�ʵ�ʿɸ����������
            return i;
        }
    }
    return -1;
}

