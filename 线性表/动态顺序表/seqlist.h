#define _CRT_SECURE_NO_WARNINGS

//seqlist.h
#include<stdio.h>
#include<stdlib.h>

#define seqdatatype int 

typedef struct seqlist
{
	seqdatatype* data;
	int size;
	int capacity;
}seqlist;

//初始化
void init_seq(seqlist* p);
//销毁
void des_seq(seqlist* p);
//增
void insert_seq(seqlist* p, int k, seqdatatype x);
//删
void delelt_seq(seqlist* p, int k);
//改
void modify_seq(seqlist* p, int k, seqdatatype x);
//(按值)查-没找到返回-1，找到返回下标
int search_seq(seqlist* p, seqdatatype x);
//遍历
void print_seq(seqlist* p);
//排序
int cmp_int(void* e1, void* e2);

void order_seq(seqlist* p, int (*cmp)(void* e1, void* e2));