#define _CRT_SECURE_NO_WARNINGS

//cir_slist.c
#include "cir_slist.h"
//创建一个头节点，返回一个尾指针
list* init_list()
{
	list* R = (list*)malloc(sizeof(list));
	if (!R)
	{
		perror("initialization failed");
		exit(-1);
	}
	else
	{
		R->data = 0;
		R->next = R;
		return R;
	}
}

//申请结点
list* request_node(datatype x)
{
	list* R = (list*)malloc(sizeof(list));
	if (!R)
	{
		perror("initialization failed");
		exit(-1);
	}
	R->data = x;
	R->next = NULL;
	return R;
}

//销毁表
void destory_list(list* R)
{
	list* p = R->next;
	list* q =NULL;
	while (p != R)
	{
		q = p->next;
		free(p);
		p=q;
	}
	free(R);
	R = NULL;
}

//求当前的表长（不包含头结点）
int length_list(list* R)
{
	list* p = R->next;
	int count = 0;
	while (p != R)
	{
		count++;
		p = p->next;
	}
	return count;
}

//定位第k个元素的位置
list* locate_by_order(list* R, int k)
{
	if (k<0 || k>length_list(R))
	{
		printf("下标不合法\n");
		exit(-1);
	}
	list* p = R->next;
	int i = 0;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//在第k个元素后面插入x
void insert_back(list** R, int k, datatype x)
{
	int len = length_list(*R);
	if (k<0 || k>len)
	{
		printf("下标不合法\n");
		return;
	}
	list* newnode = request_node(x);
	//找到第k个元素的位置
	list* p = locate_by_order(*R, k);
	newnode->next = p->next;
	p->next = newnode;
	//如果插入表尾需要调整尾指针的位置
	if (len == k)
	{
		*R = newnode;
	}
}

//删除第k个元素
void delete_by_order(list** R, int k)
{
	int len = length_list(*R);
	if (0 == len)
	{
		printf("空表不能删除\n");
		return;
	}
	if (k <= 0 || k > len)
	{
		printf("下标不合法\n");
		return;
	}
	list* p = locate_by_order(*R, k - 1);
	list* q;
	q = p->next;
	p->next = q->next;
	free(q);
	//如果删除最后一个元素需要调整尾指针的位置
	if (len == k)
	{
		(*R) = p;
	}
}

//遍历
void print_list(list* R)
{
	printf("H ");
	list* p = R->next;
	while (p != R)
	{
		list* q = p->next;
		printf("-> %d ", q->data);
		p = q;
	}
	printf("-> H\n");
}