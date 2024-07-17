#define _CRT_SECURE_NO_WARNINGS

#include "test.h"

//需要一个栈
//初始化
stack* init_stack()
{
	stack* top = (stack*)malloc(sizeof(stack*));
	top = NULL;
	return top;
	
}
//压栈
int push_stack(stack** top, int x)
{
	stack* p = (stack*)malloc(sizeof(stack));
	if (!p)
	{
		perror("内存溢出\n");
		return 0;
	}
	else
	{
		p->data = x;
		p->next = *top;
		*top = p;
		return 1;
	}
}
//出栈
int pop_stack(stack** top)
{
	if ((*top) == NULL)
	{
		printf("空栈\n");
		return 0;
	}
	stack* p = *top;
	*top = p->next;
	free(p);
	return 1;
}
//遍历查找
int search_stack(stack* top,int x)
{
	stack* p = top;
	while (p)
	{
		if(x!=p->data)
			p = p->next;
		else return 1;//找到了
	}
	return 0;
}
//销毁
void destory_stack(stack** top)
{
	stack* p = *top;
	stack* q = p;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*top = NULL;
}

//归一化
void normalization(double arr[], int n)
{
	int i = 0; double sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = arr[i] / sum;
		//printf("%lf ", arr[i]);
	}
	
}

void print(double arr[], int n)
{
	printf("\n");
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%lf ", arr[i]);
	}
	printf("\n"); return;
}
void print_int(int (*p)[COL], int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0;j < y; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

}

void print_double(double(*p)[NUMBER], int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%lf ", p[i][j]);
		}
		printf("\n");
	}

}

//距离度量
double distance_measure(int(*p1)[COL], int(*p2)[COL])
{
	int i = 0, j = 0 ;
	double sum = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			sum += fabs(double(p1[i][j]) / 100 - double(p2[i][j]) / 100);
		}
	}
	sum /= (ROW * COL);
	return sum;
}
void distance_matrix(int(*p[NUMBER])[COL], double arr[NUMBER][NUMBER])//输出成矩阵
{
	int i, j;
	//printf("\n距离:\n");
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			arr[i][j] = distance_measure(p[i], p[j]);
			//printf("%lf ", arr[i][j]);
		}
		//printf("\n");
	}
}
//相似性
double similarity_measure(int(*p1)[COL], int(*p2)[COL])
{
	return 1 - distance_measure(p1, p2);
}
void similarity_matrix(int(*p[NUMBER])[COL],double arr[NUMBER][NUMBER])//输出成矩阵
{
	int i, j;
	//printf("\n相似性:\n");
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			arr[i][j] = similarity_measure(p[i], p[j]);
			//printf("%lf ", arr[i][j]);
		}
		//printf("\n");
	}
}

//共识水平
double consensus_level(int(*p[NUMBER])[COL])
{
	int i, j;
	double sum=0;
	for (i = 0; i < NUMBER; i++)
	{
		for (j = i+1; j < NUMBER; j++)
		{
			sum+=distance_measure(p[i], p[j]);
		}
	}
	sum = 1 - sum*2 / (NUMBER*(NUMBER-1));
	return sum;
}

//信息反馈调整
void trust_feedback(int(*p[NUMBER])[COL], double t[NUMBER][NUMBER],double arr1[NUMBER], double arr2[NUMBER])
{
	int i, j;
	double sum = 0;
	//按行归一化信任矩阵
	double trust[NUMBER][NUMBER] = { 0 };
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)//计算行和
		{
			sum += t[i][j];
		}
		for (j = 0; j < NUMBER; j++)
		{
			trust[i][j] = t[i][j] / sum;
		}
		sum = 0;
	}
	double x,y=0; int h; int k;
	//print_double(trust, 9, 9);
	for (h = 0; h < NUMBER; h++)
	{
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				for (k = 0; k < NUMBER; k++)
				{
					y = trust[h][k] * ((p[k])[i][j]) + y;
					
				}
				x = (p[h])[i][j] * arr1[h] + (1 - arr1[h])*y;

				(p[h])[i][j] = int((p[h])[i][j] * arr2[h] + (1 - arr2[h])*x);
				y = 0;
			}
		}

	}
	
	for (i = 0; i < NUMBER; i++)
	{
		printf("评估矩阵V%d:\n", i + 1);
		print_int(p[i], ROW, COL);
		printf("\n");
	}
}

//信任搭建
double trust_propagation(double arr[NUMBER][NUMBER], int x, int y,stack* S)
{
	int i; double total = 0; int count = 0;
	if (x == y)
	{
		return 0;
	}
	if (search_stack(S, x * 10 + y))//如果栈中有这一项，说明绕回来了
	{
		return 0;
	}
	push_stack(&S, x * 10 + y);
	if (arr[x][y])
	{
		pop_stack(&S);
		return arr[x][y];
	}
	
	for (i = 0; i < NUMBER; i++)
	{
		if (i == x) continue;
		if (arr[x][i] == 0) continue;
		double t1 = arr[x][i];
		
		double t2 = trust_propagation(arr, i, y,S);//如果t2有值就找到了一条路径
		if (t2) count++;
		double sum = t1*t2;
		total= total+(2*sum)/(sum+(2-t1)*(2-t2));
	}
	if (count)
	{
		pop_stack(&S);
		return total / count;
	}
	else
		pop_stack(&S);
		return 0;
}

