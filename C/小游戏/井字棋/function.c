#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
//初始化棋盘
void init_board(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] =' ';
		}
	}
}

//展示棋盘
void display_board(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家下棋
void player_move(char arr[ROW][COL], int row, int col)
{
	
	int x, y;
	while (1)//判断玩家输入是否合法
	{
		printf("玩家走:\n");
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3&&arr[x-1][y-1]==' ')
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("不要乱来哦~~~\n");
	}
}

//电脑下棋
void computer_move(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走:\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}

}

//判断游戏状态
//1--玩家获胜，返回*
//2--电脑获胜，返回#
//3--棋盘满，返回f
//4--游戏继续，返回k
char is_win(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)//横3
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}

	}

	for (j = 0; j < col; j++)//竖3
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return arr[0][j];
		}
	}
	//正对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	//反对角线
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] !=' ')
	{
		return arr[1][1];
	}

	//判断棋盘是否满
	if (1 == is_full(arr, ROW, COL))
		return 'f';
	else
		return 'k';
}

//判断棋盘是否满
//满了返回1
//没满返回0
int is_full(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] ==  ' ')
				return 0;
		}
	}
	return 1;
}
