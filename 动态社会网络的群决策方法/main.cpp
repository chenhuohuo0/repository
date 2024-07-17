#define _CRT_SECURE_NO_WARNINGS

#include "test.h"


int main()
{
	int i, j;
	double confidence[NUMBER] = { 0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5 };//自信心
	double selfness[NUMBER] = { 0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5 };//自私心


	int arr1[ROW][COL] = { {74, 72, 50, 80, 83},
						 {93, 36, 51, 17, 52},
						 {55, 26, 64, 80, 62},
						 {40, 52, 80, 62, 40},
						 {53, 56, 61, 62, 71} };
	int arr2[ROW][COL] = { {31, 22, 30, 50, 26},
						 {52,58,40,55,93},
						 {95,63,30,81,96},
						 {46,93,60,68,91},
						 {70,21,71,50,50} };
	int arr3[ROW][COL] = { {30,94,37,74,72},
						 {92,59,36,49,13},
						 {87,57,79,35,70},
						 {82,60,48,77,63},
						 {85,64,48,57,95} };
	int arr4[ROW][COL] = { {39,11,45,39,93},
						 {68,46,85,55,25},
						 {70,61,54,41,80},
						 {99,50,87,51,79},
						 {36,64,63,19,62} };
	int arr5[ROW][COL] = { {59,93,68,85,69},
						 {46,43,98,92,70},
						 {47,43,78,22,12},
						 {17,50,75,44,36},
						 {87,29,47,46,85} };
	int arr6[ROW][COL] = { {52,76,73,47,91},
						 {80,73,78,90,39},
						 {56,87,28,57,73},
						 {30,11,21,88,41},
						 {14,46,28,82,42} };
	int arr7[ROW][COL] = { {70,80,69,60,32},
						 {61,58,54,20,70},
						 {33,12,21,49,46},
						 {96,10,78,19,63},
						 {90,70,58,53,61} };
	int arr8[ROW][COL] = { {56,72,78,80,21},
						 {17,85,87,32,32},
						 {73,73,61,74,64},
						 {88,64,98,63,90},
						 {58,92,11,77,32} };
	int arr9[ROW][COL] = { {60,58,42,32,25},
						 {78,24,60,70,45},
						 {40,70,45,77,70},
						 {53,10,47,58,78},
						 {64,62,77,52,17} };

	int(*p1)[COL] = arr1;
	int(*p2)[COL] = arr2;
	int(*p3)[COL] = arr3;
	int(*p4)[COL] = arr4;
	int(*p5)[COL] = arr5;
	int(*p6)[COL] = arr6;
	int(*p7)[COL] = arr7;
	int(*p8)[COL] = arr8;
	int(*p9)[COL] = arr9;
	int(*p[NUMBER])[COL] = { p1,p2,p3,p4,p5,p6,p7,p8,p9 };
	

	double T[NUMBER][NUMBER] = { {0,0.7,0.8,0.6,0,0,0,0,0} ,
								 {0.6,0,0.8,0,0,0,0.6,0,0},
								 {0,0.6,0,0,0,0,0,0.6,0.5},
								 {0,0,0,0,0.6,0.5,0.7,0,0},
								 {0.9,0,0.8,0,0,0,0,0,0},
								 {0,0.9,0,0,0.9,0,0,0,0},
								 {0.9,0, 0,0.8,0,0.7,0,0,0},
								 {0,0,0.4,0,0,0,0.5,0,0.5 },
								 {0.6,0.5,0,0,0,0,0,0.8,0}
								 };//信任矩阵

	/*stack* S = init_stack();
	double ret=trust_propagation(T, 6, 3, S);
	printf("%lf ", ret);*/
	

	double T1[NUMBER][NUMBER] = { 0 };
	update_trust_matrix(T,T1);//预建立的信任值

	double T2[NUMBER][NUMBER] = { 0 };
	similarity_matrix(p, T2);

	double T3[NUMBER][NUMBER] = { 0 };
	trust_building(T, T1, T2, T3);//初始信任值，更新后信任值，相似性矩阵，信任指标矩阵
	

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
	/*printf("\n更新后的信任值:\n");
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			printf("%lf ", T1[i][j]);
		}
		printf("\n");
	}*/
	
	reach_consensus(p, T, confidence, selfness);
	double CIn[NUMBER] = { 0 };
	for (i = 0; i < NUMBER; i++)
	{
		for (j = 0; j < NUMBER; j++)
		{
			CIn[i] += T[j][i];//列加和
		}
	}
	printf("\n专家常规影响力:\n");
	normalization(CIn, NUMBER);
	print(CIn, NUMBER);
	
	printf("\n专家卡兹影响力:\n");
	double KIn[NUMBER] = { -34.807,-37.738,-38.284,-18.037,-9.687,-11.168,-20.738,-16.015,-13.075 };
	normalization(KIn, NUMBER);
	print(KIn, NUMBER);

	printf("\n专家胡贝尔影响力:\n");
	double HIn[NUMBER] = { -33.807,-36.738,-37.284,-17.037,-8.687,-10.168,-19.738,-15.015,-12.075 };
	normalization(HIn, NUMBER);
	print(HIn, NUMBER);

	printf("\n专家泰勒影响力:\n");
	double TIn[NUMBER] = { 0.074,0.086,0.127,-0.057,-0.052,-0.092,-0.073,0.006,-0.018 };
	print(TIn, NUMBER);

	printf("\n专家决策权重:\n");
	double In[NUMBER] = { 0 };
	for (i = 0; i < NUMBER; i++)
	{
		In[i] = P1 * CIn[i] + P2 * KIn[i] + P3 * HIn[i] + P4 * TIn[i];
	}
	print(In, NUMBER);
	printf("\n------------------------------------------------------------------------------------\n");
	
	double CV[ROW][COL] = { 0 };//集体评估矩阵
	collective_evaluation(p, In, CV);
	printf("\n------------------------------------------------------------------------------------\n");
	double Wo[COL] = { 0 };//客观属性权重
	objective_height(CV, Wo);
	double Ws[COL] = { 0.1769 , 0.1919 , 0.2020 , 0.1992 , 0.2299 };//主观属性权重，Matlib给出
	printf("\n属性主观权重:\n");
	print(Ws, COL);
	printf("\n属性权重:\n");
	double W[COL] = { 0 };
	for (i = 0; i < COL; i++)
	{
		W[i] = Wo[i]*C2 + Ws[i]*(1-C2);
	}
	print(W, COL);
	printf("\n------------------------------------------------------------------------------------\n");
	decision(CV, W);
	printf("\n------------------------------------------------------------------------------------\n");







	//int i, j;
	//int arr1[ROW][COL] = { 0 }; int(*p1)[COL] = arr1;
	//int arr2[ROW][COL] = { 0 }; int(*p2)[COL] = arr2;
	//int arr3[ROW][COL] = { 0 }; int(*p3)[COL] = arr3;
	//int arr4[ROW][COL] = { 0 }; int(*p4)[COL] = arr4;
	//int arr5[ROW][COL] = { 0 }; int(*p5)[COL] = arr5;
	//int arr6[ROW][COL] = { 0 }; int(*p6)[COL] = arr6;
	//int arr7[ROW][COL] = { 0 }; int(*p7)[COL] = arr7;
	//int arr8[ROW][COL] = { 0 }; int(*p8)[COL] = arr8;
	//int arr9[ROW][COL] = { 0 }; int(*p9)[COL] = arr9;
	//int arr10[ROW][COL] = { 0 }; int(*p10)[COL] = arr10;
	//int arr11[ROW][COL] = { 0 }; int(*p11)[COL] = arr11;
	//int arr12[ROW][COL] = { 0 }; int(*p12)[COL] = arr12;
	//int arr13[ROW][COL] = { 0 }; int(*p13)[COL] = arr13;
	//int arr14[ROW][COL] = { 0 }; int(*p14)[COL] = arr14;
	//int arr15[ROW][COL] = { 0 }; int(*p15)[COL] = arr15;
	//int arr16[ROW][COL] = { 0 }; int(*p16)[COL] = arr16;
	//int arr17[ROW][COL] = { 0 }; int(*p17)[COL] = arr17;
	//int arr18[ROW][COL] = { 0 }; int(*p18)[COL] = arr18;
	//int arr19[ROW][COL] = { 0 }; int(*p19)[COL] = arr19;
	//int arr20[ROW][COL] = { 0 }; int(*p20)[COL] = arr20;
	//int arr21[ROW][COL] = { 0 }; int(*p21)[COL] = arr21;
	//int arr22[ROW][COL] = { 0 }; int(*p22)[COL] = arr22;
	//int arr23[ROW][COL] = { 0 }; int(*p23)[COL] = arr23;
	//int arr24[ROW][COL] = { 0 }; int(*p24)[COL] = arr24;
	//int arr25[ROW][COL] = { 0 }; int(*p25)[COL] = arr25;
	//int arr26[ROW][COL] = { 0 }; int(*p26)[COL] = arr26;
	//int arr27[ROW][COL] = { 0 }; int(*p27)[COL] = arr27;
	//int arr28[ROW][COL] = { 0 }; int(*p28)[COL] = arr28;
	//int arr29[ROW][COL] = { 0 }; int(*p29)[COL] = arr29;
	//int arr30[ROW][COL] = { 0 }; int(*p30)[COL] = arr30;
	//int(*p[NUMBER])[COL] = { p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,
	//	p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
	//	p21,p22,p23,p24,p25,p26,p27,p28,p29,p30 };
	//int k;
	//for (i = 0; i < NUMBER; i++)
	//{
	//	for (j = 0; j < ROW; j++)
	//	{
	//		for (k = 0; k < COL; k++)
	//		{
	//			(p[i])[j][k] = rand() % 100;
	//		}
	//	}
	//}
	///*for (i = 0; i < NUMBER; i++)
	//{
	//	printf("V%d:\n", i+1);
	//	print_int(p[i], ROW, COL);
	//}*/
	//double T[NUMBER][NUMBER] = { 0 };
	//for (i = 0; i < NUMBER; i++)
	//{
	//	for (j = 0; j < NUMBER; j++)
	//	{
	//		if ((j - i) == 1) T[i][j] = 0.6;
	//		else T[i][j] = 0;
	//	}
	//}
	//int t = NUMBER - 1;
	//T[t][0] = 0.6;
	///*print_double(T,NUMBER,NUMBER);*/
	//double T1[NUMBER][NUMBER] = { 0 };
	//update_trust_matrix(T, T1);//预建立的信任值
	//double T2[NUMBER][NUMBER] = { 0 };
	//similarity_matrix(p, T2);
	//double T3[NUMBER][NUMBER] = { 0 };
	//trust_building(T, T1, T2, T3);//初始信任值，更新后信任值，相似性矩阵，信任指标矩阵
	//double confidence[NUMBER] = { 0 };
	//double selfness[NUMBER] = { 0 };
	//for (i = 0; i < NUMBER; i++)
	//{
	//	confidence[i] = 0.5; selfness[i] = 0.5;
	//}
	//reach_consensus(p, T, confidence, selfness);
	return 0;
}