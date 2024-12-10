// account.c
#include "account.h"
#include <stdlib.h>
#include <string.h>

void read_string_from_input(char *s, int size) {
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0'; // 移除换行符
}

int validate_account(const char *filename, const char *account, const char *password) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    struct File_information file_information[100];
    char line[256];
    int accountCount = 0;

    while (fgets(line, sizeof(line), file) && accountCount < 100) {
        sscanf(line, "%49s %49s", file_information[accountCount].fileAccounts, file_information[accountCount].filePasswords);
        accountCount++;
    }
    fclose(file);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(account, file_information[i].fileAccounts) == 0 &&
            strcmp(password, file_information[i].filePasswords) == 0) {
            return 1; // 登录成功
        }
    }
    return 0; // 登录失败
}
