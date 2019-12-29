#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//整体思路 ： 把所有进制数字都转化为10进制 然后再由十进制生成目标进制数  
//需要用到计算次方的函数 自定义实现一个pow_int  函数
int Pow_int(int resource, int pow){  //这里用到了递归
	if (pow == 0){
		return 1;
	}
	else{
		return resource * Pow_int(resource, --pow);
	}
}
//先把所有的输入数字都变为十进制
int System_10(SeqList* psl, int bits,int System){
	int ret = 0;
	int flag = bits-1;
	for (int i = 1; i < bits+1; i++){
		ret = ret + (psl->arry[i] - '0' )* Pow_int(System, flag--);
	}
	return ret;
}
//先把所有的输入16进制数字都变为十进制
int System16_10(SeqList* psl, int bits, int System){
	int ret = 0;
	int flag = bits-1;
	for (int i = 1; i < bits+1; i++){
		switch (psl->arry[i])
		{
		case '1':
			ret = ret + 1* Pow_int(System, flag--);
			break;
		case '2':
			ret = ret + 2 * Pow_int(System, flag--);
			break;
		case '3':
			ret = ret + 3 * Pow_int(System, flag--);
			break;
		case '4':
			ret = ret + 4 * Pow_int(System, flag--);
			break;
		case '5':
			ret = ret + 5 * Pow_int(System, flag--);
			break;
		case '6':
			ret = ret + 6 * Pow_int(System, flag--);
			break;
		case '7':
			ret = ret + 7 * Pow_int(System, flag--);
			break;
		case '8':
			ret = ret + 8 * Pow_int(System, flag--);
			break;
		case '9':
			ret = ret + 9 * Pow_int(System, flag--);
			break;
		case 'A':
			ret = ret + 10 * Pow_int(System, flag--);
			break;
		case 'B':
			ret = ret + 11 * Pow_int(System, flag--);
			break;
		case 'C':
			ret = ret + 12 * Pow_int(System, flag--);
			break;
		case 'D':
			ret = ret + 13 * Pow_int(System, flag--);
			break;
		case 'E':
			ret = ret + 14 * Pow_int(System, flag--);
			break;
		case 'F':
			ret = ret + 15 * Pow_int(System, flag--);
			break;
		default:
			break;
		}
	}
	return ret;
}

//转换为N进制并将结果存在顺序表中
void  System_N(SeqList* psl, int Num_10, int SystemNum){
	int tmp;
	while (Num_10){
		if (SystemNum != 16){
			SeqListPushFront(psl, (Num_10 % SystemNum) + '0'); //根据该进制转换算法 需要将最终的余数倒置即为最终结果 
			//所以直接采用头插即可达到倒置的效果
			Num_10 = Num_10 / SystemNum;
		}
		else{
			tmp = Num_10 % 16;
			switch (tmp)
			{
			case 1:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 2:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 3:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 4:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 5:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 6:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 7:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 8:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 9:
				SeqListPushFront(psl, tmp + '0');
				break;
			case 10:
				SeqListPushFront(psl, 'A');
				break;
			case 11:
				SeqListPushFront(psl, 'B');
				break;
			case 12:
				SeqListPushFront(psl, 'C');
				break;
			case 13:
				SeqListPushFront(psl, 'D');
				break;
			case 14:
				SeqListPushFront(psl, 'E');
				break;
			case 15:
				SeqListPushFront(psl, 'F');
				break;
			default:
				break;
			}
			Num_10 = Num_10 / SystemNum;
		}
	}
}