void update_trust_matrix(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER])
{
	int i, j;
	double value;
	
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			stack* S = init_stack();
			value = trust_propagation(arr1, i, j, S);
			arr2[i][j] = value;
			destory_stack(&S);
		}
	}
	
	/*printf("\n预建立的信任值:\n");
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			printf("%lf ", arr2[i][j]);
		}
		printf("\n");
	}*/
	return;
}
void trust_building(double arr1[NUMBER][NUMBER], double arr2[NUMBER][NUMBER], double arr3[NUMBER][NUMBER], double arr4[NUMBER][NUMBER])
//初始信任值，更新后信任值，相似性矩阵，信任指标矩阵
{
	int i, j;
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			if (arr1[i][j] == arr2[i][j])//更新前的信任值不能改变，对应的信任指标为1
			{
				if(i==j) 
					arr4[i][j] = 0;
				else 
					arr4[i][j] = 1;
			}
			else
			{
				arr4[i][j] = C5 * arr2[i][j] + (1 - C5)*arr3[i][j];
			}
		}
	}

	/*printf("\n信任指标矩阵:\n");
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			printf("%lf ", arr4[i][j]);
		}
		printf("\n");
	}*/
	return;
}

//共识达成模型
void reach_consensus(int(*p[NUMBER])[COL], double T0[NUMBER][NUMBER], double confidence[NUMBER], double selfness[NUMBER])
{
	int n = 0; int i, j; 
	double T1[NUMBER][NUMBER] = { 0 };//更新信任矩阵
	double T2[NUMBER][NUMBER] = { 0 };//相似度矩阵
	double T3[NUMBER][NUMBER] = { 0 };//信任指标矩阵

	double cons = consensus_level(p);//共识水平
	printf("初始评估矩阵:\n");
	for (i = 0; i < NUMBER; i++)
	{
		printf("评估矩阵V%d:\n", i + 1);
		print_int(p[i], ROW, COL);
		printf("\n");
	}
	if (cons >= C1)
	{
		printf("共识水平为:%lf>=%ld\n",cons,C1);
		printf("共识达成\n");
		printf("\n------------------------------------------------------------------------------------\n");
	}
	else
	{
		printf("共识水平为:%lf<=%lf\n", cons,C1);
		printf("\n------------------------------------------------------------------------------------\n");
		printf("初始信任矩阵:\n");
		for (i = 0; i < NUMBER; i++)
		{
			for (j = 0; j < NUMBER; j++)
			{
				printf("%lf ", T0[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		while (1)
		{
			
			n++;
			printf("第%d次反馈调整:\n", n);
			trust_feedback(p, T0, confidence, selfness);
			printf("\n");
			cons = consensus_level(p);
			if (cons >= C1)
			{
				printf("共识水平为:%lf>=%lf\n",cons,C1);
				printf("共识达成\n");
				printf("\n------------------------------------------------------------------------------------\n");
				break;
			}
			else
			{
				
				printf("共识水平为:%lf<=%lf\n", cons,C1);
				printf("\n------------------------------------------------------------------------------------\n");

				update_trust_matrix(T0, T1);
				
				similarity_matrix(p, T2);
				
				trust_building(T0, T1, T2, T3);//原信任矩阵，更新信任矩阵，相似度矩阵，信任指标矩阵

				for (i = 0; i < NUMBER; i++)
				{
					for (j = 0; j < NUMBER; j++)
					{
						if (T3[i][j] < C6)
						{
							T1[i][j] = 0;
						}
					}
				}
				for (i = 0; i < NUMBER; i++)
				{
					for (j = 0; j < NUMBER; j++)
					{
						T0[i][j] = T1[i][j];
					}
				}
				printf("第%d次动态调整后的社会网络:\n", n);
				for (i = 0; i < NUMBER; i++)
				{
					for (j = 0; j < NUMBER; j++)
					{
						printf("%lf ", T0[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				
			}
		}
	}
	//出循环则共识达标
	
	return;
}

//集体评估矩阵
void collective_evaluation(int(*p[NUMBER])[COL], double In[NUMBER], double CV[ROW][COL])
{
	int i, j, k;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			for (k = 0; k < NUMBER; k++)
			{
				CV[i][j] += In[k]*(p[k])[i][j];
			}
		}
	}
	
	printf("\n集体评估矩阵:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%lf ", CV[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//属性客观权重
void objective_height(double arr1[ROW][COL], double arr2[COL])
{
	double arr[ROW][COL] = { 0 };
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			arr[i][j] = arr1[i][j];
		}
	}
	//按列归一化
	double t[ROW] = { 0 };
	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			t[j] = arr[j][i];
		}
		normalization(t, 5);
		for (j = 0; j < ROW; j++)
		{
			arr[j][i] = t[j];
		}
	}
	/*printf("\n归一化之后:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	double sum = 0;
	//计算信息熵
	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			sum += arr[j][i] * log(arr[j][i]);
		}
		arr2[i] = 1-(sum / log(ROW));
	}
	normalization(arr2, COL);
	/*for (i = 0; i < 5; i++)
	{
		arr2[i] = 1 - arr2[i];
	}*/
	printf("\n客观属性权重:\n");
	for (i = 0; i < COL; i++)
	{
		printf("%lf ", arr2[i]);
	}
	printf("\n");
}

//最终决策
void decision(double CV[ROW][COL], double W[ROW])
{
	double arr[ROW] = { 0 };
	int i,j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			arr[i] += CV[i][j] * W[j];
		}
		arr[i] /= 100;
	}
	printf("\n群决策各方案偏好结果:\n");
	print(arr, ROW);
	printf("\n归一化后结果:\n");
	normalization(arr, ROW);
	print(arr, ROW);
	return;
}