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
	int count = MINENUM; //��¼�����׵�����
	int x = 0; 
	int y = 0; //x y �ֱ�Ϊ�׵ĺ�������
	while (count != 0 )
	{
		x = rand() % row+1;//Ϊ�˲���һ��[1��10��������� 
		y = rand() % row + 1;
		if (board[x][y] == '0'){
			board[x][y] = '1';
			count--;
		}
	}
}
int GetMine(char mine[][COLS], int x, int y){    //Ѱ��x,y������Χ�м����ײ�����  ���ַ�+����=�ַ�
	return    mine[x - 1][y - 1] - '0' +                                                      //'1'-'0'=1��
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
		printf("������������꣺ ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9){
			if (mine[x][y] == '1'){
				printf("�㱻ը���ˣ�\n");
				break;
			}
			else{
				count++;
				             //�ҵ��Ա�8��λ���м����ף�Ȼ�󽫵�ǰλ����Ϊ�׵ĸ�����
				             // '1'+1 = '2'; 
				int mineMun = GetMine(mine, x, y);
				mineinfo[x][y] = mineMun+ '0';
				ShowBoard(mineinfo, ROWS, ROWS);
			}
		}  
		else{
			printf("�������겻�Ϸ���\n");
        }

	}
	if (count == row*col - MINENUM){
		printf("ɨ�׳ɹ���\n");
	}

}