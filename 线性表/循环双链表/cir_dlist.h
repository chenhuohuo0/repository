#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define datatype int

typedef struct cir_dlist
{
	datatype data;
	struct cir_dlist* prior;
	struct cir_dlist* next;
}dlist;

//����ͷ��㣬����ͷָ��
dlist* init_dlist();

//������
dlist* request_node(datatype x);

//���㵱ǰ����������ͷ��㣩
int length_dlist(dlist* H);

//�������ڵ�k��Ԫ�غ���
void insert_back(dlist* H, int k, datatype x);

//ɾ����k���ڵ�
void delete_node(dlist* H, int k);

//��λ��k������λ��
dlist* locate_by_order(dlist* H, int k);

//��ֵ���ң������״γ��ֵ�Ԫ��λ��
dlist* locate_by_value(dlist* H, datatype x);

//���ٱ�
void destory_dlist(dlist* H);

//������
void print_dlist(dlist* H);