#pragma once
#include<stdio.h>
#include<stdlib.h>//rand();
#include<time.h>//���������������Ҫ��ͷ�ļ�
#define ROW  3
#define COL  3
void InitBoard(char board[][COL], int row, int col);
void showBoard(char board[][COL], int row, int col);
void PlayerMove(char board[][COL], int row, int col);
int IsWin(char board[][COL], int row, int col);
void ComputerMove(char board[][ROW], int row, int col);
int Isfull(char board[][COL], int row, int col);