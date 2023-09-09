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

//��ʼ��
void init_seq(seqlist* p);
//����
void des_seq(seqlist* p);
//��
void insert_seq(seqlist* p, int k, seqdatatype x);
//ɾ
void delelt_seq(seqlist* p, int k);
//��
void modify_seq(seqlist* p, int k, seqdatatype x);
//(��ֵ)��-û�ҵ�����-1���ҵ������±�
int search_seq(seqlist* p, seqdatatype x);
//����
void print_seq(seqlist* p);
//����
int cmp_int(void* e1, void* e2);

void order_seq(seqlist* p, int (*cmp)(void* e1, void* e2));