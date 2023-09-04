#pragma once
#define datatype int

#include<stdio.h>
#include<stdlib.h>




typedef struct node
{
	datatype data;
	struct node* next;
}node;

typedef struct link_queue
{
	node* front;
	node* rear;
}queue;

//初始化
queue* init_queue();

//销毁
void destory_queue(queue** Q);

//判队空
int empty_queue(queue* Q);

//入队
int in_queue(queue* Q, datatype x);

//出队
int out_queue(queue* Q, datatype* x);

//读队首元素
int get_front(queue* Q, datatype* x);

//遍历
void print_queue(queue* Q);