#pragma once

//game.h--��������
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY 10

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//��ʼ��
void init_board(char arr[ROWS][COLS], int rows, int cols, char ch);
//������
void set_mine(char arr[ROW][COL],int row,int col);
//��ӡ����
void display_board(char arr[ROW][COL], int row, int col);
//ɨ��
void fine_mine(char mine[ROW][COL],char show[ROW][COL],int row,int col);
