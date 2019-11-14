#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
int main(){
	SeqList psl;
	SeqListInit(&psl);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 2);
	SeqListPushFront(&psl, 3);
	SeqListPushFront(&psl, 2);
	SeqListPushFront(&psl, 5);
	SeqListPushFront(&psl, 6);
	SeqListPushFront(&psl, 7);
	//SeqListPopFront(&psl);
	//SeqListPrint(&psl);
	//SeqListInsert(&psl, 1, 7);
	//SeqListPrint(&psl);
	//printf("%d\n", SeqListFind(&psl, 3));
	SeqListBubbleSort(&psl);
	SeqListRemoveAll(&psl, 1);
	SeqListPrint(&psl);
	


	return 0;
}