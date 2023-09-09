#define _CRT_SECURE_NO_WARNINGS

//slist.c
#include "slist.h"

//�½�һ��ͷ�ڵ㣬ͷ�ڵ��dataΪ0������ָ��ͷ�ڵ��ͷָ��
slist* init_slist()
{
	slist* ph = (slist*)malloc(sizeof(slist));
	if (ph == NULL)
	{
		perror("initializing single linklist failed");
		exit(1);
	}
	ph->data = 0;
	ph->next = NULL;
	return ph;
}

//����ڵ�
slist* apply_for_node(datatype x)
{
	slist* p = (slist*)malloc(sizeof(slist));
	if (p == NULL)
	{
		perror("applying for node failed");
		exit(1);
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}

//����
void destory_slist(slist** ph)
{
	while (*ph)
	{
		slist* q = *ph;
		*ph = (*ph)->next;
		free(q);
	}
	*ph = NULL;
}

//����
void print_slist(slist* ph)
{
	slist* p = ph;
	while (p)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

//���㵱ǰ����ĳ���(������ͷ�ڵ�)
int length_slist(slist* ph)
{
	slist*p = ph;
	int count = -1;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}



//���뵽��k��Ԫ�غ���
void insert_slist(slist* ph, int k,datatype x)
{
	if (k<0 || k>length_slist(ph))
	{
		printf("��ǰλ�ò��ܲ���\n");
		return;
	}
	slist* newnode = apply_for_node(x);

	int i = 0;
	slist* p = ph;//��pָ���k��Ԫ��
	while (i < k)
	{
		p = p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
}

//ɾ����k��Ԫ��
void delete_slist(slist* ph, int k)
{
	if (ph->next == NULL)
	{
		printf("����ʧ�ܣ�����һ���ձ�\n");
		return;
	}
	if (k<=0 || k>length_slist(ph))
	{
		printf("�±겻�Ϸ�\n");
		return;
	}
	int i = 0;
	slist* p = ph;//��pָ���k-1��Ԫ��
	while (i < k-1)
	{
		p = p->next;
		i++;
	}
	slist* q = p->next;
	p->next = q->next;
	free(q);
}

//����Ų��ң����ص�k��Ԫ�صĵ�ַ
slist* search_by_order(slist* ph, int k)
{
	int i = 0;
	slist* p = ph;//��pָ���k��Ԫ��
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//��ֵ���ң������״γ��ֵ�ֵΪx��Ԫ�ص�ַ
slist* search_by_value(slist* ph, datatype x)
{
	slist* p = ph->next;
	while (p)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;//NULL��ʾ�Ҳ���
}

//�޸ĵ�k��Ԫ�ص�ֵ��ֵΪx
void modify_slist(slist* ph, int k, datatype x)
{
	int i = 0;
	slist* p = ph;//��pָ���k��Ԫ��
	while (i < k)
	{
		p = p->next;
		i++;
	}
	p->data = x;
}
