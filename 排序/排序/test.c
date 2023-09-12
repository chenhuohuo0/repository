#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
int main()
{
	list s = { {-1,75,88,68,92,88,62,77,96,80,72},10 };
	//straight_insert_sort(&s);//结构体尽量采用传址调用
	//binary_insert_sort(&s);
	//int gaps[] = { 5,2,1 };
	//shell_sort(&s, gaps, 3);
	//bubble_sort(&s);
	//quick_sort(&s, 1, 10);
	//select_sort(&s);
	//heap_sort(&s);
	merge_sort(&s, 1, 10);
	print_list(&s);







	return 0;
}