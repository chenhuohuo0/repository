#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define m 6
#define n 8
#define MAXSIZE 30

typedef struct item
{
	int x, y;
}item;

typedef struct node
{
	int x, y, d;
}node;


typedef struct seq_stack
{
	node data[MAXSIZE];
	int top;
}stack;

//初始化栈
stack* init_stack();

//判断栈空
int empty_stack(stack* S);

//入栈
int push_stack(stack* S, node temp);

//出栈 - 删除栈顶元素保存在*x
int pop_stack(stack* S, node* temp);

//销毁栈
void destory_stack(stack** S);


//迷宫寻找可行路径并输出，找到返回1，否则0
int path_maze(int maze[m + 2][n + 2], item move[4], int x0, int y0);
