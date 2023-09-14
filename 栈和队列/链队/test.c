#define _CRT_SECURE_NO_WARNINGS

//test.c
#include "link_queue.h"


int main()
{
	queue* Q = init_queue();
	in_queue(Q, 1);
	in_queue(Q, 2);
	in_queue(Q, 3);
	in_queue(Q, 4);

	int x;
	out_queue(Q, &x);
	get_front(Q, &x);

	print_queue(Q);
	printf("%d\n", x);


	destory_queue(&Q);
}