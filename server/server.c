#include <arpa/inet.h>
#include <errno.h>
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <pthread.h>

#define PORT 8888
#define BACKLOG 20
#define BUFF_SIZE 1024
#define MAX_CLIENTS 10
#include "serverFunction.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Please input port number\n");
		return 0;
	}
	int port = atoi(argv[1]);
	int opt = 1;
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("[-]Socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		perror("[-]Setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	// Forcefully attaching socket to the port
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("[-]Bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("[-]Listen");
		exit(EXIT_FAILURE);
	}
	while (1) {
		pthread_t tid;

		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
			perror("[-]Accept");
			exit(EXIT_FAILURE);
		}
		printf("New request from sockfd = %d.\n", new_socket);
		pthread_create(&tid, NULL, &handleThread, &new_socket);
	}
	close(server_fd);
	return 0;
}
