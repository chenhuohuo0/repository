#pragma once
#include<stdio.h>
//#include<stddef.h>

//1.����˳������������£�
#define MAXSIZE 20
typedef struct
{
	char data[MAXSIZE];
	int length;
}string;


//2.��\0��Ϊ������־


//3.�趨�����洢char s[MAXSIZE+1],s[0]��Ŵ�ʵ�ʳ���





//BF�㷨
char* str_BF(char* s, char* t);

//��next����
void getnext(char *t, int next[]);

//KMP�㷨
char* str_KMP(char* s, char* t);

//�ݹ���next[]���� 
void getnext_recursion(char* t, int next[], int L);

//��nextval����
void get_nextval(char* t, int next[], int nextval[], int L);
