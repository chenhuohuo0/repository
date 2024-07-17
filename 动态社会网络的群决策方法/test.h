#pragma once
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define ROW 5
#define COL 5
#define NUMBER 9

//ģ�Ͳ���
#define C1 0.95//��ʶˮƽ
#define C2 0.5//����Ȩ�����͹۲���



#define C5 0.5//
#define C6 0.7//����������ֵ�������ι�ϵ
#define P1 0.5
#define P2 0.5
#define P3 0
#define P4 0


//��Ҫһ��ջ
typedef struct stack
{
	int data;
	struct stack* next;
}stack;
//��ʼ��
stack* init_stack();
//ѹջ
int push_stack(stack** top, int x);
//��ջ
int pop_stack(stack** top);
//��ֵ����
int search_stack(stack* top,int x);
//����
void destory_stack(stack** top);






//��ӡ����
void print(double arr[], int n);
void print_int(int (*p)[COL], int x, int y);
void print_double(double(*p)[NUMBER], int x, int y);


//��һ��
void normalization(double* arr, int n);


//�������
double distance_measure(int (*p1)[COL], int(*p2)[COL]);
void distance_matrix(int(*p[NUMBER])[COL], double arr[NUMBER][NUMBER]);//����ɾ���

//������
double similarity_measure(int(*p1)[COL], int(*p2)[COL]);
void similarity_matrix(int(*p[NUMBER])[COL], double arr[NUMBER][NUMBER]);//����ɾ���

//��ʶˮƽ
double consensus_level(int(*p[NUMBER])[COL]);

//���η�������
void trust_feedback(int(*p[NUMBER])[COL],double t[NUMBER][NUMBER],double arr1[NUMBER], double arr2[NUMBER]);

//���δ
double trust_propagation(double arr[NUMBER][NUMBER], int x, int y,stack* S);
void update_trust_matrix(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER]);
void trust_building(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER], double arr3[NUMBER][NUMBER], double arr4[NUMBER][NUMBER]);


//��ʶ���ģ��
void reach_consensus(int(*p[NUMBER])[COL], double T0[NUMBER][NUMBER],double confidence[NUMBER],double selfness[NUMBER]);

//������������
void collective_evaluation(int(*p[NUMBER])[COL], double In[NUMBER], double CV[ROW][COL]);

//���Կ͹�Ȩ��
void objective_height(double arr1[ROW][COL],double arr2[COL]);

//���վ���
void decision(double CV[ROW][COL], double W[ROW]);



