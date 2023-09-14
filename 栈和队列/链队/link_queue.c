#define _CRT_SECURE_NO_WARNINGS

//link_queue.c
#include "link_queue.h"


//����һ�����
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

//��ʼ��
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

//����
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

//�жӿ�
int empty_queue(queue* Q)
{
	if (Q->front == NULL)
	{
		return 1;
	}
	return 0;
}

//���
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

//����
int out_queue(queue* Q, datatype* x)
{
	if (empty_queue(Q))
	{
		printf("�ն�\n");
		return 0;
	}
	node* p = Q->front;
	*x = p->data;
	Q->front = p->next;
	if (!Q->front)//���ֻ��һ����㣬���Ӻ�Ӧ�ð�βָ��Ҳ�ÿ�
	{
		Q->rear = NULL;
	}
	free(p);
	return 1;
}

//������Ԫ��
int get_front(queue* Q, datatype* x)
{
	if (empty_queue(Q))
	{
		printf("�ն�\n");
		return 0;
	}
	*x = Q->front->data;
	return 1;
}

//����
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