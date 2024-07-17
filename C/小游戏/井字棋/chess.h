#pragma once


#define ROW 3
#define COL 3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//初始化棋盘
void init_board(char arr, int row, int col);
//展示棋盘
void display_board(char arr, int row, int col);
//玩家下棋
void player_move(char arr, int row, int col);
//电脑下棋
void computer_move(char arr, int row, int col);
//判断游戏状态
char is_win(char arr, int row, int col);