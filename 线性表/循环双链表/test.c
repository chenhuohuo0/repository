#define _CRT_SECURE_NO_WARNINGS
//test.c
#include "cir_dlist.h"
void test()
{
	dlist* H = init_dlist();
	insert_back(H, 0, 1);
	insert_back(H, 1, 3);
	insert_back(H, 1, 2);
	insert_back(H, 0, 0);
	insert_back(H, 4, 4);
	delete_node(H, 1);
	int len = length_dlist(H);
	printf("%d\n", len);
	print_dlist(H);
	printf("%p\n", locate_by_order(H, 4));
	printf("%p\n", locate_by_value(H, 4));



	destory_dlist(H);
}
int main()
{
	test();
	return 0;
}