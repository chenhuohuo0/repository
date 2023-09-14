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

//��ʼ������������һ��ͷָ��
slist* init_slist();

//����ڵ�
slist* apply_for_node(datatype x);

//����
void destory_slist(slist** ph);

//����
void print_slist(slist* ph);

//���㵱ǰ����ĳ���(������ͷ�ڵ�)
int length_slist(slist* ph);

//���뵽��k��Ԫ�غ���
void insert_slist(slist* ph, int k, datatype x);

//ɾ����k��Ԫ��
void delete_slist(slist* ph, int k);

//����Ų��ң����ص�k��Ԫ�صĵ�ַ
slist* search_by_order(slist* ph, int k);

//��ֵ���ң������״γ��ֵ�ֵΪx��Ԫ�ص�ַ
slist* search_by_value(slist* ph, datatype x);

//�޸ĵ�k��Ԫ�ص�ֵ��ֵΪx
void modify_slist(slist* ph, int k, datatype x);
