#define _CRT_SECURE_NO_WARNINGS 1
#include"QueueStack.h"
/*
核心思想：
    建立两个队列 相互导数据即可实现栈的功能  画图推导过程保存在本文件下
*/
int main(){
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackPush(obj, 3);
	return 0;
}