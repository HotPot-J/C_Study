#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��ʼ������
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
//��ӡ����
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
//�������
void PlayerMove(char board[][COL], int row, int col){
	int i, j;
	while (1){
		printf("�������\n");
		printf("����������Ҫ�µ�λ�����꣺ ");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= 3){
			if (board[i - 1][j - 1] == ' '){
				board[i - 1][j - 1] = '1';
				break;
			}
			else if (board[i - 1][j - 1] != ' '){
				printf("��λ���Ѿ����¹������������룡\n");
			}
		}
		else{ printf("���벻�Ϸ���\n");
		}
	}
}
//�ж��Ƿ�ʤ��
int IsWin(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){ //�ж���
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
			return board[i][0];
		}
    }
	for (int j = 0; j < row; j++){ //�ж���
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' '){
			return board[0][j];
		}
	}
	//�ж������Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
		return board[0][2];
	}
	if (Isfull(board, row, col)){
		return 'A';//����ƽ��
	}
	return 'n';//û��ûӮûƽ�� ������
}
//�ж������Ƿ�����
int Isfull(char board[][COL], int row, int col){
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;//����
}
//��������
void ComputerMove(char board[][ROW], int row, int col){
	printf("��������\n");
	int i = 0; int j = 0;
	while (1){
		i = rand() % row;//�������һ��0��row�ĺ�����
		j = rand() % col;
	 if (board[i][j] == ' '){ //���û���¹�ֱ�����ڸ�λ��  ����¹����������������
			board[i - 1][j - 1] = '0';
			break;
		}

	}

}
