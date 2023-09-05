#define _CRT_SECURE_NO_WARNINGS
#include "maze.h"

//初始化栈
stack* init_stack()
{
	stack* S = (stack*)malloc(sizeof(stack));
	if (S)
	{
		S->top = -1;//-1代表栈空
	}
	return S;
}

//判断栈空
int empty_stack(stack* S)
{
	if (S->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//入栈 
int push_stack(stack* S, node temp)
{
	if (S->top == MAXSIZE - 1)
	{
		printf("栈满\n");
		return 0;
	}
	S->top++;
	S->data[S->top].x = temp.x;
	S->data[S->top].y = temp.y;
	S->data[S->top].d = temp.d;
	return 1;
}

//出栈 
int pop_stack(stack* S, node* temp)
{
	if (empty_stack(S) == 1)
	{
		printf("栈已空\n");
		return 0;
	}
	(*temp).x = S->data[S->top].x;
	(*temp).y = S->data[S->top].y;
	(*temp).d = S->data[S->top].d;
	S->top--;
	return 1;
}


//销毁栈
void destory_stack(stack** S)
{
	free(*S);
	*S = NULL;
}


//迷宫寻找可行路径并输出，找到返回1，否则0
int path_maze(int maze[m + 2][n + 2], item move[4], int x0, int y0)
{
	int x, y, i, j, d;
	node temp;
	maze[x0][y0] = -1;
	temp.x = x0;
	temp.y = y0;
	temp.d = -1;

	stack* S = init_stack();
	push_stack(S, temp);
	while (!empty_stack(S))
	{
		pop_stack(S, &temp);
		x = temp.x; y = temp.y; d = temp.d+1;
		while (d < 4)//每次循环试探某一个方向
		{
			i = x + move[d].x; j = y + move[d].y;
			if (maze[i][j] == 0)//发现这个方向可行
			{
				temp.x = x;
				temp.y = y;
				temp.d = d;
				push_stack(S, temp);//把上一步的位置入栈
				x = i; y = j;//向前走一步
				maze[x][y] = -1;//标记
				if (x == m && y == n)//如果这一步是终点
				{
					printf("终点<-");
					while (!empty_stack(S))
					{
						pop_stack(S, &temp);
						if (temp.x == x0 && temp.y == y0)
						{
							printf("起点\n");
						}
						else
						{
							printf("(%d %d)<-", temp.x, temp.y);
						}
					}
					destory_stack(&S);
					return 1;
				}
				else
				{
					d = 0;
				}
			}
			else
			{
				d++;//换个方向重试
			}
		}
	}
	destory_stack(&S);
	return 0;
}