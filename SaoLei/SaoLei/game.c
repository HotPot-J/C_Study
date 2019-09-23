#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[][ROWS], int rows, int cols, char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++){
		for (j = 0; j < COLS; j++){
			board[i][j] = set;
		}
	}
}

void ShowBoard(char board[][ROWS], int rows, int cols){
	int i = 0;
	int j = 0;

	for (i = 0; i < rows - 1; i++){
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i < rows - 1; i++){
		printf(" %d ", i);
		for (j = 1; j < cols - 1; j++){
			
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("====================================\n");
}
void SetMine(char board[][ROWS], int row, int col){
	int count = MINENUM; //记录设置雷的数量
	int x = 0; 
	int y = 0; //x y 分别为雷的横纵坐标
	while (count != 0 )
	{
		x = rand() % row+1;//为了产生一个[1，10）的随机数 
		y = rand() % row + 1;
		if (board[x][y] == '0'){
			board[x][y] = '1';
			count--;
		}
	}
}
int GetMine(char mine[][COLS], int x, int y){    //寻找x,y坐标周围有几个雷并返回  （字符+数字=字符
	return    mine[x - 1][y - 1] - '0' +                                                      //'1'-'0'=1）
		mine[x - 1][y] - '0' +
		mine[x - 1][y + 1] - '0' +
		mine[x][y + 1] - '0' +
		mine[x + 1][y + 1] - '0' +
		mine[x + 1][y] - '0' +
		mine[x + 1][y - 1] - '0' +
		mine[x][y - 1] - '0';
}
void FindMine(char mineinfo[][ROWS],char mine[][ROWS], int row, int col){
	int x = 0;
	int y = 0;
	int count = 0;
	while (count<row*col - MINENUM){
		printf("请输入你的坐标： ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9){
			if (mine[x][y] == '1'){
				printf("你被炸死了！\n");
				break;
			}
			else{
				count++;
				             //找到旁边8个位置有几个雷？然后将当前位置置为雷的个数。
				             // '1'+1 = '2'; 
				int mineMun = GetMine(mine, x, y);
				mineinfo[x][y] = mineMun+ '0';
				ShowBoard(mineinfo, ROWS, ROWS);
			}
		}  
		else{
			printf("输入坐标不合法！\n");
        }

	}
	if (count == row*col - MINENUM){
		printf("扫雷成功！\n");
	}

}