#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu(){
	printf("*******������*********\n");
	printf("*******1Ϊ��Ϸ��ʼ*********\n");
	printf("*******0Ϊ�˳���Ϸ*********\n");
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
		printf("ƽ��");	
	}
	if (ret == '1'){
		printf("��ϲ���ʤ��\n");
	}
	if (ret == '0'){
		printf("���Ի�ʤ�R �n �Q\n");
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
				printf("��Ϸ�˳�\n");
				break;
			default:
				break;
		}
	} while (input);

	return 0;
}