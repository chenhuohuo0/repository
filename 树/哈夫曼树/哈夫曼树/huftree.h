#pragma once

#define MAXSIZE 30
#include<stdlib.h>
#include<stdio.h>

typedef struct htnode//哈夫曼树结点
{
	char ch;
	int weight;//权值
	int parent, lchild, rchild;
}htnode;

//typedef struct huftree//静态链表
//{
//	htnode arr[MAXSIZE];
//	int length;
//}huftree;

typedef struct nodecode
{
	char* code;//结点对应的编码
	char leaf;//结点值
	int length;//编码长度
}nodecode;

//哈夫曼算法
void hufcoding(htnode huftree[], nodecode cd[], int w, int n);

//找没父母的结点的最小和次小
void select2max(htnode huftree[],int len, int* s1, int* s2);
