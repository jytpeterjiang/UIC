#include "auth.h"
#include <stdio.h>
#include <string.h>

bool authenticateUser(const char *username, const char *password) {
    FILE *file = fopen("account.txt", "r");
    if (!file) {
        perror("T_T Failed to open account.txt");
        return false;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char storedUsername[50], storedPassword[50];
        sscanf(line, "%s %s", storedUsername, storedPassword);
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}
