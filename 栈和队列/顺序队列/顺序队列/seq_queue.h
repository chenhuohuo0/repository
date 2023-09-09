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

//��ʼ������
queue* init_queue();

//���ٶ���
void destory_queue(queue** Q);

//�жӿ�
int empty_queue(queue* Q);

//���
int in_queue(queue* Q, datatype x);

//����
int out_queue(queue* Q, datatype* x);

//������Ԫ��
int get_front(queue* Q, datatype* x);

//��ӳ�
size_t length_queue(queue* Q);

//����
void print_queue(queue* Q);