//seq_queue.c
#define _CRT_SECURE_NO_WARNINGS
#include "seq_queue.h"


//初始化队列
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

//销毁队列
void destory_queue(queue** Q)
{
	free(*Q);
	*Q = NULL;
}

//判队空
int empty_queue(queue* Q)
{
	if (Q->front == Q->rear && Q)
	{
		return 1;
	}
	return 0;
}

//入队
int in_queue(queue* Q, datatype x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队列已满\n");
		return 0;
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
		return 1;
	}
}

//出队 
//由于队列的内存使静态分配的，为了避免出队时大量移动元素，采用将头指针+1的方式
int out_queue(queue* Q, datatype* x)
{
	if (empty_queue(Q) == 1)
	{
		printf("空队\n");
		return 0;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		*x = Q->data[Q->front];
		return 1;
	}
}

//读队首元素
int get_front(queue* Q, datatype* x)
{
	if (empty_queue(Q) == 1)
	{
		printf("空队\n");
		return 0;
	}
	else
	{
		*x = Q->data[(Q->front + 1) % MAXSIZE];
		return 1;
	}
}

//求队长
size_t length_queue(queue* Q)
{
	return (size_t)Q->rear - Q->front;
}

//遍历
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