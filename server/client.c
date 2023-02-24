#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#define BUFF_DATA 4096
#define PATH "image/admin/hanoi.jpg"
#define BUFF_SIZE 1024

int send_image(int socket,char *filepath){
   FILE *picture;
   int size, read_size, stat, packet_index;
   char send_buffer[BUFF_SIZE], read_buffer[256];
   packet_index = 1;
   picture = fopen(filepath, "rb");
   if(picture == NULL) {
        printf("Error Opening Image File"); 
    } 
   fseek(picture, 0, SEEK_END);
   size = ftell(picture);
   fseek(picture, 0, SEEK_SET);

   //Send Picture Size
   write(socket, (void *)&size, sizeof(int));

   //Send Picture as Byte Array

   do { //Read while we get errors that are due to signals.
        stat=read(socket, &read_buffer , 255);
   } while (stat < 0);

   while(!feof(picture)) {
        //Read from the file into our send buffer
        read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

        //Send data through our socket 
        do{
            stat = write(socket, send_buffer, read_size);  
        }while (stat < 0);
        packet_index++;  
        //Zero out our send buffer
        bzero(send_buffer, sizeof(send_buffer));
    }
    return 1;
}

void SendFile(int new_socket, char *fname) {
	printf("b");
	FILE *fp = fopen(fname, "r");
	printf("a");
	if (fp == NULL) {
		printf("[-] File open error");
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	int n, total = 0;
	char sendline[BUFF_DATA] = {0};
	printf("abc\n");
	send(new_socket, &size, sizeof(size), 0);
	printf("abcdef\n");
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

int main(int argc, char * argv[]){
    if(argc < 3)return 1;
	int client_sock,choose,menu;
	char buff[BUFF_SIZE],input[BUFF_SIZE];
	char *name , *pass;
	char comfirm;
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
		
		// send message
		printf("\nInsert string to send:");
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
		
		if(strcmp(buff,"16") == 0){
            printf("Login!!!!!\n");
            memset(buff,'\0',(strlen(buff)+1));
            bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
			if(bytes_received <= 0){
				printf("\nError!Cannot receive data from sever!\n");
				break;
			}
			char *opcode = strtok(buff,"|");
			char *filename = strtok(NULL,"|");
			printf("Reply from server:%s %s\n",opcode,filename);
			if(strcmp(opcode,"5") ==0 ){
				// printf("Ban nhan duoc yeu cau muon chia se anh ,Ban co muon chia se khong(y/n)?");
				// scanf("%c",&comfirm);
				if(1){
					char x[BUFF_SIZE];
			
					FILE *fp = fopen(x, "wb+");
					if (fp == NULL) {
						printf("[-] Error opening file\n");
						return -1;
					}
					printf("Nhap thong diep:");
					memset(buff,'\0',(strlen(buff)+1));
					fgets(buff, BUFF_SIZE, stdin);					
					msg_len = strlen(buff);

					if (msg_len == 0) break;
					bytes_sent = send(client_sock, buff, msg_len, 0);
					printf("%s\n",buff);
					if(bytes_sent <= 0){
						printf("\nConnection closed!\n");
						break;
					}
					send_image(client_sock,PATH );
					// SendFile(client_sock,x);
					// bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
					// if(bytes_received <= 0){
					// 	printf("\nError!Cannot receive data from sever!\n");
					// 	break;
					// }
					// printf("Reply from server: %s", buff);
					
					printf("Cam on ban da chia se file\n");
					// exit(0);
				}
			}else{
				printf("That su xin loi vi da lam phien !!!!\n");
				exit(0);
			}
            
			
		}else{
			printf("fale\n");
		}
		// printf("Reply from server: %s", buff);
	}
	
	//Step 4: Close socket
	close(client_sock);
	return 0;
}

void receiveUploadedFile(int sock, char filePath[255],char *filename) {
	FILE *fp;
	printf("[+] Receiving file... \n");
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