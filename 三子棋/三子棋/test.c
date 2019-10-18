#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu(){
	printf("*******请输入*********\n");
	printf("*******1为游戏开始*********\n");
	printf("*******0为退出游戏*********\n");
}
void game(){
	char ret;
	char board[3][3] = {0};
	InitBoard(board, ROW, COL);
	showBoard(board, ROW, COL);
	while (1){
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'n'){
			break;
		}
		showBoard(board, ROW, COL);
			ComputerMove(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'n'){
				break;
			}
			showBoard(board, ROW, COL);
	}
	if (ret == 'A'){
		printf("平局");	
	}
	if (ret == '1'){
		printf("恭喜你获胜！\n");
	}
	if (ret == '0'){
		printf("电脑获胜≧ ﹏ ≦\n");
    }

}
int main(){
	srand((unsigned int)time(NULL));
	int input;
	do
	{   
		menu();
		scanf("%d", &input);
		switch (input){
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