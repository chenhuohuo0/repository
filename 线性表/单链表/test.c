#define _CRT_SECURE_NO_WARNINGS

//test.c
#include "slist.h"
int main()
{
	slist* ph = init_slist();
	insert_slist(ph, 0, 3);
	insert_slist(ph, 0, 2);
	insert_slist(ph, 0, 1);
	insert_slist(ph, 3, 4);
	insert_slist(ph, 4, 5);
	//printf("%d\n",search_by_order(ph, 5)->data);
	//printf("%p\n", search_by_order(ph, 1));
	//modify_slist(ph, 1, 5);
	//printf("%p\n", search_by_value(ph, 5));
	print_slist(ph);
	printf("%d\n", length_slist(ph));

	destory_slist(&ph);
	return 0;
}