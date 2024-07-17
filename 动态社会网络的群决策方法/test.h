#pragma once
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define ROW 5
#define COL 5
#define NUMBER 9

//模型参数
#define C1 0.95//共识水平
#define C2 0.5//属性权重主客观侧重



#define C5 0.5//
#define C6 0.7//超过信任阈值建立信任关系
#define P1 0.5
#define P2 0.5
#define P3 0
#define P4 0


//需要一个栈
typedef struct stack
{
	int data;
	struct stack* next;
}stack;
//初始化
stack* init_stack();
//压栈
int push_stack(stack** top, int x);
//出栈
int pop_stack(stack** top);
//按值查找
int search_stack(stack* top,int x);
//销毁
void destory_stack(stack** top);






//打印测试
void print(double arr[], int n);
void print_int(int (*p)[COL], int x, int y);
void print_double(double(*p)[NUMBER], int x, int y);


//归一化
void normalization(double* arr, int n);


//距离度量
double distance_measure(int (*p1)[COL], int(*p2)[COL]);
void distance_matrix(int(*p[NUMBER])[COL], double arr[NUMBER][NUMBER]);//输出成矩阵

//相似性
double similarity_measure(int(*p1)[COL], int(*p2)[COL]);
void similarity_matrix(int(*p[NUMBER])[COL], double arr[NUMBER][NUMBER]);//输出成矩阵

//共识水平
double consensus_level(int(*p[NUMBER])[COL]);

//信任反馈调整
void trust_feedback(int(*p[NUMBER])[COL],double t[NUMBER][NUMBER],double arr1[NUMBER], double arr2[NUMBER]);

//信任搭建
double trust_propagation(double arr[NUMBER][NUMBER], int x, int y,stack* S);
void update_trust_matrix(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER]);
void trust_building(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER], double arr3[NUMBER][NUMBER], double arr4[NUMBER][NUMBER]);


//共识达成模型
void reach_consensus(int(*p[NUMBER])[COL], double T0[NUMBER][NUMBER],double confidence[NUMBER],double selfness[NUMBER]);

//集体评估矩阵
void collective_evaluation(int(*p[NUMBER])[COL], double In[NUMBER], double CV[ROW][COL]);

//属性客观权重
void objective_height(double arr1[ROW][COL],double arr2[COL]);

//最终决策
void decision(double CV[ROW][COL], double W[ROW]);



