#pragma once


#define ROW 3
#define COL 3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//��ʼ������
void init_board(char arr, int row, int col);
//չʾ����
void display_board(char arr, int row, int col);
//�������
void player_move(char arr, int row, int col);
//��������
void computer_move(char arr, int row, int col);
//�ж���Ϸ״̬
char is_win(char arr, int row, int col);