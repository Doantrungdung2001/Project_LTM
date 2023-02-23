#include <arpa/inet.h>
#include <errno.h>
#include <libgen.h>
#include <mysql/mysql.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include "object.h"
#include "linked_list.h"
#include "protocol.h"
#include "serverFunction.h"

#define BUFF_SIZE 1024
#define ONLINE 1
#define OFFLINE 0
#define BLOCK 2
#define MAX_CLIENTS 10
#define REQUEST_SIZE 1024
#define BUFF_DATA 4096
#define SERVER_NAME "127.0.0.1"
#define USERNAME "root"
#define PASSWORD "Dung19102001"
MYSQL *con;

List users;
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
int count_send = 0;
int count_write = 0;
char main_name[BUFF_SIZE] = "";
int num_client = 0;

    
// check if username is logged in
int isLogged(char *user_name) {
	for(int i = 0; i < MAX_CLIENTS; i++) {
		if(clients[i]) {
			if(strcmp(clients[i]->name, user_name) == 0) {
				return 1;
			}
		}
	}
	return 0;
}

// Thêm các client đã đăng nhập thành công vào mảng kết nối - OK
void queue_add(client_t *cl) {
	pthread_mutex_lock(&clients_mutex);
	for (int i = 0; i < MAX_CLIENTS; ++i) {
		if (!clients[i]) {
			clients[i] = cl;
			num_client++;
			break;
		}
	}
	pthread_mutex_unlock(&clients_mutex);
}

// Xóa client đã đăng xuất ra khỏi mảng đang kết nối - OK
void queue_delete(char *username) {
	pthread_mutex_lock(&clients_mutex);
	for (int i = 0; i < MAX_CLIENTS; ++i) {
		if (clients[i] && strcmp(clients[i]->name, username) == 0) {
			clients[i] = NULL;
			num_client--;
			break;
		}
	}
	pthread_mutex_unlock(&clients_mutex);
}

// In ra danh sách client đang kết nối - OK
void print_queue() {
	printf("[+] List clients: \n");
	for (int i = 0; i < num_client; i++) {
		printf("%s\n", clients[i]->name);
	}
}

// Đọc file chứa thông tin user rồi lưu vào danh sách liên kết userList - OK
// void readUserFile(singleList *users) {
// 	char username[50], password[50];
// 	int status;
// 	FILE *f = fopen("./storage/user.txt", "r");

// 	if (f == NULL) {
// 		perror("[-] Error while opening the file.\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	while (1) {
// 		char c = fgetc(f);
// 		if (c != EOF) {
// 			int res = fseek(f, -1, SEEK_CUR);
// 		}else {
// 			break;
// 		}

// 		fgets(username, 50, f);
// 		username[strlen(username) - 1] = '\0';

// 		fgets(password, 50, f);
// 		password[strlen(password) - 1] = '\0';

// 		fscanf(f, "%d\n", &status);

