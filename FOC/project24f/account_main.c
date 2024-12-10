// main.c
#include <stdio.h>
#include "account.h"

int main() {
    char account[50];
    char password[50];

    for (int attempt = 0; attempt < 3; attempt++) {
        printf("Please enter your account and password:\n");
        printf("Account: ");
        read_string_from_input(account, sizeof(account));
        printf("Password: ");
        read_string_from_input(password, sizeof(password));

        if (validate_account("account.txt", account, password)) {
            printf("Welcome!\n");
            return 0;
        } else {
            printf("Invalid account name or password!\n");
        }
    }

    printf("You have failed three times!\n");
    return 0;
}
