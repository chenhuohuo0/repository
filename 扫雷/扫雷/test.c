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
	char mine[ROWS][COLS] = { 0 };//�׵Ĳ���
	char show[ROWS][COLS] = { 0 };//չʾ������

	//��ʼ��
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//������
	set_mine(mine, ROW, COL);

	//չʾ����
	display_board(mine, ROW, COL);
	display_board(show, ROW, COL);

	//ɨ��
	fine_mine(mine,show, ROW, COL);

}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("�˳�����\n"); break;
		default:printf("�������������:"); break;
		}
	} while (input);

}
