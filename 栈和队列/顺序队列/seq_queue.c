//seq_queue.c
#define _CRT_SECURE_NO_WARNINGS
#include "seq_queue.h"


//��ʼ������
queue* init_queue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	if (!Q)
	{
		perror("init_queue");
		exit(-1);
	}
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

//���ٶ���
void destory_queue(queue** Q)
{
	free(*Q);
	*Q = NULL;
}

//�жӿ�
int empty_queue(queue* Q)
{
	if (Q->front == Q->rear && Q)
	{
		return 1;
	}
	return 0;
}

//���
int in_queue(queue* Q, datatype x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("��������\n");
		return 0;
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
		return 1;
	}
}

//���� 
//���ڶ��е��ڴ�ʹ��̬����ģ�Ϊ�˱������ʱ�����ƶ�Ԫ�أ����ý�ͷָ��+1�ķ�ʽ
int out_queue(queue* Q, datatype* x)
{
	if (empty_queue(Q) == 1)
	{
		printf("�ն�\n");
		return 0;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		*x = Q->data[Q->front];
		return 1;
	}
}

//������Ԫ��
int get_front(queue* Q, datatype* x)
{
	if (empty_queue(Q) == 1)
	{
		printf("�ն�\n");
		return 0;
	}
	else
	{
		*x = Q->data[(Q->front + 1) % MAXSIZE];
		return 1;
	}
}

//��ӳ�
size_t length_queue(queue* Q)
{
	return (size_t)Q->rear - Q->front;
}

//����
void print_queue(queue* Q)
{
	printf("front-> ");
	int p= (Q->front + 1) % MAXSIZE;
	int len = length_queue(Q);
	for(int i=0;i<len;i++)
	{
		printf("%d ", Q->data[p]);
		p = (p + 1) % MAXSIZE;
	}
	printf("<- rear\n");
}