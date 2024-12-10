/*已知共有三位学生信息：
alice 1111
tony 2222
jane 3333
*/
#include <stdio.h>
#include <string.h>

void read_string_from_input(char *s, int size) {
    int i = 0;
    char ch;
    while (i < size) {
        scanf("%c", &s[i]);
        if (s[i] == '\n') {
            break;
        }
        i++;
    }
    s[i] = '\0';
}

int main() {
    struct information {
        char acc[10];
        char pass[12]; // 改成用char数组存储密码
    };

    // 定义三个有效用户，之后循环验证，不用每次都写if判断
    int valid_user_num = 3;
    struct information valid_users[3] = {
        {"alice", "1111"},
        {"tony", "2222"},
        {"jane", "3333"}
    };

    printf("Please enter the account password: \n");

    for (int attempt = 0; attempt < 3; attempt++) {
        struct information user;

        printf("Account: ");
        read_string_from_input(user.acc, 10); // 改成用函数读取字符串，不容易出错

        printf("Password: ");
        read_string_from_input(user.pass, 12);

        for (int i = 0; i < valid_user_num; i++) {
            if (strcmp(user.acc, valid_users[i].acc) == 0 && strcmp(user.pass, valid_users[i].pass) == 0) {
                printf("Welcome, %s!\n", user.acc);
                return 0;
            }
        }
        printf("Invalid account name or password!\n");
    }
    printf("You have failed three times!\n");
    return 0;
}