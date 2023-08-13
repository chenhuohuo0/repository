#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
//��ʼ������
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

//չʾ����
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

//�������
void player_move(char arr[ROW][COL], int row, int col)
{
	
	int x, y;
	while (1)//�ж���������Ƿ�Ϸ�
	{
		printf("�����:\n");
		printf("����������:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3&&arr[x-1][y-1]==' ')
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("��Ҫ����Ŷ~~~\n");
	}
}

//��������
void computer_move(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("������:\n");
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

//�ж���Ϸ״̬
//1--��һ�ʤ������*
//2--���Ի�ʤ������#
//3--������������f
//4--��Ϸ����������k
char is_win(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)//��3
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}

	}

	for (j = 0; j < col; j++)//��3
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return arr[0][j];
		}
	}
	//���Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	//���Խ���
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] !=' ')
	{
		return arr[1][1];
	}

	//�ж������Ƿ���
	if (1 == is_full(arr, ROW, COL))
		return 'f';
	else
		return 'k';
}

//�ж������Ƿ���
//���˷���1
//û������0
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
