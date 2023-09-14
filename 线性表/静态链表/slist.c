#define _CRT_SECURE_NO_WARNINGS
//slist.c
#include "slist.h"

//初始化
slist* init_slist()
{
	//申请内存存放静态链表
	slist* H = (slist*)malloc(sizeof(slist));
	if (!H)
	{
		perror("init_slist error");
		exit(-1);
	}
	//数据域全部置0，游标-1代表末尾元素，游标-2代表未使用
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

//销毁
void destory_slist(slist* H)
{
	free(H);
	H = NULL;
	return ;
}

//定位第k个元素的位置
node* locate_by_order(slist* H, int k)
{
	if (k<0 || k>H->len)
	{
		printf("下标不合法\n");
		return NULL;
	}
	node* p = &(H->arr[0]);
	for(int i=0;i<k;i++)
	{
		
		p = &(H->arr[p->next]);
	}
	return p;
}

//插入
void insert_back(slist* H, int k, datatype x)
{
	if (k<0 || k> H->len )
	{
		printf("下标非法\n");
		return;
	}
	//找一个空位,并把这个空位下标记录为pos
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
		printf("表已满\n");
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
	//找到第k个结点的位置
	node* p = locate_by_order(H, k);
	H->arr[pos].next = p->next;
	H->arr[pos].data = x;
	p->next = pos;
	H->len++;
}

//删除
void delete_node(slist* H, int k)
{
	if (k <= 0 || k > H->len)
	{
		printf("下标非法\n");
		return;
	}
	node* p = locate_by_order(H, k-1);
	int q = p->next;
	p->next = H->arr[q].next;
	H->arr[q].data = 0;
	H->arr[q].next = -2;
	H->len--;

}

//遍历
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