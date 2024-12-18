// authenticator.h
#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QString>

class Authenticator {
public:
    bool authenticateUser(const char *username, const char *password);
};

#endif // AUTHENTICATOR_H
