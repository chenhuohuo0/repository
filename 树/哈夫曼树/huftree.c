#define _CRT_SECURE_NO_WARNINGS

#include "huftree.h"

//哈夫曼算法
void hufcoding(htnode huftree[], nodecode cd[], int w[], int n)
{
	int i,s1,s2;
	char* temp = (char*)malloc(n);
	//初始化静态链表，把n个叶子结点的值和权值存入，父母孩子都置为-1
	for (i = 1; i <= n; i++)
	{
		huftree[i].ch = getchar();
		huftree[i].weight = w[i - 1];
		huftree[i].parent = huftree[i].lchild = huftree[i].rchild = -1;
	}
	//开始补齐后面n-1个结点
	for (i = n + 1; i < 2*n; i++)
	{
		//找当前已有的没父母结点的权值最小和次小的结点下标分别存入s1和s2
		select2max(huftree, i - 1, &s1, &s2);
		huftree[i].weight = huftree[s1].weight + huftree[s2].weight;
		huftree[i].lchild = s1;
		huftree[i].rchild = s2;
		huftree[i].parent = -1;
		huftree[s1].parent = huftree[s2].parent = i;
	}
	//开始求前n个结点(叶子结点)的编码
	for (i = 1; i <= n; i++)
	{
		int c = 0;
		//从叶子往根查看每一个分支是左还是右
		int j = i;
		while (huftree[j].parent != -1)
		{
			
			//如果这个结点是左孩子
			if (huftree[huftree[j].parent].lchild == j)
			{
				temp[c] = '0';
				c++;
			}
			else
			{
				temp[c] = '1';
				c++;
			}
			j = huftree[j].parent;
		}
		cd[i].code = (char*)malloc(c+1);
		int k = 0;
		c--;
		while (c>=0)
		{
			cd[i].code[k++] = temp[c--];
		}
		cd[i].code[k] = '\0';
		cd[i].leaf = huftree[i].ch;
		cd[i].length = k;
	}
	free(temp);
}


//找最小和次小
void select2max(htnode huftree[], int len, int* s1, int* s2)
{
	int i = 1; int a, b;
	while(i<=len)
	{
		if (huftree[i].parent == -1)//先找一个没父母的结点作为a
		{
			a = i;
			break;
		}
		i++;
	}
	i++;
	while (i <= len)
	{
		if (huftree[i].parent == -1)//再找一个没父母的结点为b
		{
			b = i;
			break;
		}
		i++;
	}
	//如果下标为a的结点权值比下标为b的结点权值更大，则交换ab
	if (huftree[a].weight > huftree[b].weight)
	{
		int t = a; a = b; b = t;
	}
	//ab此时一定是没父母的结点中下标最小的两个结点，所以循环可以从i+1开始
	for (i = i + 1; i <= len; i++)
	{
		//只处理没妈的孩子
		if (huftree[i].parent == -1)
		{
			//比ab权值还小
			if (huftree[i].weight < huftree[a].weight)
			{
				b = a; a = i;
			}
			//大于a小于b
			else if (huftree[i].weight > huftree[a].weight&&huftree[i].weight < huftree[b].weight)
			{
				b = i;
			}
			else
				continue;
		}
	}
	*s1 = a;
	*s2 = b;
}