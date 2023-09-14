//test.c
#define _CRT_SECURE_NO_WARNINGS
#include "seq_queue.h"

int main()
{
	queue* Q = init_queue();
	in_queue(Q, 1);
	in_queue(Q, 2);
	in_queue(Q, 3);
	in_queue(Q, 4);
	in_queue(Q, 5);
	in_queue(Q, 6);
	in_queue(Q, 7);

	int x;
	out_queue(Q, &x);
	get_front(Q, &x);

	print_queue(Q);
	printf("%d\n", x);


	destory_queue(&Q);
}