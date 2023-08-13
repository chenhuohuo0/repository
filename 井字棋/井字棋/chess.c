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
	display_board(arr, ROW, COL);//չʾ����
	while (1)
	{

		player_move(arr, ROW, COL);//�����
		display_board(arr, ROW, COL);//չʾ����
		//�жϴ�ʱ����Ϸ״̬
		if ('*' == is_win(arr, ROW, COL))
		{
			printf("��Ӯ�ˣ���������\n");
			break;
		}
		if ('f' == is_win(arr, ROW, COL))
		{
			printf("ƽ�֣�����൱\n");
			break;
		}

		computer_move(arr, ROW, COL);//������
		display_board(arr, ROW, COL);//չʾ����
		//�жϴ�ʱ����Ϸ״̬
		if ('#' == is_win(arr, ROW, COL))
		{
			printf("�����ˣ�������ң�����������\n");
			break;
		}
		if ('f' == is_win(arr, ROW, COL))
		{
			printf("ƽ�֣�����൱\n");
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
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:chess(); break;
		case 0:printf("�˳�����\n"); break;
		default:printf("�������������:\n"); break;
		}
	} while (input);

}