#define _CRT_SECURE_NO_WARNINGS

//slist.c
#include "slist.h"

//新建一个头节点，头节点的data为0，返回指向头节点的头指针
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

//申请节点
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

//销毁
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

//遍历
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

//计算当前链表的长度(不包含头节点)
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



//插入到第k个元素后面
void insert_slist(slist* ph, int k,datatype x)
{
	if (k<0 || k>length_slist(ph))
	{
		printf("当前位置不能插入\n");
		return;
	}
	slist* newnode = apply_for_node(x);

	int i = 0;
	slist* p = ph;//让p指向第k个元素
	while (i < k)
	{
		p = p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
}

//删除第k个元素
void delete_slist(slist* ph, int k)
{
	if (ph->next == NULL)
	{
		printf("操作失败：这是一个空表\n");
		return;
	}
	if (k<=0 || k>length_slist(ph))
	{
		printf("下标不合法\n");
		return;
	}
	int i = 0;
	slist* p = ph;//让p指向第k-1个元素
	while (i < k-1)
	{
		p = p->next;
		i++;
	}
	slist* q = p->next;
	p->next = q->next;
	free(q);
}

//按序号查找，返回第k个元素的地址
slist* search_by_order(slist* ph, int k)
{
	int i = 0;
	slist* p = ph;//让p指向第k个元素
	while (i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}

//按值查找，返回首次出现的值为x的元素地址
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
	return NULL;//NULL表示找不到
}

//修改第k个元素的值的值为x
void modify_slist(slist* ph, int k, datatype x)
{
	int i = 0;
	slist* p = ph;//让p指向第k个元素
	while (i < k)
	{
		p = p->next;
		i++;
	}
	p->data = x;
}