// 		user_struct *user = (user_struct *)malloc(sizeof(user_struct));
// 		strcpy(user->user_name, username);
// 		strcpy(user->password, password);
// 		user->status = status;
// 		insertEnd(users, user);
// 	}
// 	fclose(f);
// }
// Đọc dữ liệu từ database
void readUsers(){
	MYSQL mysql; 

    if(mysql_init(&mysql)==NULL) { 
        printf("\nInitialization error\n"); 
        return; 
    } 
    mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    char query[BUFF_SIZE];
	sprintf(query, "SELECT username,password,status from users");
    if (mysql_query(&mysql, query))
    {
        printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
        return;
    }
	MYSQL_RES *result = mysql_store_result(&mysql);
	user_struct *user;
	while(1){
		MYSQL_ROW row = mysql_fetch_row(result);
		if (row == NULL)break;
		user = malloc(sizeof(user_struct));
		strcpy(user->user_name,row[0]);
		strcpy(user->password,row[1]);
		user->status = atoi(row[2]);
		insertEnd(&users, user);
	}
}
// Hàm cập nhật trạng thái
void UpdateStatus(char *username){
	MYSQL mysql; 

    if(mysql_init(&mysql)==NULL) { 
        printf("\nInitialization error\n"); 
        return; 
    } 
    mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    char query[BUFF_SIZE];
	sprintf(query,"UPDATE users set status = '0' WHERE username = '%s'",username);
	printf("\n%s",query);
    if (mysql_query(&mysql, query))
    {
        printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
        return;
    }
}
// ham tim path
char *FindImagePath(char *username,char* filename){
	MYSQL mysql; 

    if(mysql_init(&mysql)==NULL) { 
        printf("\nInitialization error\n"); 
        return NULL; 
    } 
    mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    char query[BUFF_SIZE];
	sprintf(query, "SELECT imagelink from user_image where username = '%s' and imagename = '%s'",username,filename);
    if (mysql_query(&mysql, query))
    {
        printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
        return NULL;
    }
	MYSQL_RES *result = mysql_store_result(&mysql);
	MYSQL_ROW row = mysql_fetch_row(result);
	return row[0];
}
// Hàm kiểm tra username đã tồn tại chưa - OK
int checkExistence(int type, List list, char *string) {
	switch (type) {
	// Check user
	case 1: {
		int i = 0;
		list.cur = list.root;
		while (list.cur != NULL) {
			i++;
			if (strcmp(((user_struct *)list.cur->element)->user_name, string) != 0) {
				list.cur = list.cur->next;
			}else {
				return 1;
			}
		}
		return 0;
	}
	break;

	default:
		printf("[-] Type chua hop le !! (1,2 or 3)\n");
		break;
	}
}

// Tìm kiếm user theo username - OK
void *findByName(int type, List list, char string[50]) {
	switch (type) {
	case 1: {
			int i = 0;
			list.cur = list.root;
			while (list.cur != NULL) {
				i++;
				if (strcmp(((user_struct *)list.cur->element)->user_name, string) != 0) {
					list.cur = list.cur->next;
				}else {
					return list.cur->element;
				}
			}
			return NULL;
		}
		break;
	default:
		printf("[-] Type chua hop le !! (1,2 or 3)\n");
		break;
	}
}

// Hàm kiểm tra đăng ký - OK
void signUp(int sock, List *users, char *name, char *pass) {
	char buff[BUFF_SIZE];
	int size;
	printf("USERNAME: \'%s\'\n", name);
    printf("PASS: \'%s\'\n", pass);
	if (checkExistence(1, *users, name) == 1) {
		sendCode(sock, EXISTENCE_USERNAME);
	}else {
		user_struct *user = (user_struct *)malloc(sizeof(user_struct));
		strcpy(user->user_name, name);
		strcpy(user->password, pass);
		user->status = 1;
		insertEnd(users, user);
		sendCode(sock, REGISTER_SUCCESS);
		printf("REGISTER SUCCESS\n");
	}
	// them vao database
	MYSQL mysql; 
    if(mysql_init(&mysql)==NULL) { 
        printf("\nInitialization error\n"); 
        return; 
    } 
    mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    char query[BUFF_SIZE];
	sprintf(query, "INSERT INTO users(username, password,status) VALUES('%s','%s','%d')",name,pass,1);
    if (mysql_query(&mysql, query))
    {
        printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
        return;
    }
	// tao folder trong image
	char dirname[255];
	sprintf(dirname,"image/%s",name);
	int check = mkdir(dirname,S_IRWXU);
	if (!check)
		printf("[+]Folder created\n");
	else {
		printf("[-]Unable to create folder\n");
		exit(1);
	}
}

