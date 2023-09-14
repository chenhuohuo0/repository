#define _CRT_SECURE_NO_WARNINGS
//slist.c
#include "slist.h"

//��ʼ��
slist* init_slist()
{
	//�����ڴ��ž�̬����
	slist* H = (slist*)malloc(sizeof(slist));
	if (!H)
	{
		perror("init_slist error");
		exit(-1);
	}
	//������ȫ����0���α�-1����ĩβԪ�أ��α�-2����δʹ��
	H->len = 0;
	H->arr[0].data = 0;
	H->arr[0].next = -1;
	for (int i = 1; i < MAXSIZE; i++)
	{
		H->arr[i].data = 0;
		H->arr[i].next = -2;
	}
	return H;
} 

//����
void destory_slist(slist* H)
{
	free(H);
	H = NULL;
	return ;
}

//��λ��k��Ԫ�ص�λ��
node* locate_by_order(slist* H, int k)
{
	if (k<0 || k>H->len)
	{
		printf("�±겻�Ϸ�\n");
		return NULL;
	}
	node* p = &(H->arr[0]);
	for(int i=0;i<k;i++)
	{
		
		p = &(H->arr[p->next]);
	}
	return p;
}

//����
void insert_back(slist* H, int k, datatype x)
{
	if (k<0 || k> H->len )
	{
		printf("�±�Ƿ�\n");
		return;
	}
	//��һ����λ,���������λ�±��¼Ϊpos
	int pos = 1;
	while (pos<MAXSIZE)
	{
		if (H->arr[pos].next == -2)
		{
			break;
		}
		pos++;
	}
	if (pos == MAXSIZE)
	{
		printf("������\n");
		return;
	}
	if (k == 0)
	{
		H->arr[pos].data = x;
		H->arr[pos].next = H->arr[0].next;
		H->arr[0].next = pos;
		H->len++;
		return;
	}
	//�ҵ���k������λ��
	node* p = locate_by_order(H, k);
	H->arr[pos].next = p->next;
	H->arr[pos].data = x;
	p->next = pos;
	H->len++;
}

//ɾ��
void delete_node(slist* H, int k)
{
	if (k <= 0 || k > H->len)
	{
		printf("�±�Ƿ�\n");
		return;
	}
	node* p = locate_by_order(H, k-1);
	int q = p->next;
	p->next = H->arr[q].next;
	H->arr[q].data = 0;
	H->arr[q].next = -2;
	H->len--;

}

//����
void print_slist(slist* H)
{
	node* p = &(H->arr[H->arr[0].next]);
	while (H->len--)
	{
		printf("%d ->", p->data);
		p = &(H->arr[p->next]);
	}
	printf("NULL\n");
}