#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>


#define BUFF_SIZE 1024

int main(int argc, char * argv[]){
    if(argc < 3)return 1;
	int client_sock,choose,menu;
	char buff[BUFF_SIZE];
	char *name , *pass;
	char enter,comfirm;
	struct sockaddr_in server_addr; /* server's address information */
	int msg_len, bytes_sent, bytes_received;
	
	//Step 1: Construct socket
	client_sock = socket(AF_INET,SOCK_STREAM,0);
	
	//Step 2: Specify server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	
	//Step 3: Request to connect server
	if(connect(client_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0){
		printf("\nError!Can not connect to sever! Client exit imediately! ");
		return 0;
	}
		
	//Step 4: Communicate with server			
	while(1){
		printf("\n*********************************************\n");
		printf("*1.Dang nhap                                 *\n");
		printf("*2.Dang ky                                   *\n");
		printf("*3.Thoat                                     *\n");
		printf("*********************************************\n");
		printf("Ban hay chon 1 chuc nang : ");
		scanf("%d",&choose);
		scanf("%c",&enter);
		switch (choose){
			case 1:
				printf("\nChuc nang dang nhap\n");
				printf("Nhap:");
				fflush(stdin);
				memset(buff,'\0',(strlen(buff)+1));
				fgets(buff, BUFF_SIZE, stdin);		
				msg_len = strlen(buff);
				if (msg_len == 0) break;
			
				bytes_sent = send(client_sock, buff, msg_len, 0);
				if(bytes_sent <= 0){
					printf("\nConnection closed!\n");
					break;
				}
				//receive echo reply
				bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
				if(bytes_received <= 0){
					printf("\nError!Cannot receive data from sever!\n");
					break;
				}
				printf("Reply from server: %s\n", buff);
				if(strcmp(buff,"16") == 0){
					printf("Login\n");
					while (1){
						printf("\n*********************************************\n");
						printf("*Tim kiem anh theo ten                       *\n");
						printf("*Dang xuat                                  *\n");
						printf("*********************************************\n");
						printf("Nhap:");
						memset(buff,'\0',(strlen(buff)+1));
						fgets(buff, BUFF_SIZE, stdin);		
						msg_len = strlen(buff);
						if (msg_len == 0) break;
						
						bytes_sent = send(client_sock, buff, msg_len, 0);
						if(bytes_sent <= 0){
							printf("\nConnection closed!\n");
							break;
						}
						//receive echo reply
						bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
						if(bytes_received <= 0){
							printf("\nError!Cannot receive data from sever!\n");
							break;
						}
						printf("Reply from server: %s\n", buff);
						
						if(strcmp(buff,"17")){

						}
						else if(strcmp(buff,"17") == 0){
							break;
						}else{
							printf("Nhap lai\n");
						}
					}	
				}else{
					printf("fale\n");
				}
			break;
			case 2:
				printf("\nChuc nang dang ky\n");
				printf("Nhap:");
				fflush(stdin);
				memset(buff,'\0',(strlen(buff)+1));
				fgets(buff, BUFF_SIZE, stdin);		
				msg_len = strlen(buff);
				if (msg_len == 0) break;
			
				bytes_sent = send(client_sock, buff, msg_len, 0);
				if(bytes_sent <= 0){
					printf("\nConnection closed!\n");
					break;
				}
				//receive echo reply
				bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
				if(bytes_received <= 0){
					printf("\nError!Cannot receive data from sever!\n");
					break;
				}
				
				printf("Reply from server: %s\n", buff);
				if(strcmp(buff,"16") == 0){
					printf("Login\n");
				}else{
					printf("fale\n");
				}
			break;

			case 3:
				printf("Ban co muon thoat khong(y/n)?");
				scanf("%c",&comfirm);
				if(comfirm == 'y'){
					exit(0);
				}
				
		}
		// send message
		// printf("\nInsert string to send:");
		// memset(buff,'\0',(strlen(buff)+1));
		// fgets(buff, BUFF_SIZE, stdin);		
		// msg_len = strlen(buff);
		// if (msg_len == 0) break;
		
		// bytes_sent = send(client_sock, buff, msg_len, 0);
		// if(bytes_sent <= 0){
		// 	printf("\nConnection closed!\n");
		// 	break;
		// }
		
		// //receive echo reply
		// bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
		// if(bytes_received <= 0){
		// 	printf("\nError!Cannot receive data from sever!\n");
		// 	break;
		// }
		
		// // if(strcmp(buff,"16")){
		// // 	printf("Login");
		// // }else{
		// // 	printf("fale");
		// // }
		// printf("Reply from server: %s", buff);
	}
	
	//Step 4: Close socket
	close(client_sock);
	return 0;
}
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
	printf("[+] File OK....Completed\n");
	printf("[+] TOTAL SEND: %d\n", total);
}

void receiveUploadedFile(int sock, char filePath[255],char *filename) {
	FILE *fp;
	printf([+] Receiving file... "\n");
	fp = fopen(filePath, "wb");
	if (NULL == fp) {
		printf("[-] Error opening file\n");
		return -1;
	}
	int sizeFileRecv = 0;
	recv(sock, &sizeFileRecv, sizeof(sizeFileRecv), 0);
	printf("[+] SIZE IMG: %d\n", sizeFileRecv);
	ssize_t n;
	int total = 0;
	char buff[BUFF_DATA] = {0};
	while ((n = recv(sock, buff, BUFF_DATA, 0)) > 0) {
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
		total += n;
		memset(buff, '\0', BUFF_DATA);
		if(total >= sizeFileRecv) {
			break;
		}
	}
	printf("[+] File OK....Completed\n");
	printf("[+] TOTAL RECV: %d \n", total);
	
	fclose(fp);
}