#define _CRT_SECURE_NO_WARNINGS 1
#include"QueueStack.h"
/*
����˼�룺
    ������������ �໥�����ݼ���ʵ��ջ�Ĺ���  ��ͼ�Ƶ����̱����ڱ��ļ���
*/
int main(){
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackPush(obj, 3);
	return 0;
}