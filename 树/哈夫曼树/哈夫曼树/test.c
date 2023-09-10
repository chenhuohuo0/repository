#define _CRT_SECURE_NO_WARNINGS

#include "huftree.h"


int main()
{
	int n = 8;
	int w[8] = { 3,4,8,10,16,18,20,21 };
	htnode huftree[16] = { 0 };
	nodecode cd[9];

	hufcoding(huftree, cd, w, n);

	for (int i = 1; i <= 8; i++)
	{
		printf("%c(%d)->%s\n", cd[i].leaf, huftree[i].weight, cd[i].code);
	}

	return 0;

}