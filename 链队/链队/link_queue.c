#define _CRT_SECURE_NO_WARNINGS

//link_queue.c
#include "link_queue.h"


//申请一个结点
node* request_node(datatype x)
{
	node* p = (node*)malloc(sizeof(node));
	if (p)
	{
		p->data = x;
		p->next = NULL;
	}
	return p;
}

//初始化
queue* init_queue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	if (!Q)
	{
		perror("init_queue error");
		exit(-1);
	}
		Q->front = NULL;
		Q->rear = NULL;
		return Q;
}

//销毁
void destory_queue(queue** Q)
{
	node* p = (*Q)->rear;
	node* q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(*Q);
}

//判队空
int empty_queue(queue* Q)
{
	if (Q->front == NULL)
	{
		return 1;
	}
	return 0;
}

//入队
int in_queue(queue* Q, datatype x)
{
	node* newnode = request_node(x);
	if (!newnode)
	{
		return 0;
	}
	if (empty_queue(Q)==0)
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
	else
	{
		Q->front = newnode;
		Q->rear = newnode;
	}
	return 1;
}

//出队
int out_queue(queue* Q, datatype* x)
{
	if (empty_queue(Q))
	{
		printf("空队\n");
		return 0;
	}
	node* p = Q->front;
	*x = p->data;
	Q->front = p->next;
	if (!Q->front)//如果只有一个结点，出队后应该把尾指针也置空
	{
		Q->rear = NULL;
	}
	free(p);
	return 1;
}

//读队首元素
int get_front(queue* Q, datatype* x)
{
	if (empty_queue(Q))
	{
		printf("空队\n");
		return 0;
	}
	*x = Q->front->data;
	return 1;
}

//遍历
void print_queue(queue* Q)
{
	node* p = Q->front;
	printf("front-> ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<-rear\n");
}