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
	InitBoard(mineinfo, ROWS, ROWS, '*');//��ʼ������
	InitBoard(mine, ROWS, ROWS, '0');//��ʼ������
	ShowBoard(mineinfo, ROWS, ROWS);//��ӡ����

	SetMine(mine, ROW, COL);//��������
	ShowBoard(mine, ROWS, ROWS);
	FindMine(mineinfo,mine, ROWS, ROWS);//����
	
}
int main(){
	int input = 0;
	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("����������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
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