// Hàm kiểm tra đăng nhập - OK
int signIn(int sock, List users, user_struct **loginUser, char *name, char *pass) {
	if(isLogged(name) == 1) {
		sendCode(sock, IS_CURRENTLY_LOGGED);
		printf("[-] LOGIN FAILED\n");
		return 0;
	}
	if (checkExistence(1, users, name) == 1) {
		*loginUser = (user_struct *)(findByName(1, users, name));
		if (strcmp((*loginUser)->password, pass) == 0) {
			sendCode(sock, LOGIN_SUCCESS);
			client_t *cli = (client_t *)malloc(sizeof(client_t));
			strcpy(cli->name, name);
			cli->sockfd = sock;
			cli->uid = num_client;
			queue_add(cli);
			printf("[+] LOGIN SUCCESS\n");
			return 1;
		}else {
			sendCode(sock, LOGIN_FAILED);
			printf("a");
			printf("[-]LOGIN FAILED\n");
			return 0;
		}
	}else {
		sendCode(sock, LOGIN_FAILED);
		printf("[-]LOGIN FAILED\n");
		printf("b");
		return 0;
	}
}

// Hàm gửi thông điệp tìm kiếm cho các client khác trừ người gửi - OK
void send_message(char name[100], char *nameFile) {
	char send_request[REQUEST_SIZE];
	for (int i = 0; i < num_client; i++) {
		if (strcmp(name, clients[i]->name) != 0) {
			sprintf(send_request, "%d|%s", FIND_IMG_IN_USERS, nameFile);
			printf("->SEND TO %s - RECV FROM %s - %s - %s \n", clients[i]->name, name, nameFile, send_request);
			printf("%s\n",send_request);
			send(clients[i]->sockfd, send_request, sizeof(send_request), 0);
			printf("abcs");
			memset(send_request, '\0', strlen(send_request) + 1);
		}
	}
}

// Hàm gửi code không tìm thấy ảnh - OK
void send_code_img_not_found(){ 
	for (int i = 0; i < num_client; i++) {
		if (strcmp(main_name, clients[i]->name) == 0) {
			sendCode(clients[i]->sockfd, NO_IMG_FOUND);
			break;
		}
	}
}

// Hàm gửi file cho client - OK
void *SendFileToClient(int new_socket, char *fname) {
	SendFile(new_socket, fname);
}


// Gửi danh sách tìm thấy cho người dùng tìm kiếm - OK
void send_message_to_sender(char *file_path, char *username) {
	char send_request[REQUEST_SIZE];
	for (int i = 0; i < num_client; i++) {
		if (strcmp(main_name, clients[i]->name) == 0) {
			sprintf(send_request, "%d|%s", SEND_IMGS_TO_USER, username);
			send(clients[i]->sockfd, send_request, sizeof(send_request), 0);
			SendFileToClient(clients[i]->sockfd, file_path);
			printf("SEND_MESSAGE: %s\n", send_request);
			// if(remove(file_path) == 0){
			// 	printf("[+] DELETED FILE SUCCESS: %s\n", file_path);
			// }else{
			// 	printf("[-]  DELETED FILE FAILED: %s\n", file_path);
			// }
			if(count_send == count_write) {
				count_send = count_write = 0;
				printf("[+] SEND TO %s DONE\n", clients[i]->name);
				break;
			}
		}
	}
}

// Hàm nhận file gửi lên từ client - OK
void receiveUploadedFileServer(int sock, char filePath[200], char *filename){
	if(receiveUploadedFile(sock, filePath, filename)) count_write++;
	else return;
}
// In ra thông điệp request - OK
void printRequest(char *request){
	printf(FG_GREEN "[+] REQUEST: %s\n" NORMAL, request);
}

// Gửi thông điệp không gửi được báo lỗi - OK
void sendWithCheck(int sock, char buff[BUFF_SIZE], int length) {
	int sendByte = 0;
	sendByte = send(sock, buff, length, 0);
	if (sendByte > 0) {
	}else {
		printf("[-] Connection is interrupted\n");
		exit(0);
	}
}

// Nhận thông điệp không gửi được báo lỗi - OK
int readWithCheck(int sock, char buff[BUFF_SIZE], int length) {
	int recvByte = 0;
	recvByte = recv(sock, buff, length, 0);
	if (recvByte > 0) {
		return recvByte;
	}
	return 0;
}

