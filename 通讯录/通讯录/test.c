#define _CRT_SECURE_NO_WARNINGS

//test.c - 主框架
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
	//创建通讯录对象
	struct contact con;
	//初始化通讯录
	init_contact(&con);
	int input;
	do
	{
		menu();
		printf("请选择:>");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("没有这项功能！\n");
			break;
		}
	} while (input);
}