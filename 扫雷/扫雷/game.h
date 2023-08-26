#pragma once

//game.h--函数声明
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY 10

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//初始化
void init_board(char arr[ROWS][COLS], int rows, int cols, char ch);
//布置雷
void set_mine(char arr[ROW][COL],int row,int col);
//打印棋盘
void display_board(char arr[ROW][COL], int row, int col);
//扫雷
void fine_mine(char mine[ROW][COL],char show[ROW][COL],int row,int col);
