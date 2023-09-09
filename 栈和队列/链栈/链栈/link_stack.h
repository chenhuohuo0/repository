#define _CRT_SECURE_NO_WARNINGS

//link_stack.h
#define datatype int
#include<stdio.h>
#include<stdlib.h>

typedef struct link_stack
{
	datatype data;
	struct link_stack* next;
}stack;

//��ʼ��
stack* init_stack();

//��ջ��
int stack_is_empty(stack* top);

//ѹջ
int push_stack(stack** top, datatype x);

//��ջ
int pop_stack(stack** top, datatype* x);

//ȡջ��Ԫ��
int get_stack_top(stack* top, datatype* x);

//����
void print_stack(stack* top);

//����
void destory_stack(stack** top);