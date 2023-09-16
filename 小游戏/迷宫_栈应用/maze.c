#define _CRT_SECURE_NO_WARNINGS
#include "maze.h"

//��ʼ��ջ
stack* init_stack()
{
	stack* S = (stack*)malloc(sizeof(stack));
	if (S)
	{
		S->top = -1;//-1����ջ��
	}
	return S;
}

//�ж�ջ��
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

//��ջ 
int push_stack(stack* S, node temp)
{
	if (S->top == MAXSIZE - 1)
	{
		printf("ջ��\n");
		return 0;
	}
	S->top++;
	S->data[S->top].x = temp.x;
	S->data[S->top].y = temp.y;
	S->data[S->top].d = temp.d;
	return 1;
}

//��ջ 
int pop_stack(stack* S, node* temp)
{
	if (empty_stack(S) == 1)
	{
		printf("ջ�ѿ�\n");
		return 0;
	}
	(*temp).x = S->data[S->top].x;
	(*temp).y = S->data[S->top].y;
	(*temp).d = S->data[S->top].d;
	S->top--;
	return 1;
}


//����ջ
void destory_stack(stack** S)
{
	free(*S);
	*S = NULL;
}


//�Թ�Ѱ�ҿ���·����������ҵ�����1������0
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
		while (d < 4)//ÿ��ѭ����̽ĳһ������
		{
			i = x + move[d].x; j = y + move[d].y;
			if (maze[i][j] == 0)//��������������
			{
				temp.x = x;
				temp.y = y;
				temp.d = d;
				push_stack(S, temp);//����һ����λ����ջ
				x = i; y = j;//��ǰ��һ��
				maze[x][y] = -1;//���
				if (x == m && y == n)//�����һ�����յ�
				{
					printf("�յ�<-");
					while (!empty_stack(S))
					{
						pop_stack(S, &temp);
						if (temp.x == x0 && temp.y == y0)
						{
							printf("���\n");
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
				d++;//������������
			}
		}
	}
	destory_stack(&S);
	return 0;
}