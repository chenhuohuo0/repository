#define _CRT_SECURE_NO_WARNINGS
//slist.h

#define  datatype int
#define MAXSIZE 20
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	datatype data;
	int next;
}node;

typedef struct static_list
{
	node arr[MAXSIZE];
	int len;
}slist;

//��ʼ��
slist* init_slist();

//����
void destory_slist(slist* H);

//��λ��k��Ԫ�ص�λ��
node* locate_by_order(slist* H, int k);

//����
void insert_back(slist* H, int k, datatype x);

//ɾ��
void delete_node(slist* H, int k);

//����
void print_slist(slist* H);
