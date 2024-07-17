#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//雷的布置
	char show[ROWS][COLS] = { 0 };//展示的棋盘

	//初始化
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//布置雷
	set_mine(mine, ROW, COL);

	//展示棋盘
	display_board(mine, ROW, COL);
	display_board(show, ROW, COL);

	//扫雷
	fine_mine(mine,show, ROW, COL);

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
		case 1:game(); break;
		case 0:printf("退出程序\n"); break;
		default:printf("输入错误，请重试:"); break;
		}
	} while (input);

}
