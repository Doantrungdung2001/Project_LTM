#include "object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Các hàm khởi tạo
*/
void   createList(List * list);
node * makeNewNode(void *e);

/*
Thêm 1 node
*/

node * insertAfter(List * list, void *e);
node * insertBegin(List * list, void *e);
node * insertEnd(List * list, void *e);
node * insertAtPosition(List * list, void *e, int n);

/*
Xóa node
*/

node * deleteBegin(List * list);
node * deleteEnd(List * list);
node * deleteAtPosition(List * list, int n);
node * deleteList(List * list);


/*
Tất cả node
*/
int    printUser(List list);
int    printGroup(List list);

/*
*
*
Chi tiết các hàm
*
*
*/

// Tạo danh sách mới - OK 
void createList(List * list) {
  (*list).root = (*list).prev = (*list).cur = (*list).tail  = NULL;
}

// Tạo node mới - OK
node * makeNewNode(void *e)
{
  node * newNode = (node *)malloc(sizeof(node));
  newNode->element = e;
  newNode->next = NULL;
  return newNode;
}

// Thêm vào cuối danh sách - OK
node * insertEnd(List *list,void *e)
{
	node * newNode = makeNewNode(e);
	if((*list).root == NULL)
	{
      (*list).root = (*list).tail = newNode;
	}
	else
	{
		(*list).tail->next = newNode;
		(*list).tail = newNode;
	}
	return (*list).tail;
}

// Thêm vào đầu danh sách - OK
node * insertBegin(List * list, void *e)
{
  node * newNode = makeNewNode(e);
  if ((*list).root == NULL)
    {
      (*list).root = (*list).tail = newNode;
    }
  else
    {
      newNode->next=(*list).root;
      (*list).root = newNode;
    }
  return (*list).root;
}

// Tinh tong list - OK
int totalList(List list) {
  int i=0;
  list.cur = list.root;
	while(list.cur != NULL)
      {
        i++;
        list.cur = list.cur->next;
      }
    return i;
}

// Thêm vào vị trí - OK
node * insertAtPosition(List * list,void *e,int n)
{
  node *newNode = makeNewNode(e);
  if((*list).root == NULL)
    {
      (*list).root = (*list).tail = (*list).cur = newNode;
	}
  else
    {
      if(n <= 1)
        {
          insertBegin(list,newNode->element);
          return (*list).cur;
        }
      if(n > totalList(*list))
        {
          insertEnd(list,newNode->element);
          return (*list).cur;
        }
      else
        {
          (*list).cur = (*list).prev = (*list).root;
          int i = 1;
          while(((*list).cur->next != NULL)&&(i <= n-1))
            {
              i++;
              (*list).prev = (*list).cur;
              (*list).cur = (*list).cur->next;
            }
          newNode->next = (*list).cur;
          (*list).prev->next = (*list).cur = newNode;
        }
    }
  return (*list).cur;
}

// Xóa node đầu tiên - OK
node * deleteBegin(List * list)
{
  if((*list).root != NULL)
	{
    node * newNode = (*list).root;
		(*list).root = (*list).root->next;
		free(newNode);
	}
  return (*list).root;
}

// Xóa node cuối cùng - OK
node * deleteEnd(List *list)
{
  if((*list).root != NULL)
    {
      (*list).cur = (*list).prev = (*list).root;
        while(((*list).cur->next != NULL))
          {
            (*list).prev = (*list).cur;
            (*list).cur = (*list).cur->next;
          }
      node *newNode = (*list).cur;
      (*list).cur = (*list).cur->next;
      free(newNode);
      (*list).tail = (*list).prev;
      (*list).tail->next = NULL;
      return (*list).tail;
    }
}

// Xóa tất cả - OK
node * deleteList(List * list)
{
  while((*list).root != NULL) deleteBegin(list);
}

// Luu thong tin user - OK
int saveUsers(List users){
  user_struct* user = NULL;

  FILE *fp = fopen("./storage/user.txt", "w");

  if(fp == NULL){
    printf("Khong tim thay file luu tru. Luu nguoi dung that bai!!\n");
  }

  users.cur = users.root;
  while(users.cur != NULL){
    user = (user_struct*)(users.cur->element);
    fprintf(fp, "%s\n%s\n%d\n", user->user_name, user->password, user->status);
    users.cur = users.cur->next;
  }

  fclose(fp);
  printf("Save account success\n");
}