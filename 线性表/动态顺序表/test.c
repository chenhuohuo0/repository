#define _CRT_SECURE_NO_WARNINGS

//test.c
#include "seqlist.h"
void test()
{
	seqlist s;
	//³õÊ¼»¯
	init_seq(&s);


	insert_seq(&s, 0, 0);
	insert_seq(&s, 1, 1);
	insert_seq(&s, 2, 3);
	insert_seq(&s, 3, 4);
	insert_seq(&s, 4, 2);
	insert_seq(&s, 5, 6);
	insert_seq(&s, 5, 5);
	print_seq(&s);
	order_seq(&s, cmp_int);
	modify_seq(&s, 6, 666);
	delelt_seq(&s, 0);
	print_seq(&s);
	printf("%d\n",search_seq(&s, 666));

	//modify_seq(&s,4,4);
	//delete_seq(&s,5);


	//Ïú»Ù
	des_seq(&s);
}

int main()
{
	test();
	return 0;
}