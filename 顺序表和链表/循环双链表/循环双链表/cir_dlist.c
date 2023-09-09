#define _CRT_SECURE_NO_WARNINGS
#include "cir_dlist.h"

//����ͷ��㣬����ͷָ��
dlist* init_dlist()
{
	dlist* H = (dlist*)malloc(sizeof(dlist));
	if (H == NULL)
	{
		perror("init_dlist");
		exit(-1);
	}
	H->data = 0;
	H->next = H;
	H->prior = H;
}

//������
dlist* request_node(datatype x)
{
	dlist* p = (dlist*)malloc(sizeof(dlist));
	if (p == NULL)
	{
		perror("init_dlist error");
		exit(-1);
	}
	p->data = x;
	p->next = NULL;
	p->prior = NULL;
	return p;
}

//���㵱ǰ����������ͷ��㣩
int length_dlist(dlist* H)
{
	dlist* p = H->next;
	int count = 0;
	while (p!=H)
	{
		count++;
		p = p->next;
	}
	return count;
}


//�������ڵ�k��Ԫ�غ���
void insert_back(dlist* H, int k, datatype x)
{
	int len = length_dlist(H);
	if (k<0 || k>len)
	{
		printf("�±겻�Ϸ�\n");
		return;
	}
	dlist* newnode = request_node(x);
	dlist* p = locate_by_order(H, k);

	p->next->prior = newnode;
	newnode->next = p->next;
	p->next = newnode;
	newnode->prior = p;

}

//ɾ����k���ڵ�
void delete_node(dlist* H, int k)
{
	int len = length_dlist(H);
	if (k <= 0 || k > len)
	{
		printf("�±겻�Ϸ�\n");
		return;
	}
	dlist* p = locate_by_order(H, k - 1);
	dlist* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
}

//��λ��k������λ��
dlist* locate_by_order(dlist* H, int k)
{
	if (k<0 || k>length_dlist(H))
	{
		printf("�±겻�Ϸ�\n");
		exit(-1);
	}
	dlist* p = H;
	int i = 0;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//��ֵ���ң������״γ��ֵ�Ԫ��λ��
dlist* locate_by_value(dlist* H, datatype x)
{
	dlist* p = H->next;
	while (p != H)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

//���ٱ�
void destory_dlist(dlist* H)
{
	dlist* p = H;
	int i = 0;
	int len = length_dlist(p);
	while (i <= len)
	{
		dlist* q = p->next;
		free(p);
		p = q;
		i++;
	}
}

//������
void print_dlist(dlist* H)
{
	dlist* p = H->next;
	printf("H <->");
	while (p != H)
	{
		printf("%d <-> ", p->data);
		p = p->next;
	}
	printf("H\n");
}