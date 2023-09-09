#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define datatype int

typedef struct cir_dlist
{
	datatype data;
	struct cir_dlist* prior;
	struct cir_dlist* next;
}dlist;

//创建头结点，返回头指针
dlist* init_dlist();

//申请结点
dlist* request_node(datatype x);

//计算当前表长（不包含头结点）
int length_dlist(dlist* H);

//插入结点在第k个元素后面
void insert_back(dlist* H, int k, datatype x);

//删除第k个节点
void delete_node(dlist* H, int k);

//定位第k个结点的位置
dlist* locate_by_order(dlist* H, int k);

//按值查找，返回首次出现的元素位置
dlist* locate_by_value(dlist* H, datatype x);

//销毁表
void destory_dlist(dlist* H);

//遍历表
void print_dlist(dlist* H);