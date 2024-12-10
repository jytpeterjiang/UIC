// account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>

// 结构体声明
struct File_information {
    char fileAccounts[100];
    char filePasswords[100];
};

// 函数声明
void read_string_from_input(char *s, int size);
int validate_account(const char *filename, const char *account, const char *password);

#endif // ACCOUNT_H
