#include <stdio.h>
#include <time.h>

// ��������
void displayMenuDates();
void printDateOptions(const char* today, const char* tomorrow, const char* dayAfterTomorrow);
void handleDateSelection(int choice, const char* today, const char* tomorrow, const char* dayAfterTomorrow);

int main() {
    int choice;

    // ��ʾ���ڲ˵�
    char today[11], tomorrow[11], dayAfterTomorrow[11];
    displayMenuDates(today, tomorrow, dayAfterTomorrow);

    // ��ʾ�û�����ѡ��
    printf("���������ѡ�� (1-3 ѡ�����ڣ�4 �˳�): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        // ��������ѡ��
        handleDateSelection(choice, today, tomorrow, dayAfterTomorrow);
        
        // ���ʱ���ѡ����ʾ
        printf("��������ѡ��ʱ���:\n");
    } else if (choice == 4) {
        printf("�˳�Ԥ��ϵͳ��\n");
    } else {
        printf("��Ч��ѡ�������ԡ�\n");
    }

    return 0;
}

// ��ʾ���ڲ˵��ĺ���
void displayMenuDates(char* today, char* tomorrow, char* dayAfterTomorrow) {
    time_t currentTime;
    struct tm *localTime;

    // ��ȡ��ǰʱ��
    time(&currentTime);
    localTime = localtime(&currentTime);

    // ��ȡ���������
    strftime(today, 11, "%Y.%m.%d", localTime);

    // ��ȡ���������
    localTime->tm_mday += 1;
    mktime(localTime); // ��������
    strftime(tomorrow, 11, "%Y.%m.%d", localTime);

    // ��ȡ���������
    localTime->tm_mday += 1;
    mktime(localTime); // ��������
    strftime(dayAfterTomorrow, 11, "%Y.%m.%d", localTime);

    // ��ӡ����ѡ��
    printDateOptions(today, tomorrow, dayAfterTomorrow);
}

// ��ӡ�˵�ѡ��ĺ���
void printDateOptions(const char* today, const char* tomorrow, const char* dayAfterTomorrow) {
    printf("��ѡ������:\n");
    printf("1. Date (today): %s\n", today);
    printf("2. Date (tomorrow): %s\n", tomorrow);
    printf("3. Date (the day after tomorrow): %s\n", dayAfterTomorrow);
    printf("4. Exit\n");
}

// ��������ѡ��ĺ���
void handleDateSelection(int choice, const char* today, const char* tomorrow, const char* dayAfterTomorrow) {
    switch (choice) {
        case 1:
            printf("��ѡ���������: %s\n", today);
            break;
        case 2:
            printf("��ѡ���������: %s\n", tomorrow);
            break;
        case 3:
            printf("��ѡ���������: %s\n", dayAfterTomorrow);
            break;
        default:
            // ����ﵽ�����Ϊ�Ѿ�����ѭ�����ж�
            break;
    }
}
