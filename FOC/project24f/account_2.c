#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_string_from_input(char *s, int size) {
    int i = 0;
    char ch;
    while (i < size - 1) {
        scanf("%c", &ch);
        if (ch == '\n' || ch == EOF) {
            break;
        }
        s[i++] = ch;
    }
    s[i] = '\0'; // 确保字符串以'\0'结尾
}

int main() {
    FILE *file;
    char filename[256];
    char account[50];
    char password[50];

    // 打开文件
    file = fopen("account.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    // 读取文件内容并存储账户信息
	struct File_information{
        char fileAccounts[100];
        char filePasswords[100];
	};
	struct File_information file_information[100];
	char line[256];
    int accountCount = 0;
    while (fgets(line, sizeof(line), file) != NULL && accountCount < 100) {
        sscanf(line, "%49s %49s", file_information[accountCount].fileAccounts, file_information[accountCount].filePasswords);
        accountCount++;
    }

    // 关闭文件
    fclose(file);

    // 提示用户输入账号和密码
	int attempt=0;
	while(attempt<3){
        printf("Please enter your account and password:\n");
	    printf("Account: ");
        read_string_from_input(account, sizeof(account));
        printf("Password: ");
        read_string_from_input(password, sizeof(password));

    // 验证账号和密码
        for (int i = 0; i < accountCount; i++) {
            if (strcmp(account, file_information[i].fileAccounts) == 0 && strcmp(password, file_information[i].filePasswords) == 0) {
                printf("Welcome!\n");
                return 0;
            }
        }
		if (attempt < 2) {
            printf("Invalid account name or password!\n");
        }
        attempt++;
    }

    if (attempt == 3) {
        printf("You have failed three times!\n");
    }

    // 输出结果
   
    return 0;
}
