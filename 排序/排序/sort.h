#pragma once

#define MAXSIZE 20

#include<stdio.h>

typedef struct seqlist
{
	int arr[MAXSIZE];
	int length;
}list;

//遍历表
void print_list(list* L);

//直接插入排序
void straight_insert_sort(list* L);

//折半插入排序
void binary_insert_sort(list* L);

//希尔排序 - 希尔建议步长每次取一半
void shell_insert(list* L, int gap);
void shell_sort(list* L, int gaps[],int n);

//冒泡排序
void bubble_sort(list* L);

//快速排序
int quick_sort1(list* L, int left, int right);
void quick_sort(list* L, int left, int right);

//简单选择排序
void select_sort(list* L);

//堆排序
void maxheap_adjust(list* L, int i, int n);
void heap_sort(list* L);

//归并排序
void merge(list* L, int left, int right);
void merge_sort(list* L,int left,int right);

//多关键码排序

//链式基数排序