// Hàm gửi file- OK
void *SendFile(int new_socket, char *fname) {
	FILE *fp = fopen(fname, "rb");
	if (fp == NULL) {
		printf("[-] File open error");
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	int n, total = 0;
	char sendline[BUFF_DATA] = {0};
	send(new_socket, &size, sizeof(size), 0);
	while ((n = fread(sendline, 1, BUFF_DATA, fp)) > 0) {
		if (n != BUFF_DATA && ferror(fp)) {
			perror("[-] Read File Error");
			exit(1);
		}
		if (send(new_socket, sendline, n, 0) == -1) {
			perror("[-] Can't send file");
			exit(1);
		}
		total += n;
		memset(sendline, '\0', BUFF_DATA);
		if(total >= size) {
			fclose(fp);
			break;
		}
	}
	printf(FG_GREEN "[+] File OK....Completed" NORMAL "\n");
	printf(FG_GREEN "[+] TOTAL SEND: %d\n" NORMAL, total);
}

// Hàm nhận file vào lưu vào thư mục chứa - OK
int receiveUploadedFile(int sock, char filePath[255],char *filename) {
	FILE *fp;
	printf(FG_GREEN "[+] Receiving file..." NORMAL "\n");
	fp = fopen(filePath, "wb+");
	if (NULL ==fp) {
		printf("[-] Error opening file\n");
		return -1;
	}
	printf("a");
	int sizeFileRecv = 0;
	recv(sock, &sizeFileRecv, sizeof(sizeFileRecv), 0);
	printf("[+] SIZE IMG: %d\n", sizeFileRecv);
	ssize_t n;
	int total = 0;
	char buff[BUFF_DATA] = {0};
	while ((n = recv(sock, buff, BUFF_DATA, 0)) > 0) {
		printf("b");
		if (n == -1) {
			perror("[-] Receive File Error");
			exit(1);
		}
		// if (total + n >= sizeFileRecv) {
		// 	n = sizeFileRecv - total;
		// }
		if (fwrite(buff, 1, n, fp) != n) {
			perror("[-] Write File Error");
			exit(1);
		}
		printf("c");
		total += n;
		memset(buff, '\0', BUFF_DATA);
		if(total >= sizeFileRecv) {
			break;
		}
	}
	printf(FG_GREEN "[+] File OK....Completed" NORMAL "\n");
	printf(FG_GREEN "[+] TOTAL RECV: %d\n" NORMAL, total);
	// them vao database
	// MYSQL mysql; 
    // if(mysql_init(&mysql)==NULL) { 
    //     printf("\nInitialization error\n"); 
    //     return; 
    // } 
    // mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    // char query[BUFF_SIZE];
	// sprintf(query, "INSERT INTO user_image(username,imagename,imagelink) VALUES('%s','%s','%d')",name,filename,filePath);
    // if (mysql_query(&mysql, query))
    // {
    //     printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
    //     return;
    // }
	fclose(fp);
	return 1;
}
// Hàm gửi danh sách trạng thái người dùng
void send_status_user(char* username, int sockfd){
	char send_message[BUFF_SIZE];
	sprintf(send_message,"%d",STATUS_USER_LIST);
	MYSQL mysql; 
    if(mysql_init(&mysql)==NULL) { 
        printf("\nInitialization error\n"); 
        return; 
    } 
    mysql_real_connect(&mysql,SERVER_NAME,USERNAME,PASSWORD,"share_image",0,NULL,0); 
    char query[BUFF_SIZE];
	sprintf(query, "SELECT username,status from users Where username != '%s'",username);
    if (mysql_query(&mysql, query))
    {
        printf("%d|%s\n", QUERY_FAILD, mysql_error(&mysql));
        return;
    }
	char str[BUFF_SIZE];
	MYSQL_RES *result = mysql_store_result(&mysql);
	while(1){
		MYSQL_ROW row = mysql_fetch_row(result);
		if (row == NULL)break;
		// if(strcmp(username,row[0]) == 0) continue;
		sprintf(str,"|%s|%s",row[0],row[1]);
		strcat(send_message,str);
	}
	sendWithCheck(sockfd,send_message,strlen(send_message));
}
// Hàm gửi tín hiệu code tương ứng - OK
void sendCode(int sock, int code) {
	char codeStr[10];
	sprintf(codeStr, "%d", code);
	sendWithCheck(sock, codeStr, strlen(codeStr) + 1);
}
// Hàm kết nối lại
int reconnect(char *username,int socket){
	for(int i = 0; i < MAX_CLIENTS; i++) {
		if(strcmp(clients[i]->name, username) == 0) {
			clients[i]->sockfd = socket;
			printf("%s reconnect by %d",username,socket);
			sendWithCheck(socket,"RECONNET",23);
			return 1;
		}
	}
	return 0;
}

// Xứ lí dấu enter - OK
void str_trim_lf(char *arr, int length) {
	int i;
	for (i = 0; i < length; i++) {
		if (arr[i] == '\n') {
			arr[i] = '\0';
			break;
		}
	}
}

void clearBuff() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}
void clearClient(){
    for(int k = 0; k < MAX_CLIENTS; k++) {
		free(clients[k]);
	}
}
	
