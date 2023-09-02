#define _CRT_SECURE_NO_WARNINGS
#include "seqstack.h"

//��ʼ��ջ
stack* init_stack()
{
	stack* H = (stack*)malloc(sizeof(stack));
	if (!H)
	{
		perror("init_stack error");
		exit(-1);
	}
	H->top = -1;//-1����ջ��
	return H;
}

//�ж�ջ��
int stack_is_empty(stack* H)
{
	if (H->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��ջ - �ڱ�β����
int push_stack(stack* H, datatype x)
{
	if (H->top == MAXSIZE - 1)
	{
		printf("ջ��\n");
		return 0;
	}
	H->top++;
	H->data[H->top] = x;
	return 1;
	//1������ջ�ɹ���0����ʧ��
}

//��ջ - ɾ��ջ��Ԫ�ر�����*x
int pop_stack(stack* H, datatype* x)
{
	if (stack_is_empty(H) == 1)
	{
		printf("ջ�ѿ�\n");
		return 0;
	}
	*x = H->data[H->top];
	H->top--;
	return 1;
	//1��ջ�ɹ���0ʧ��
}

//ȡջ��Ԫ��,������*x
int get_stack_top(stack* H, datatype* x)
{
	if (stack_is_empty(H) == 1)
	{
		printf("ջ�ѿ�\n");
		return 0;
	}
	*x = H->data[H->top];
	return 1;
}

//����
void print_stack(stack* H)
{
	
	for(int i=0;i <= H->top;i++)
	{
		printf("%d  <-  ", H->data[i]);
	}
	printf("top\n");
}

//����ջ
void destory_stack(stack** H)
{
	free(*H);
	*H = NULL;
}