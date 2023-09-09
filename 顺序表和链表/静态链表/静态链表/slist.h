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

//初始化
slist* init_slist();

//销毁
void destory_slist(slist* H);

//定位第k个元素的位置
node* locate_by_order(slist* H, int k);

//插入
void insert_back(slist* H, int k, datatype x);

//删除
void delete_node(slist* H, int k);

//遍历
void print_slist(slist* H);
