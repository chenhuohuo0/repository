#define _CRT_SECURE_NO_WARNINGS
#include "seqstack.h"

//初始化栈
stack* init_stack()
{
	stack* H = (stack*)malloc(sizeof(stack));
	if (!H)
	{
		perror("init_stack error");
		exit(-1);
	}
	H->top = -1;//-1代表栈空
	return H;
}

//判断栈空
int stack_is_empty(stack* H)
{
	if (H->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//入栈 - 在表尾插入
int push_stack(stack* H, datatype x)
{
	if (H->top == MAXSIZE - 1)
	{
		printf("栈满\n");
		return 0;
	}
	H->top++;
	H->data[H->top] = x;
	return 1;
	//1代表入栈成功，0代表失败
}

//出栈 - 删除栈顶元素保存在*x
int pop_stack(stack* H, datatype* x)
{
	if (stack_is_empty(H) == 1)
	{
		printf("栈已空\n");
		return 0;
	}
	*x = H->data[H->top];
	H->top--;
	return 1;
	//1出栈成功，0失败
}

//取栈顶元素,保存在*x
int get_stack_top(stack* H, datatype* x)
{
	if (stack_is_empty(H) == 1)
	{
		printf("栈已空\n");
		return 0;
	}
	*x = H->data[H->top];
	return 1;
}

//遍历
void print_stack(stack* H)
{
	
	for(int i=0;i <= H->top;i++)
	{
		printf("%d  <-  ", H->data[i]);
	}
	printf("top\n");
}

//销毁栈
void destory_stack(stack** H)
{
	free(*H);
	*H = NULL;
}