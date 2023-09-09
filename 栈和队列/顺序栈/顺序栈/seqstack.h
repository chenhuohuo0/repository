#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define datatype int
#define MAXSIZE 10


typedef struct seq_stack
{
	datatype data[MAXSIZE];
	int top;
}stack;

//��ʼ��ջ
stack* init_stack();

//�ж�ջ��
int stack_is_empty(stack* H);

//��ջ
int push_stack(stack* H, datatype x);

//��ջ - ɾ��ջ��Ԫ�ر�����*x
int pop_stack(stack* H, datatype* x);

//ȡջ��Ԫ��,������*x
int get_stack_top(stack* H,datatype* x);

//����
void print_stack(stack* H);

//����ջ
void destory_stack(stack** H);