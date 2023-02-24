// #include <stdio.h>
// #include <stdlib.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <sys/socket.h>
// #include <sys/types.h>
// #include <string.h>


#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define PATH "hanoi.jpg"

#define BUFF_SIZE 1024
#define BUFF_DATA 4096

//nhan anh
int receive_image(int socket, char *filename)
{ // Start function 
	int buffersize = 0, recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

	char imagearray[10240],verify = '1';
	FILE *image;
	//Find the size of the image
	do{
		stat = read(socket, &size, sizeof(int));
	}while(stat < 0);
	printf("nhan size\n");
	printf("Kich thuoc :%d\n",size);
	char buffer[255] = "Got";	
//Send our verification signal
	do{
		stat = write(socket, &buffer, sizeof(int));
	}while(stat < 0);

	image = fopen(filename, "w+");
//Loop while we have not received the entire file yet
	int need_exit = 0;
	struct timeval timeout = {10,0};

	fd_set fds;
	int buffer_fd, buffer_out;
	while(recv_size < size) {
		FD_ZERO(&fds);
		FD_SET(socket,&fds);
		buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);
		if (buffer_fd < 0)
			printf("error: bad file descriptor set.\n");
		if (buffer_fd == 0)
			printf("error: buffer read timeout expired.\n");
		if (buffer_fd > 0)
		{
			do{
				read_size = read(socket,imagearray, 10241);
			}while(read_size <0);

		//Write the currently read data into our image file
			write_size = fwrite(imagearray,1,read_size, image); 
			if(read_size != write_size) {
				printf("error in read write\n");    
			}
			//Increment the total number of bytes read
			recv_size += read_size;
			packet_index++;
		}
	}
	fclose(image);
	return 1;
}
int main(int argc, char * argv[]){
    if(argc < 3)return 1;
	int client_sock,choose,menu;
	char buff[BUFF_SIZE],file_path[BUFF_SIZE];
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
						printf("*1.Hien thi thong tin nguoi online            *\n");
						printf("*2.Tim kiem anh                               *\n");
						printf("*3.Dang xuat                                  *\n");
						printf("*********************************************\n");
						printf("Ban hay chon 1 chuc nang :");
						scanf("%d",&menu);
						scanf("%c",&enter);
						switch (menu){
						case 1:
							printf("chuc nang 1\n");
							break;
						case 2:
							printf("Nhap thong diep :");
							memset(buff,'\0',(strlen(buff)+1));
							fgets(buff, BUFF_SIZE, stdin);		
							msg_len = strlen(buff);
							if (msg_len == 0) break;
								
							bytes_sent = send(client_sock, buff, msg_len, 0);
							if(bytes_sent <= 0){
								printf("\nConnection closed!\n");
								break;
							}
							receive_image(client_sock,PATH);
							break;
						case 3:
							printf("Ban co muon dang xuat khong khong(y/n)?");
							scanf("%c",&comfirm);
							if(comfirm == 'y'){
								exit(0);
							}
						default:
							break;
						}
						
					}		
				}else{
					printf("fale\n");
				}
			break;
			case 2:
				printf("\nChuc nang dang ky\n");
				printf("Nhap thong diep:");
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
				// if(strcmp(buff,"16") == 0){
				// 	printf("Login\n");
				// }else{
				// 	printf("fale\n");
				// }
			break;

			case 3:
				printf("Ban co muon thoat khong(y/n)?");
				scanf("%c",&comfirm);
				if(comfirm == 'y'){
					exit(0);
				}
				
		}
	}
	
	//Step 4: Close socket
	close(client_sock);
	return 0;
}