//Hàm xử lí luồng - OK
void *handleThread(void *my_sock) {
	int new_socket = *((int *)my_sock);
	PROTOCOL REQUEST;
	char buff[BUFF_SIZE];
	char *name, *pass;
	user_struct *loginUser = NULL;
	readUsers(&users);
	while (1) {
		int n = readWithCheck(new_socket, buff, BUFF_SIZE);
		if(n <= 0 || strlen(buff) == 0) {
			printf("Close request from sockfd = %d\n", new_socket);
			close(new_socket);
			return NULL;
		}
        str_trim_lf(buff,strlen(buff));
		char *opcode = strtok(buff,"|");
		REQUEST = atoi(opcode);
		switch (REQUEST) {
		case REGISTER_REQUEST:
			name = strtok(NULL,"|");
			pass = strtok(NULL,"|");
			printf("[+] REGISTER_REQUEST\n");
			signUp(new_socket, &users, name, pass);
			// saveUsers(users);
			break;
		case LOGIN_REQUEST:
			// nhan username va password
			printf("[+] LOGIN_REQUEST\n");
			name = strtok(NULL, "|");
			pass = strtok(NULL, "|");
			printf("|%s| %s\n",name,pass);
			if (signIn(new_socket, users, &loginUser, name, pass) == 1) {
				while (REQUEST != LOGOUT_REQUEST) {
					char *username;
					char *filename;
					char file_path[255];
					if(readWithCheck(new_socket, buff, REQUEST_SIZE) == 0) {
						continue;
					}
					printRequest(buff);
					char *opcode;
					opcode = strtok(buff, "|");
					REQUEST = atoi(opcode);
					switch (REQUEST) {
					case STATUS_USER_REQUEST:
						username = strtok(NULL,"|");
						send_status_user(username,new_socket);
						break;
					case FIND_IMG_REQUEST:
						username = strtok(NULL, "|");
						strcpy(main_name, username);
						filename = strtok(NULL, "|");
						// gui yeu cau toi cac may con lai
						send_message(username, filename);
						count_send = num_client - 1;
						printf("[+] SEND TO ALL : %s\n", filename);
						break;
					case FILE_WAS_FOUND: //06|dungdoan|file
						username = strtok(NULL, "|");
						filename = strtok(NULL, "|");
						char str[BUFF_SIZE];
						sprintf(str,"%d|%s|%s",ACCEPT_IMAGE,username,filename);
						sendWithCheck(new_socket,str,strlen(str));
						printf("[+] FOUND FROM %s\n", username);  
						str_trim_lf(username, strlen(username));
						sprintf(file_path,"image/%s/%s",username,filename);
						printf("%s\n",file_path);
						printf("image/%s/%s\n",username,filename);
						pthread_mutex_lock(&clients_mutex);
						receiveUploadedFileServer(new_socket, file_path, filename);
						pthread_mutex_unlock(&clients_mutex);
						printf("[+] AMAZING GOOD JOB\n");
						send_message_to_sender(file_path, username);
						break;
					case FILE_WAS_NOT_FOUND:
						count_send--;
						if(count_send == 0) {
							send_code_img_not_found();
						}
						break;
					case LOGOUT_REQUEST: // request code: 14
						printf("[+] LOGOUT_REQUEST\n");
						username = strtok(NULL, "|");
						printf("\nusername:%s",username);
						UpdateStatus(username);
						queue_delete(username);
						sendCode(new_socket, LOGOUT_SUCCESS);
						printf("[+] LOGOUT SUCCESS\n");
						memset(username, '\0', strlen(username) + 1);
						loginUser = NULL;
						break;
					default:
						break;
					}

				}
			}
			break;
		// case RECONNECT:
		// 	name = strtok(NULL,"|");
		// 	if(reconnect(name,new_socket)==1){
		// 		while (1) {
		// 			char *username;
		// 			char *filename;
		// 			char file_path[255];
		// 			if(readWithCheck(new_socket, buff, REQUEST_SIZE) == 0) {
		// 				continue;
		// 			}
		// 			printRequest(buff);
		// 			char *opcode;
		// 			opcode = strtok(buff, "|");
		// 			REQUEST = atoi(opcode);
		// 			switch (REQUEST) {
		// 			case STATUS_USER_REQUEST:
		// 				username = strtok(NULL,"|");
		// 				send_status_user(username,new_socket);
		// 				break;
		// 			case FIND_IMG_REQUEST:
		// 				username = strtok(NULL, "|");
		// 				strcpy(main_name, username);
		// 				filename = strtok(NULL, "|");
		// 				// gui yeu cau toi cac may con lai
		// 				send_message(username, filename);
		// 				count_send = num_client - 1;
		// 				printf("[+] SEND TO ALL : %s\n", filename);
		// 				break;
		// 			case FILE_WAS_FOUND:
		// 				username = strtok(NULL, "|");
		// 				filename = strtok(NULL, "|");
		// 				char str[BUFF_SIZE];
		// 				sprintf(str,"%d|%s|%s",ACCEPT_IMAGE,username,filename);
		// 				sendWithCheck(new_socket,str,strlen(str));
		// 				printf("[+] FOUND FROM %s\n", username);  
		// 				str_trim_lf(username, strlen(username));
		// 				sprintf(file_path,"image/%s/%s",username,filename);
		// 				pthread_mutex_lock(&clients_mutex);
		// 				receiveUploadedFileServer(new_socket, file_path, filename);
		// 				pthread_mutex_unlock(&clients_mutex);
		// 				printf("[+] AMAZING GOOD JOB\n");
		// 				send_message_to_sender(file_path, username);
						
		// 				break;
		// 			case FILE_WAS_NOT_FOUND:
		// 				count_send--;
		// 				if(count_send == 0) {
		// 					send_code_img_not_found();
		// 				}
		// 				break;
		// 			case LOGOUT_REQUEST: // request code: 14
		// 				printf("[+] LOGOUT_REQUEST\n");
		// 				username = strtok(NULL, "|");
		// 				printf("\nusername:%s",username);
		// 				UpdateStatus(username);
		// 				queue_delete(username);
		// 				sendCode(new_socket, LOGOUT_SUCCESS);
		// 				printf("[+] LOGOUT SUCCESS\n");
		// 				memset(username, '\0', strlen(username) + 1);
		// 				loginUser = NULL;
		// 				break;
		// 			default:
		// 				break;
		// 			}
		// 			if(REQUEST == LOGOUT_REQUEST)break;
		// 		}
		// 	}
		// 	break;
		case LOGOUT_REQUEST: // request code: 14
			printf("[+] LOGOUT_REQUEST\n");
			name = strtok(NULL, "|");
			printf("\nname:%s",name);
			UpdateStatus(name);
			queue_delete(name);
			sendCode(new_socket, LOGOUT_SUCCESS);
			printf("[+] LOGOUT SUCCESS\n");
			memset(name, '\0', strlen(name) + 1);
			loginUser = NULL;
			break;			
		case EXIT_SYS:
			close(new_socket);
			printf("Close request from sockfd = %d\n", new_socket);
			return NULL;
		default:
			break;
		}
		memset(buff, '\0', strlen(buff) + 1);
	}
}