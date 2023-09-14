#define _CRT_SECURE_NO_WARNINGS

//slist.h
#include<stdio.h>
#include<stdlib.h>

#define datatype int

typedef struct slinklist
{
	datatype data;
	struct slinklist* next;
}slist;

//初始化单链表，返回一个头指针
slist* init_slist();

//申请节点
slist* apply_for_node(datatype x);

//销毁
void destory_slist(slist** ph);

//遍历
void print_slist(slist* ph);

//计算当前链表的长度(不包含头节点)
int length_slist(slist* ph);

//插入到第k个元素后面
void insert_slist(slist* ph, int k, datatype x);

//删除第k个元素
void delete_slist(slist* ph, int k);

//按序号查找，返回第k个元素的地址
slist* search_by_order(slist* ph, int k);

//按值查找，返回首次出现的值为x的元素地址
slist* search_by_value(slist* ph, datatype x);

//修改第k个元素的值的值为x
void modify_slist(slist* ph, int k, datatype x);
