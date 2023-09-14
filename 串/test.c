#define _CRT_SECURE_NO_WARNINGS
#include "seqstring.h"
int main()
{
	////第一种顺序存储方式
	//string s = { "abcaababc", 9 };//定义一个串变量
	//int n = s.length;//这种方式可以直接得到串长

	//第三种
	/*char s[19];
	s[0] = 18;
	char s1[] = "aabcbabcaabcaababc";
	int i = 0;
	while (s1[i])
	{
		s[i + 1] = s1[i];
		i++;
	}*/
	char t[10];
	t[0] = 9;
	char t1[] = "abcaababc";
	int j = 0;
	while (t1[j])
	{
		t[j + 1] = t1[j];
		j++;
	}

	//char *p = str_BF(s, t);

	int next[10];
	//getnext(t, next);

	//char* p=str_KMP(s, t);
	//printf(p);

	getnext_recursion(t, next, 9);

	int i;
	for (i = 1; i < 10; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");
	int nextval[10];
	get_nextval(t, next, nextval, 10);
	for (i = 1; i < 10; i++)
	{
		printf("%d ", nextval[i]);
	}
	return 0;
}