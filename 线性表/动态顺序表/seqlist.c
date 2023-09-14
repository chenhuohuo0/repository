#define _CRT_SECURE_NO_WARNINGS

//seqlist.c
#include "seqlist.h"

//��ʼ��
void init_seq(seqlist* pq)
{
	seqdatatype* p=(seqdatatype*)malloc(3*sizeof(seqdatatype));
	if(p==NULL)
	{
		perror("initializing seqlist failed");
		return;
	}
	pq->data = p;
	pq->size = 0;
	pq->capacity = 3;
}

//����
void des_seq(seqlist* p)
{
	free(p->data);
	p = NULL;
}

void check_capacity(seqlist* p)
{
	if (p->capacity == p->size)
	{
		seqdatatype* pdata = (seqdatatype*)realloc(p->data, (p->capacity+2)*sizeof(seqdatatype));
		if (pdata == NULL)
		{
			perror("checking capacity failed");
			return;
		}
		p->data = pdata;
		p->capacity+=2;
	}
}

//��
void insert_seq(seqlist* p, int k, seqdatatype x)
{
	check_capacity(p);
	if (k<0 || k>p->size)
	{
		printf("���λ�ò��Ϸ�\n");
		return;
	}
	int n = p->size - 1;
	while (n >= k)
	{
		p->data[n + 1] = p->data[n];
		n--;
	}
	p->data[k] = x;
	p->size++;
}

//ɾ
void delelt_seq(seqlist* p, int k)
{
	if (k<0 || k>p->size)
	{
		printf("���λ��û��Ԫ��\n");
		return;
	}
	while (k <= p->size - 2)
	{
		p->data[k] = p->data[k + 1];
		k++;
	}
	p->size--;
}

//��
void modify_seq(seqlist* p, int k, seqdatatype x)
{
	if (k<0 || k>p->size)
	{
		printf("���λ��û��Ԫ��\n");
		return;
	}
	p->data[k] = x;
}

//(��ֵ)��
int search_seq(seqlist* p, seqdatatype x)
{
	for (int i = 0; i < p->size; i++)
	{
		if (x == p->data[i])
		{
			return i;
		}
	}
	return -1;
}

//����
void print_seq(seqlist* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->data[i]);
	}
	printf("\n");
}

//���� - ������ʾ�������������������Ϳɲο�qsort���
int cmp_int(void* e1, void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void order_seq(seqlist* p, int (*cmp)(void* e1, void* e2))
{
	int i, j;
	for (i = 0; i < p->size - 1; i++)
	{
		int flag = 0;//������һ���Ѿ�����
		for (j = 0; j < p->size - i - 1; j++)
		{
			if (cmp(&(p->data[j]), &(p->data[j + 1])) > 0)
			{
				seqdatatype t = p->data[j];
				p->data[j] = p->data[j + 1];
				p->data[j + 1] = t;
				flag = 1;
			}
		}
		if (flag == 0)//˵����ǰ�Ѿ�����
		{
			return;
		}
	}
}