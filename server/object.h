#ifndef __OBJECT_H__
#define __OBJECT_H__
typedef struct node_t{
	void *element;
	struct node_t *next;
} node;

typedef struct single_t{
	node * root;
	node * cur;
	node * prev;
	node * tail;
}List;

typedef struct user_t
{
	char user_name[50];
	char password[50];
	int status;
} user_struct;

typedef struct client
{
	int sockfd;
	int uid;
	char name[100];
} client_t;
#endif