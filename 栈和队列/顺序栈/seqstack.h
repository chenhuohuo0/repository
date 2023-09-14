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

//初始化栈
stack* init_stack();

//判断栈空
int stack_is_empty(stack* H);

//入栈
int push_stack(stack* H, datatype x);

//出栈 - 删除栈顶元素保存在*x
int pop_stack(stack* H, datatype* x);

//取栈顶元素,保存在*x
int get_stack_top(stack* H,datatype* x);

//遍历
void print_stack(stack* H);

//销毁栈
void destory_stack(stack** H);