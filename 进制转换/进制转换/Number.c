#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//����˼· �� �����н������ֶ�ת��Ϊ10���� Ȼ������ʮ��������Ŀ�������  
//��Ҫ�õ�����η��ĺ��� �Զ���ʵ��һ��pow_int  ����
int Pow_int(int resource, int pow){  //�����õ��˵ݹ�
	if (pow == 0){
		return 1;
	}
	else{
		return resource * Pow_int(resource, --pow);
	}
}
//�Ȱ����е��������ֶ���Ϊʮ����
int System_10(SeqList* psl, int bits,int System){
	int ret = 0;
	int flag = bits-1;
	for (int i = 1; i < bits+1; i++){
		ret = ret + (psl->arry[i] - '0' )* Pow_int(System, flag--);
	}
	return ret;
}
//�Ȱ����е�����16�������ֶ���Ϊʮ����
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

//ת��ΪN���Ʋ����������˳�����
void  System_N(SeqList* psl, int Num_10, int SystemNum){
	int tmp;
	while (Num_10){
		if (SystemNum != 16){
			SeqListPushFront(psl, (Num_10 % SystemNum) + '0'); //���ݸý���ת���㷨 ��Ҫ�����յ��������ü�Ϊ���ս�� 
			//����ֱ�Ӳ���ͷ�弴�ɴﵽ���õ�Ч��
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