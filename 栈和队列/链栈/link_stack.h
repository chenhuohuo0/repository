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

//初始化
stack* init_stack();

//判栈空
int stack_is_empty(stack* top);

//压栈
int push_stack(stack** top, datatype x);

//出栈
int pop_stack(stack** top, datatype* x);

//取栈顶元素
int get_stack_top(stack* top, datatype* x);

//遍历
void print_stack(stack* top);

//销毁
void destory_stack(stack** top);