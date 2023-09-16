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






//问询法生成二叉树
tree* create_tree();

//数组法生成二叉树
tree* create_tree_2();

//访问结点
void visit(datatype x);

//先序遍历
void pre_order(tree* root);

//利用栈的先序遍历的非递归算法
void pre_oder_2(tree* root);

//中序遍历
void in_order(tree* root);

//利用栈的中序遍历的非递归算法
void in_order_2(tree* root);

//后序遍历
void post_order(tree* root);

//利用栈的后序遍历的非递归算法
//法1 - 利用两个栈
void post_order_2(tree* root);

//法2 - 利用一个栈和一个标记,
//将栈结点暂时加一个flag字段,压栈出栈时修改flag
typedef struct stack_node
{
	struct binary_tree* p_node;
	int flag;
	struct stack_node* next;
}node;
void post_order_3(tree* root);

//层次遍历法
typedef struct queue_node
{
	struct binary_tree* node;
	struct queue_node* next;
}q_node;
typedef struct queue
{
	struct queue_node* front, *rear;
}queue;
/*      1.访问根结点，并将根结点入队
        2.while(队不空)
		(1)出队一个结点
		(2)如果该结点有左孩子，访问其左孩子并入队
		(3)如果该结点有右孩子，访问其右孩子并入队 */
void gradation_traverse(tree* root);

//计算结点个数
int count_node(tree* root);

//求树的高度
int length_tree(tree* root);

//求每一层的结点个数，把信息存入数组中
void level_count(tree* root, int num[], int L);

