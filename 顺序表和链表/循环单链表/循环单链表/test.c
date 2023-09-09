#define _CRT_SECURE_NO_WARNINGS

#include "cir_slist.h"
void test()
{
	list* R = init_list();
	printf("%d\n", length_list(R));
	insert_back(&R, 0, 1);
	insert_back(&R, 1, 3);
	insert_back(&R, 1, 2);
	insert_back(&R, 3, 5);
	delete_by_order(&R, 4);
	insert_back(&R, 3, 4);
	print_list(R);
	printf("%d\n", length_list(R));

}
int main()
{
	test();
	return 0;
}