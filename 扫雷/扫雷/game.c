#define _CRT_SECURE_NO_WARNINGS

//game.c--��Ϸ���ܺ���
#include "game.h"

void init_board(char arr[ROWS][COLS], int rows, int cols, char ch)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = ch;
		}
	}
}

void set_mine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY;
	int x, y;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}

}

void display_board(char arr[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)
		printf("%d ", i);
	printf("\n");

	

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");


	}

}

void spread(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y, int* win)
{
	int ret = get_mine_count(mine, x, y);
	if (ret > 0)//���>0ֹͣ�ݹ�
	{
		show[x][y] = ret + '0';
		(*win)++;
		return;
	}
	else//�����0�����ݹ�
	{
		show[x][y] = ' ';
		(*win)++;
		//��8������ݹ�
		if (y - 1 != 0 && show[x][y - 1] == '*')
			spread(show, mine, x, y - 1, win);
		if (y + 1 != COL + 1 && show[x][y + 1] != ' ')
			spread(show, mine, x, y + 1, win);

		if (x - 1 != 0 && show[x - 1][y] == '*')
		{
			spread(show, mine, x - 1, y, win);
			if (y - 1 != 0 && show[x - 1][y - 1] == '*')
				spread(show, mine, x - 1, y - 1, win);
			if (y + 1 != COL + 1 && show[x - 1][y + 1] == '*')
				spread(show, mine, x - 1, y + 1, win);
		}

		if (x + 1 != ROW + 1 && show[x + 1][y] == '*')
		{
			spread(show, mine, x + 1, y, win);
			if (y - 1 != 0 && show[x + 1][y - 1] == '*')
				spread(show, mine, x + 1, y - 1, win);
			if (y + 1 != COL + 1 && show[x + 1][y + 1] == '*')
				spread(show, mine, x + 1, y + 1, win);
		}
	}
}

void fine_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int win = 0;
	int* p = &win;
	while (1)
	{
		printf("����������:");
		int x, y;
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9 && show[x][y] == '*')
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը���ˣ��ޡ�����\n");
				display_board(mine, row, col);
				break;
			}
			else
			{
				spread(show,mine, x, y, p);
				display_board(show, ROW, COL);
			}
		}
		else
		{
			printf("����Ƿ���������:\n");

		}
		if (win == row * col - EASY)
		{
			printf("��Ϸʤ����̫�����ˣ�\n");
			break;
		}
		
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	

	return mine[x - 1][y - 1] +
	mine[x - 1][y] +
	mine[x - 1][y + 1] +
	mine[x][y - 1] +
	mine[x][y + 1] +
	mine[x + 1][y - 1] +
	mine[x + 1][y] +
	mine[x + 1][y + 1] - 8* '0';

}


