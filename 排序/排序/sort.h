#pragma once

#define MAXSIZE 20

#include<stdio.h>

typedef struct seqlist
{
	int arr[MAXSIZE];
	int length;
}list;

//������
void print_list(list* L);

//ֱ�Ӳ�������
void straight_insert_sort(list* L);

//�۰��������
void binary_insert_sort(list* L);

//ϣ������ - ϣ�����鲽��ÿ��ȡһ��
void shell_insert(list* L, int gap);
void shell_sort(list* L, int gaps[],int n);

//ð������
void bubble_sort(list* L);

//��������
int quick_sort1(list* L, int left, int right);
void quick_sort(list* L, int left, int right);

//��ѡ������
void select_sort(list* L);

//������
void maxheap_adjust(list* L, int i, int n);
void heap_sort(list* L);

//�鲢����
void merge(list* L, int left, int right);
void merge_sort(list* L,int left,int right);

//��ؼ�������

//��ʽ��������
