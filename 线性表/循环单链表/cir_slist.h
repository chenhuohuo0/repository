#define _CRT_SECURE_NO_WARNINGS

//cir_slist.h
#include<stdio.h>
#include<stdlib.h>

#define datatype int

typedef struct cir_slinklist
{
	datatype data;
	struct cir_slinklist* next;
}list;

//创建一个头节点，返回一个尾指针
list* init_list();

//申请结点
list* request_node(datatype x);

//销毁表
void destory_list(list* R);

//求当前的表长（不包含头结点）
int length_list(list* R);

//定位第k个元素的位置
list* locate_by_order(list* R, int k);

//在第k个元素后面插入x
void insert_back(list** R, int k, datatype x);

//删除第k个元素
void delete_by_order(list** R, int k);

//遍历
void print_list(list* R);

