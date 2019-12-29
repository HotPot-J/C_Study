#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void menu(){
	printf("*****************************\n");
	printf("******1.输入目标数字的位数***\n");
	printf("******2.输入目标数字*********\n");
	printf("******3.该目标数字的进制*****\n");
	printf("******4.输入需要转换的进制***\n");
	printf("******5.开始转换*************\n");
	printf("******0.退出*****************\n");
	printf("===========================================\n");
	printf("\n");

}

int main(){
	int input = 0;//控制菜单选项
	int bits = 0; //目标数字的位数
	SeqList Num ; //存储目标数字
	int Num_10 = 0; //存放目标数字转化为的十进制数
	int System = 0; //目标数字的进制
	int SystemNum = 0; //目的进制
	SeqList AimNum; //存放目的数字
	int i = 0; //控制循环
	char tmp = '0'; //临时保存输入数字的每一位数字 使其入顺序表
	SeqListInit(&Num);
	SeqListInit(&AimNum);
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1: //输入目标数字的位数
			printf("请输入目标数字位数吧：");
			scanf("%d", &bits);
			break;
		case 2:  //输入目标数字
			printf("请输入目标数字吧：");//尾插进顺序表 因为输入数字的习惯是从最高开始输入 
			for (i = 0; i < bits+1; i++){
				scanf("%c", &tmp);
				SeqListPushBack(&Num, tmp);
			}
			SeqListPrint(&Num);
			break;
		case 3:  //输入目标数字的进制
			printf("请输入目标数字的进制吧：");
			scanf("%d", &System);
			break;
		case 4: //输入需要转换的进制
			printf("请输入目的数字的进制吧：");
			scanf("%d", &SystemNum);
			break;
		case 5: //开始转换
				if (System == 16){
					Num_10 = System16_10(&Num, bits, System);
				}
				else{
					Num_10 = System_10(&Num, bits, System);
				}
				System_N(&AimNum, Num_10, SystemNum);
				printf("转换结果如下：\n");
				SeqListPrint(&AimNum);
			
			break;
		case 0: //退出
			break;
		default:
			break;
		}
	} while (input);
	SeqListDestory(&Num);
	SeqListDestory(&AimNum);
	return 0;
}