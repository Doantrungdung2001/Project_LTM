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
						printf("*1.Tim kiem anh theo ten                      *\n");
						printf("*2.Dang xuat                                  *\n");
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
