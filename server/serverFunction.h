#ifndef __SERVERFUNCTION_H__
#define __SERVERFUNCTION_H__

#include "object.h"
#define BUFF_SIZE 1024
int isLogged(char *user_name);
void queue_add(client_t *cl);
void queue_delete(char *username);
void print_queue();
void readUsers();
void UpdateStatus(char* username);
char *FindImagePath(char *username,char* filename);
int checkExistence(int type, List list, char *string);
void *findByName(int type, List list, char string[50]);
void signUp(int sock, List *users, char *name, char *pass);
int signIn(int sock, List users, user_struct **loginUser, char *name, char *pass);
void send_message(char name[100], char *nameFile);
void send_code_img_not_found();
void send_status_user(char* username, int sockfd);
void *SendFileToClient(int new_socket, char *fname);
void send_message_to_sender(char *file_path, char *username);
void receiveUploadedFileServer(int sock, char filePath[200],char *filename);
void printRequest(char *request);
void sendWithCheck(int sock, char buff[BUFF_SIZE], int length);
int readWithCheck(int sock, char buff[BUFF_SIZE], int length);
void *SendFileToServer(int new_socket, char fname[50]);
int receiveUploadedFile(int sock, char filePath[100],char *filename);
void str_trim_lf(char *arr, int length);
void sendCode(int sock, int code);
void clearBuff();
void *SendFile(int new_socket, char *fname);
void *handleThread(void *my_sock);
#endif  // _SERVER_FUNC_H
