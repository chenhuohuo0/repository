#define _CRT_SECURE_NO_WARNINGS

//test.c - �����
#include "contact.h"

void menu()
{
	printf("******************\n");
	printf("***** 1.add  *****\n");
	printf("***** 2.del  *****\n");
	printf("**** 3.search ****\n");
	printf("**** 4.modify ****\n");
	printf("***** 5.show *****\n");
	printf("***** 6.sort *****\n");
	printf("***** 0.exit *****\n");
	printf("******************\n");
}
int main()
{
	//����ͨѶ¼����
	struct contact con;
	//��ʼ��ͨѶ¼
	init_contact(&con);
	int input;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:

			add_contact(&con);
			break;
		case del:
			del_contact(&con);
			break;
		case search:
			search_contact(&con);
			break;
		case modify:
			modify_contact(&con);
			break;
		case show:
			show_contact(&con);
			break;
		case sort:
			sort_contact(con.data, con.size);
			break;
		case EXIT:
			destory_contact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("û������ܣ�\n");
			break;
		}
	} while (input);
}