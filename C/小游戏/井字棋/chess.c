#define _CRT_SECURE_NO_WARNINGS

#include "chess.h"

void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");
}

void chess()
{
	char arr[ROW][COL] = { 0 };
	init_board(arr, ROW, COL);
	display_board(arr, ROW, COL);//展示棋盘
	while (1)
	{

		player_move(arr, ROW, COL);//玩家下
		display_board(arr, ROW, COL);//展示棋盘
		//判断此时的游戏状态
		if ('*' == is_win(arr, ROW, COL))
		{
			printf("你赢了！真厉害！\n");
			break;
		}
		if ('f' == is_win(arr, ROW, COL))
		{
			printf("平局，旗鼓相当\n");
			break;
		}

		computer_move(arr, ROW, COL);//电脑下
		display_board(arr, ROW, COL);//展示棋盘
		//判断此时的游戏状态
		if ('#' == is_win(arr, ROW, COL))
		{
			printf("你输了，你是输家，哭着找妈妈\n");
			break;
		}
		if ('f' == is_win(arr, ROW, COL))
		{
			printf("平局，旗鼓相当\n");
			break;
		}
	}
}




int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:chess(); break;
		case 0:printf("退出程序\n"); break;
		default:printf("输入错误，请重试:\n"); break;
		}
	} while (input);

}