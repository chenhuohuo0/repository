#define _CRT_SECURE_NO_WARNINGS


//test.c
#include "slist.h"

int main()
{
	slist* H=init_slist();

	insert_back(H, 0, 1);
	insert_back(H, 1, 2);
	insert_back(H, 2, 3);
	delete_node(H, 1);
	print_slist(H);


	destory_slist(H);
	return 0;
}