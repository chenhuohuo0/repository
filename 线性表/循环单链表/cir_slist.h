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

//����һ��ͷ�ڵ㣬����һ��βָ��
list* init_list();

//������
list* request_node(datatype x);

//���ٱ�
void destory_list(list* R);

//��ǰ�ı���������ͷ��㣩
int length_list(list* R);

//��λ��k��Ԫ�ص�λ��
list* locate_by_order(list* R, int k);

//�ڵ�k��Ԫ�غ������x
void insert_back(list** R, int k, datatype x);

//ɾ����k��Ԫ��
void delete_by_order(list** R, int k);

//����
void print_list(list* R);

