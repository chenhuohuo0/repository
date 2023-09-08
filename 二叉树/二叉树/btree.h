#pragma once

#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
typedef int datatype;

typedef struct binary_tree
{
	datatype data;
	struct binary_tree* left;
	struct binary_tree* right;
}tree;

//typedef struct stack_node
//{
//	struct binary_tree* p_node;
//	struct stack_node* next;
//}node;

typedef struct stack
{
	struct stack_node* top;
}stack;






//��ѯ�����ɶ�����
tree* create_tree();

//���鷨���ɶ�����
tree* create_tree_2();

//���ʽ��
void visit(datatype x);

//�������
void pre_order(tree* root);

//����ջ����������ķǵݹ��㷨
void pre_oder_2(tree* root);

//�������
void in_order(tree* root);

//����ջ����������ķǵݹ��㷨
void in_order_2(tree* root);

//�������
void post_order(tree* root);

//����ջ�ĺ�������ķǵݹ��㷨
//��1 - ��������ջ
void post_order_2(tree* root);

//��2 - ����һ��ջ��һ�����,
//��ջ�����ʱ��һ��flag�ֶ�,ѹջ��ջʱ�޸�flag
typedef struct stack_node
{
	struct binary_tree* p_node;
	int flag;
	struct stack_node* next;
}node;
void post_order_3(tree* root);

//��α�����
typedef struct queue_node
{
	struct binary_tree* node;
	struct queue_node* next;
}q_node;
typedef struct queue
{
	struct queue_node* front, *rear;
}queue;
/*      1.���ʸ���㣬������������
        2.while(�Ӳ���)
		(1)����һ�����
		(2)����ý�������ӣ����������Ӳ����
		(3)����ý�����Һ��ӣ��������Һ��Ӳ���� */
void gradation_traverse(tree* root);

//���������
int count_node(tree* root);

//�����ĸ߶�
int length_tree(tree* root);

//��ÿһ��Ľ�����������Ϣ����������
void level_count(tree* root, int num[], int L);

