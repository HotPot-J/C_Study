#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu(){
	printf("***********************\n");
	printf("*********0.exit********\n");
	printf("*********1.play********\n");
	printf("***********************\n");
}
void game(){
	char mineinfo[ROWS][COLS];//*
	char mine[ROWS][COLS];//'0'
	InitBoard(mineinfo, ROWS, ROWS, '*');//初始化棋盘
	InitBoard(mine, ROWS, ROWS, '0');//初始化雷盘
	ShowBoard(mineinfo, ROWS, ROWS);//打印棋盘

	SetMine(mine, ROW, COL);//布置雷盘
	ShowBoard(mine, ROWS, ROWS);
	FindMine(mineinfo,mine, ROWS, ROWS);//找雷
	
}
int main(){
	int input = 0;
	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("请输入您的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			break;

		}
	} while (input);


	return 0;
}