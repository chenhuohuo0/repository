#define _CRT_SECURE_NO_WARNINGS

#include "huftree.h"

//�������㷨
void hufcoding(htnode huftree[], nodecode cd[], int w[], int n)
{
	int i,s1,s2;
	char* temp = (char*)malloc(n);
	//��ʼ����̬������n��Ҷ�ӽ���ֵ��Ȩֵ���룬��ĸ���Ӷ���Ϊ-1
	for (i = 1; i <= n; i++)
	{
		huftree[i].ch = getchar();
		huftree[i].weight = w[i - 1];
		huftree[i].parent = huftree[i].lchild = huftree[i].rchild = -1;
	}
	//��ʼ�������n-1�����
	for (i = n + 1; i < 2*n; i++)
	{
		//�ҵ�ǰ���е�û��ĸ����Ȩֵ��С�ʹ�С�Ľ���±�ֱ����s1��s2
		select2max(huftree, i - 1, &s1, &s2);
		huftree[i].weight = huftree[s1].weight + huftree[s2].weight;
		huftree[i].lchild = s1;
		huftree[i].rchild = s2;
		huftree[i].parent = -1;
		huftree[s1].parent = huftree[s2].parent = i;
	}
	//��ʼ��ǰn�����(Ҷ�ӽ��)�ı���
	for (i = 1; i <= n; i++)
	{
		int c = 0;
		//��Ҷ�������鿴ÿһ����֧��������
		int j = i;
		while (huftree[j].parent != -1)
		{
			
			//���������������
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


//����С�ʹ�С
void select2max(htnode huftree[], int len, int* s1, int* s2)
{
	int i = 1; int a, b;
	while(i<=len)
	{
		if (huftree[i].parent == -1)//����һ��û��ĸ�Ľ����Ϊa
		{
			a = i;
			break;
		}
		i++;
	}
	i++;
	while (i <= len)
	{
		if (huftree[i].parent == -1)//����һ��û��ĸ�Ľ��Ϊb
		{
			b = i;
			break;
		}
		i++;
	}
	//����±�Ϊa�Ľ��Ȩֵ���±�Ϊb�Ľ��Ȩֵ�����򽻻�ab
	if (huftree[a].weight > huftree[b].weight)
	{
		int t = a; a = b; b = t;
	}
	//ab��ʱһ����û��ĸ�Ľ�����±���С��������㣬����ѭ�����Դ�i+1��ʼ
	for (i = i + 1; i <= len; i++)
	{
		//ֻ����û��ĺ���
		if (huftree[i].parent == -1)
		{
			//��abȨֵ��С
			if (huftree[i].weight < huftree[a].weight)
			{
				b = a; a = i;
			}
			//����aС��b
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