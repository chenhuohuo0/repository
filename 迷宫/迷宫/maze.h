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

//��ʼ��ջ
stack* init_stack();

//�ж�ջ��
int empty_stack(stack* S);

//��ջ
int push_stack(stack* S, node temp);

//��ջ - ɾ��ջ��Ԫ�ر�����*x
int pop_stack(stack* S, node* temp);

//����ջ
void destory_stack(stack** S);


//�Թ�Ѱ�ҿ���·����������ҵ�����1������0
int path_maze(int maze[m + 2][n + 2], item move[4], int x0, int y0);
