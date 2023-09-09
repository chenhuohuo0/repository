#define _CRT_SECURE_NO_WARNINGS

//cir_slist.c
#include "cir_slist.h"
//����һ��ͷ�ڵ㣬����һ��βָ��
list* init_list()
{
	list* R = (list*)malloc(sizeof(list));
	if (!R)
	{
		perror("initialization failed");
		exit(-1);
	}
	else
	{
		R->data = 0;
		R->next = R;
		return R;
	}
}

//������
list* request_node(datatype x)
{
	list* R = (list*)malloc(sizeof(list));
	if (!R)
	{
		perror("initialization failed");
		exit(-1);
	}
	R->data = x;
	R->next = NULL;
	return R;
}

//���ٱ�
void destory_list(list* R)
{
	list* p = R->next;
	list* q =NULL;
	while (p != R)
	{
		q = p->next;
		free(p);
		p=q;
	}
	free(R);
	R = NULL;
}

//��ǰ�ı���������ͷ��㣩
int length_list(list* R)
{
	list* p = R->next;
	int count = 0;
	while (p != R)
	{
		count++;
		p = p->next;
	}
	return count;
}

//��λ��k��Ԫ�ص�λ��
list* locate_by_order(list* R, int k)
{
	if (k<0 || k>length_list(R))
	{
		printf("�±겻�Ϸ�\n");
		exit(-1);
	}
	list* p = R->next;
	int i = 0;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//�ڵ�k��Ԫ�غ������x
void insert_back(list** R, int k, datatype x)
{
	int len = length_list(*R);
	if (k<0 || k>len)
	{
		printf("�±겻�Ϸ�\n");
		return;
	}
	list* newnode = request_node(x);
	//�ҵ���k��Ԫ�ص�λ��
	list* p = locate_by_order(*R, k);
	newnode->next = p->next;
	p->next = newnode;
	//��������β��Ҫ����βָ���λ��
	if (len == k)
	{
		*R = newnode;
	}
}

//ɾ����k��Ԫ��
void delete_by_order(list** R, int k)
{
	int len = length_list(*R);
	if (0 == len)
	{
		printf("�ձ���ɾ��\n");
		return;
	}
	if (k <= 0 || k > len)
	{
		printf("�±겻�Ϸ�\n");
		return;
	}
	list* p = locate_by_order(*R, k - 1);
	list* q;
	q = p->next;
	p->next = q->next;
	free(q);
	//���ɾ�����һ��Ԫ����Ҫ����βָ���λ��
	if (len == k)
	{
		(*R) = p;
	}
}

//����
void print_list(list* R)
{
	printf("H ");
	list* p = R->next;
	while (p != R)
	{
		list* q = p->next;
		printf("-> %d ", q->data);
		p = q;
	}
	printf("-> H\n");
}