//seq_queue.h
#pragma once
#define datatype int
#define MAXSIZE 10 

#include<stdio.h>
#include<stdlib.h>


typedef struct seq_queue
{
	datatype data[MAXSIZE];
	int front, rear;
}queue;

//初始化队列
queue* init_queue();

//销毁队列
void destory_queue(queue** Q);

//判队空
int empty_queue(queue* Q);

//入队
int in_queue(queue* Q, datatype x);

//出队
int out_queue(queue* Q, datatype* x);

//读队首元素
int get_front(queue* Q, datatype* x);

//求队长
size_t length_queue(queue* Q);

//遍历
void print_queue(queue* Q);