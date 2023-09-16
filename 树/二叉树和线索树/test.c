#define _CRT_SECURE_NO_WARNINGS
#include "btree.h"

int main()
{
	//tree* root = create_tree();
	tree* root = create_tree_2();

	//pre_order(root);
	//printf("\n");
	//pre_oder_2(root);


	/*in_order(root);
	printf("\n");
	in_order_2(root);*/

	/*post_order(root);
	printf("\n");
	post_order_2(root);*/

	/*post_order(root);
	printf("\n");
	post_order_3(root);*/

	//gradation_traverse(root);

	/*int count=count_node(root);
	printf("%d\n", count);*/
	
	/*int h = length_tree(root);
	printf("%d\n", h);
	int num[5] = { 0 };
	level_count(root, num, 1);
	for (int i = 1; i < 5; i++)
	{
		printf("%d ", num[i]);
	}*/

	return 0;
}