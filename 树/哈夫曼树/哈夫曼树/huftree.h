#pragma once

#define MAXSIZE 30
#include<stdlib.h>
#include<stdio.h>

typedef struct htnode//�����������
{
	char ch;
	int weight;//Ȩֵ
	int parent, lchild, rchild;
}htnode;

//typedef struct huftree//��̬����
//{
//	htnode arr[MAXSIZE];
//	int length;
//}huftree;

typedef struct nodecode
{
	char* code;//����Ӧ�ı���
	char leaf;//���ֵ
	int length;//���볤��
}nodecode;

//�������㷨
void hufcoding(htnode huftree[], nodecode cd[], int w, int n);

//��û��ĸ�Ľ�����С�ʹ�С
void select2max(htnode huftree[],int len, int* s1, int* s2);
