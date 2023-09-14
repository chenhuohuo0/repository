#define _CRT_SECURE_NO_WARNINGS
#include "seqstring.h"
//BF�㷨
char* str_BF(char* s, char* t)
{
	int i = 1, j = 1;
	while ( i <= s[0] && j <= t[0] )
	{
		if (s[i] == t[j])
		{
			i++; j++;
		}
		else//����
		{
			i = i - j + 2;
			j = 1;
		}	
	}
	if(j>t[0])//����ܹ�������t�ʹ���ɹ�
	{
		return &s[i - j + 1];
	}	
	else
	{
		return NULL;
	}
}


//��next����
void getnext(char *t, int next[])
{
	next[1] = 0;
	int i = 1, j = 0;
	while (i < t[0])
	{
		if (t[i] == t[j] || j == 0)
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
}



//KMP�㷨
char* str_KMP(char* s, char* t)
{
	int next[10];
	getnext(t, next);
	int i = 1, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (s[i] == t[j]||j==0)
		{
			i++; j++;
		}
		else//����
		{
			j = next[j];
		}
	}
	if (j > t[0])//����ܹ�������t�ʹ���ɹ�
	{
		return &s[i - j + 1];
	}
	else
	{
		return NULL;
	}
}


//�ݹ���next[]���� 
void getnext_recursion(char* t, int next[], int L)
{
	next[0] = 0;
	//L - ����
	if (L == 1)
	{
		next[1] = 0;
		return;
	}
	getnext_recursion(t, next, L - 1);
	int k = next[L - 1];
	while (1)
	{
		if (t[k] == t[L - 1])
		{
			next[L] = k + 1;
			return;
		}
		k = next[k];
		if (k == 0)
		{
			next[L] = 1;
			return;
		}
	}
}

//��nextval����
void get_nextval(char* t, int next[], int nextval[], int L)
{
	nextval[1] = 0;
	for (int i = 2; i < L; i++)
	{
		if (t[i] == t[next[i]])
		{
			int j = i;
			do
			{
				nextval[i] = nextval[next[j]];
				j = next[j];
			} while (t[i] == t[next[j]]);
		}
		else
		{
			nextval[i] = next[i];
		}
	}
}