#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void menu(){
	printf("*****************************\n");
	printf("******1.����Ŀ�����ֵ�λ��***\n");
	printf("******2.����Ŀ������*********\n");
	printf("******3.��Ŀ�����ֵĽ���*****\n");
	printf("******4.������Ҫת���Ľ���***\n");
	printf("******5.��ʼת��*************\n");
	printf("******0.�˳�*****************\n");
	printf("===========================================\n");
	printf("\n");

}

int main(){
	int input = 0;//���Ʋ˵�ѡ��
	int bits = 0; //Ŀ�����ֵ�λ��
	SeqList Num ; //�洢Ŀ������
	int Num_10 = 0; //���Ŀ������ת��Ϊ��ʮ������
	int System = 0; //Ŀ�����ֵĽ���
	int SystemNum = 0; //Ŀ�Ľ���
	SeqList AimNum; //���Ŀ������
	int i = 0; //����ѭ��
	char tmp = '0'; //��ʱ�����������ֵ�ÿһλ���� ʹ����˳���
	SeqListInit(&Num);
	SeqListInit(&AimNum);
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1: //����Ŀ�����ֵ�λ��
			printf("������Ŀ������λ���ɣ�");
			scanf("%d", &bits);
			break;
		case 2:  //����Ŀ������
			printf("������Ŀ�����ְɣ�");//β���˳��� ��Ϊ�������ֵ�ϰ���Ǵ���߿�ʼ���� 
			for (i = 0; i < bits+1; i++){
				scanf("%c", &tmp);
				SeqListPushBack(&Num, tmp);
			}
			SeqListPrint(&Num);
			break;
		case 3:  //����Ŀ�����ֵĽ���
			printf("������Ŀ�����ֵĽ��ưɣ�");
			scanf("%d", &System);
			break;
		case 4: //������Ҫת���Ľ���
			printf("������Ŀ�����ֵĽ��ưɣ�");
			scanf("%d", &SystemNum);
			break;
		case 5: //��ʼת��
				if (System == 16){
					Num_10 = System16_10(&Num, bits, System);
				}
				else{
					Num_10 = System_10(&Num, bits, System);
				}
				System_N(&AimNum, Num_10, SystemNum);
				printf("ת��������£�\n");
				SeqListPrint(&AimNum);
			
			break;
		case 0: //�˳�
			break;
		default:
			break;
		}
	} while (input);
	SeqListDestory(&Num);
	SeqListDestory(&AimNum);
	return 0;
}