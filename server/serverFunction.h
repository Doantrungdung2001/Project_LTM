#ifndef __SERVERFUNCTION_H__
#define __SERVERFUNCTION_H__

#include "object.h"
#define BUFF_SIZE 1024
int isLogged(char *user_name);
void queue_add(client_t *cl);
void queue_delete(char *username);
void print_queue();
void readUserFile(singleList *users);
int checkExistence(int type, singleList list, char *string);
void *findByName(int type, singleList list, char string[50]);
void signUp(int sock, singleList *users, char *name, char *pass);
int signIn(int sock, singleList users, user_struct **loginUser, char *name, char *pass);
void send_message(char name[100], char *nameFile);
void send_code_img_not_found();
void *SendFileToClient(int new_socket, char *fname);
void send_message_to_sender(char *file_path, char *username);
void receiveUploadedFileServer(int sock, char filePath[200]);
void printRequest(char *request);
void sendWithCheck(int sock, char buff[BUFF_SIZE], int length);
int readWithCheck(int sock, char buff[BUFF_SIZE], int length);
void *SendFileToServer(int new_socket, char fname[50]);
int receiveUploadedFile(int sock, char filePath[100]);
void str_trim_lf(char *arr, int length);
void sendCode(int sock, int code);
void clearBuff();
void *SendFile(int new_socket, char *fname);
void *handleThread(void *my_sock);
#endif  // _SERVER_FUNC_H
