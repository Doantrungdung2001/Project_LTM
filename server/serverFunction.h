#ifndef _SERVER_FUNC_H
#define _SERVER_FUNC_H
#include "protocol.h"

void handle_message(char*, int);
int registerUser(char*, int);
int loginUser(char*, int);
int logoutUser(char*, int);
#endif  // _SERVER_FUNC_H
