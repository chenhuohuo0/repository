#define _CRT_SECURE_NO_WARNINGS

#include "btree.h"


//栈相关
stack* init_stack()
{
	stack* S = (stack*)malloc(sizeof(stack));
	S->top = NULL;
	
	return S;
}
void destory_stack(stack** S)
{
	node* p = (*S)->top;
	free(*S);
	*S = NULL;
	while (p)
	{
		node* q = p->next;
		free(p->p_node);
		p = q;
	}
}
int empty_stack(stack* S)
{
	if (S->top)
	{
		return 0;
	}
	return 1;
}
int push_stack(stack* S, tree* p)
{
	node* newnode = (node*)malloc(sizeof(node));
	if (!newnode)
	{
		return 0;
	}
	newnode->p_node = p;
	
	newnode->next = S->top;
	S->top = newnode;
	return 1;
}
int pop_stack(stack* S, tree** p)
{
	if (empty_stack(S))
	{
		return 0;
	}
	*p = S->top->p_node;
	
	node *q = S->top;
	S->top = q->next;
	free(q);
	return 1;
}



//队相关
queue* init_queue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	if (Q)
	{
		Q->front = Q->rear = NULL;
		return Q;
	}
}
void destory_queue(queue** Q)
{
	q_node* p = (*Q)->front;
	while (p != (*Q)->rear)
	{
		q_node* q = p->next;
		free(p);
		p = q;
	}
	free(p);
	free(*Q);
	*Q = NULL;
}
int empty_queue(queue* Q)
{
	if (Q->rear)
	{
		return 0;
	}
	return 1;
}
int in_queue(queue* Q, tree* q)
{
	q_node* newnode = (q_node*)malloc(sizeof(q_node));
	if (!newnode)
	{
		return 0;
	}
	newnode->next = NULL;
	newnode->node = q;
	if (empty_queue(Q))
	{
		Q->front = Q->rear = newnode;
		return 1;
	}
	Q->rear->next = newnode;
	Q->rear = newnode;
	return 1;
}
int out_queue(queue* Q, tree** p)
{
	if (empty_queue(Q))
	{
		return 0;
	}
	q_node* q = Q->front;
	(*p) = q->node;
	Q->front = q->next;
	if (!Q->front)
	{
		Q->rear = NULL;
	}
	free(q);
}



//生成二叉树
tree* create_tree()
{
	printf("结点值为:>");
	
	tree* root = (tree*)malloc(sizeof(tree));
	scanf("%d", &root->data);
	printf("是否为结点%d创建左子树(y/n):>",root->data);
	while (getchar() != '\n')
	{
		;//如果没有接收到\n,就执行空语句
	}
	char c=getchar();
	if (c == 'y')
	{
		root->left=create_tree();
	}
	else
	{
		root->left = NULL;
	}
	printf("是否为结点%d创建右子树(y/n):>", root->data);
	while (getchar() != '\n')
	{
		;//如果没有接收到\n,就执行空语句
	}
	c = getchar();
	if (c == 'y')
	{
		root->right = create_tree();
	}
	else
	{
		root->right = NULL;
	}
	return root;
}

//数组法生成二叉树
tree* create_tree_2()
{
	char c = getchar();
	tree* root = (tree*)malloc(sizeof(tree));
	
	if (c == '#')
	{
		free(root);
		root = NULL;
	}
	else
	{
		root->data = c - '0';
		root->left = create_tree_2();
		root->right = create_tree_2();
	}
	return root;
}

//访问结点
void visit(datatype x)
{
	printf("%d ", x);
}

//先序遍历
void pre_order(tree* root)
{
	if (root)
	{
		visit(root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

//利用栈的先序遍历的非递归算法
void pre_oder_2(tree* root)
{
	stack* S = init_stack();
	tree* p = root;
	
	while (p || !empty_stack(S))
	{
		if (p)
		{
			push_stack(S, p);
			visit(p->data);
			p = p->left;
		}
		else
		{
			pop_stack(S, &p);
			p = p->right;
		}
	}
	destory_stack(&S);
}

//中序遍历
void in_order(tree* root)
{
	if (root)
	{
		in_order(root->left);
		visit(root->data);
		in_order(root->right);
	}
}

//利用栈的中序遍历的非递归算法
void in_order_2(tree* root)
{
	stack* S = init_stack();
	tree* p = root;
	while (p||!empty_stack(S))
	{
		if (p)
		{
			push_stack(S, p);
			p = p->left;
		}
		else
		{
			pop_stack(S, &p);
			visit(p->data);
			p = p->right;
		}
	}
}

//后序遍历
void post_order(tree* root)
{
	if (root)
	{
		post_order(root->left);
		post_order(root->right);
		visit(root->data);
	}
}

//利用栈的后序遍历的非递归算法
//法1 - 利用两个栈
void post_order_2(tree* root)
{
	stack* S1 = init_stack();
	stack* S2 = init_stack();
	tree* p = root;
	while (p || !empty_stack(S2))
	{
		if (p)
		{
			push_stack(S1, p);
			push_stack(S2, p);
			p = p->right;
		}
		else
		{
			pop_stack(S2, &p);
			p = p->left;
		}
	}
	while (!empty_stack(S1))
	{
		pop_stack(S1, &p);
		visit(p->data);
	}
}

//法2 - 利用一个栈和一个标记
void post_order_3(tree* root)
{
	stack* S = init_stack();
	tree* p = root;
	while (p || !empty_stack(S))
	{
		if (p)
		{
			push_stack(S, p);
			S->top->flag = 0;
			p = p->left;
		}
		else
		{
			if (S->top->flag == 0)
			{
				S->top->flag = 1;
				pop_stack(S, &p);
				push_stack(S, p);
				p = p->right;
			}
			else
			{
				pop_stack(S, &p);
				visit(p->data);
				p = NULL;
			}
		}
	}
}

//层次遍历法
void gradation_traverse(tree* root)
{
	tree* p = root;
	queue* Q = init_queue();
	in_queue(Q, p);
	while (!empty_queue(Q))
	{
		out_queue(Q, &p);
		visit(p->data);
		if (p->left)
		{
			in_queue(Q,p->left);
		}
		if (p->right)
		{
			in_queue(Q, p->right);
		}
	}
}

//计算结点个数
int count_node(tree* root)
{
	if (root)
	{
		return 1 + count_node(root->left) + count_node(root->right);
	}
	return 0;
}

//求树的高度
int length_tree(tree* root)
{
	int h, h1, h2;
	if (!root)
	{
		return 0;
	}
	h1 = length_tree(root->left);
	h2 = length_tree(root->right);
	h=h1 > h2 ?  1+h1 : 1+h2;
	return h;
}

//求每一层的结点个数，把信息存入数组中
void level_count(tree* root, int num[], int L)
{
	if (root)
	{
		num[L]++;
		level_count(root->left, num, L + 1);
		level_count(root->right, num, L + 1);
	}
}