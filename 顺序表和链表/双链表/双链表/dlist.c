#define _CRT_SECURE_NO_WARNINGS
//dlist.c
#include "dlist.h"

//创建头结点，返回头指针
dlist* init_dlist()
{
	dlist* H = (dlist*)malloc(sizeof(dlist));
	if (H == NULL)
	{
		perror("init_dlist error");
		exit(-1);
	}
	H->prior = NULL;
	H->next = NULL;
	H->data = 0;
	return H;
}

//申请结点
dlist* request_node(datatype x)
{
	dlist* p = (dlist*)malloc(sizeof(dlist));
	if (p == NULL)
	{
		perror("init_dlist error");
		exit(-1);
	}
	p->data = x;
	p->next = NULL;
	p->prior = NULL;
	return p;
}

//计算当前表长（不包含头结点）
int length_dlist(dlist* H)
{
	dlist* p = H->next;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

//插入结点在第k个元素后面
void insert_back(dlist* H, int k, datatype x)
{
	int len = length_dlist(H);
	if (k<0 || k>len)
	{
		printf("下标不合法\n");
		return;
	}
	dlist* newnode = request_node(x);
	dlist* p = locate_by_order(H, k);
	if (k == len)
	{
		p->next = newnode;
		newnode->prior = p;
	}
	else
	{
		p->next->prior = newnode;
		newnode->next = p->next;
		p->next = newnode;
		newnode->prior = p;
	}
}

//删除第k个节点
void delete_node(dlist* H, int k)
{
	int len = length_dlist(H);
	if (k <= 0 || k > len)
	{
		printf("下标不合法\n");
		return;
	}
	dlist* p = locate_by_order(H, k - 1);
	dlist* q = p->next;
	if (k == len)
	{
		p->next = NULL;
		free(q);
	}
	else
	{
		p->next = q->next;
		q->next->prior = p;
		free(q);
	}
}

//定位第k个结点的位置
dlist* locate_by_order(dlist* H, int k)
{
	if (k<0 || k>length_dlist(H))
	{
		printf("下标不合法\n");
		exit(-1);
	}
	dlist* p = H;
	int i = 0;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//按值查找，返回首次出现的元素位置
dlist* locate_by_value(dlist* H, datatype x)
{
	dlist* p = H->next;
	while (p)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

//销毁表
void destory_dlist(dlist* H)
{
	dlist* p = H;
	while (p)
	{
		dlist* q = p->next;
		free(p);
		p = q;
	}
}

//遍历表
void print_dlist(dlist* H)
{
	dlist* p = H->next;
	printf("H ->");
	while (p)
	{
		printf("%d <-> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}