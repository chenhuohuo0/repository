#pragma once
#include<stdio.h>
//#include<stddef.h>

//1.类似顺序表，串描述如下：
#define MAXSIZE 20
typedef struct
{
	char data[MAXSIZE];
	int length;
}string;


//2.用\0作为结束标志


//3.设定长串存储char s[MAXSIZE+1],s[0]存放串实际长度





//BF算法
char* str_BF(char* s, char* t);

//求next数组
void getnext(char *t, int next[]);

//KMP算法
char* str_KMP(char* s, char* t);

//递归求next[]数组 
void getnext_recursion(char* t, int next[], int L);

//求nextval数组
void get_nextval(char* t, int next[], int nextval[], int L);
