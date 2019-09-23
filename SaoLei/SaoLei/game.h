#pragma once
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINENUM 10 //³õÊ¼»¯10¸öÀ×

void InitBoard(char board[][ROWS], int rows, int cols, char a);
void ShowBoard(char board[][ROWS], int rows, int cols);
void SetMine(char board[][ROWS], int row, int col);
void FindMine(char mineinfo[][ROWS],char mine[][ROWS] ,int row, int col);
int GetMine(char mine[][COLS], int x, int y);