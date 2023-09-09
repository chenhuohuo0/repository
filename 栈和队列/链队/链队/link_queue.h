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

//��ʼ��
queue* init_queue();

//����
void destory_queue(queue** Q);

//�жӿ�
int empty_queue(queue* Q);

//���
int in_queue(queue* Q, datatype x);

//����
int out_queue(queue* Q, datatype* x);

//������Ԫ��
int get_front(queue* Q, datatype* x);

//����
void print_queue(queue* Q);