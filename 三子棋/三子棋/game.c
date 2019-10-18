#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void InitBoard(char board[][COL], int row , int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < row;j++){
			board[i][j] = ' ';
		}
	}
}
/*
   |   |
---|---|---
   |   | 
---|---|---
   |   | 
*/
//打印棋盘
void showBoard(char board[][COL], int row, int col){
	int i; int j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col;j++){
			printf(" %c ", board[i][j]);
			if (j < col - 1){
				printf("|");
			}
		}
		printf("\n");
		if (i < row-1){
			for (j = 0; j < col; j++){
				if (j < col - 1){
					printf("---|");
				}
				else{ printf("---"); }
			}
			printf("\n");
		}
	}

}
//玩家下棋
void PlayerMove(char board[][COL], int row, int col){
	int i, j;
	while (1){
		printf("玩家下棋\n");
		printf("请输入你想要下的位置坐标： ");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= 3){
			if (board[i - 1][j - 1] == ' '){
				board[i - 1][j - 1] = '1';
				break;
			}
			else if (board[i - 1][j - 1] != ' '){
				printf("该位置已经被下过，请重新输入！\n");
			}
		}
		else{ printf("输入不合法！\n");
		}
	}
}
//判断是否胜利
int IsWin(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){ //判断行
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
			return board[i][0];
		}
    }
	for (int j = 0; j < row; j++){ //判断列
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' '){
			return board[0][j];
		}
	}
	//判断两条对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
		return board[0][2];
	}
	if (Isfull(board, row, col)){
		return 'A';//代表平局
	}
	return 'n';//没输没赢没平局 接着下
}
//判断棋盘是否满了
int Isfull(char board[][COL], int row, int col){
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;//满了
}
//电脑下棋
void ComputerMove(char board[][ROW], int row, int col){
	printf("电脑下棋\n");
	int i = 0; int j = 0;
	while (1){
		i = rand() % row;//随机生成一个0到row的横坐标
		j = rand() % col;
	 if (board[i][j] == ' '){ //如果没被下过直接下在该位置  如果下过接着生成随机坐标
			board[i - 1][j - 1] = '0';
			break;
		}

	}

}
