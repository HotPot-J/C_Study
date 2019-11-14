#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListPrint(SeqList* psl){
	size_t i = 0;
	for (i = 0; i < psl->size; i++){
		printf(" ->%d ", psl->arry[i]);
	}
	printf("\n");
}
void SeqListInit(SeqList* psl){
	assert(psl != NULL);
	psl->arry = NULL;
	psl->capicity = 0;
	psl->size = 0;
}
void CheckCapacity(SeqList* psl){
	assert(psl != NULL);
	size_t newcapocity = psl->capicity == 0 ? 4 : psl->capicity * 2;
	if (psl->capicity == psl->size){
		psl->arry = realloc(psl->arry, newcapocity*sizeof(SLDataType));
		psl->capicity = newcapocity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x){
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->arry[psl->size++] = x;
}
void SeqListPopBack(SeqList* psl){
	assert(psl != NULL);
	if(psl->size>0){
		psl->size--;
	}
	if (psl->size == 0){
		psl->arry = NULL;
	}
}
void SeqListPushFront(SeqList* psl, SLDataType x){
	assert(psl != NULL);
	int i = 0;
	CheckCapacity(psl);
	if (psl->size == 0){
		psl->arry[psl->size++] = x;
	}
	else{
		i = psl->size - 1;
		for (i; i >=0; i--){
			psl->arry[i+1] = psl->arry[i];
		}
		psl->arry[0] = x;
		psl->size++;
	}
}
void SeqListPopFront(SeqList* psl){
	assert(psl!=NULL);
	int i = 0;
	if (psl->size > 0){
		for (i; i < (int)psl->size; i++){
			psl->arry[i] = psl->arry[i + 1];
		}
		psl->size--;
	}
		if (psl->size == 0){
			psl->arry = NULL;
		}
}
int SeqListFind(SeqList* psl, SLDataType x){
	assert(psl != NULL);
	int i = 0;
	for (i; i < (int)psl->size; i++){

		if (psl->arry[i] == x){
			return  i;
		}
	}
	return - 1;//代表没找到
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x){
	assert(psl!= NULL);
	int i = 0;
	int j = psl->size - 1;
	int flag = 0; //如果增加数据完毕则跳出循环
	CheckCapacity(psl);
	for (i; i <(int) psl->size; i++){
		while (i == pos){
			for (j; j>=(int)pos; j--){
				psl->arry[j + 1] = psl->arry[j];
			}
			psl->arry[pos] = x;
			psl->size++;
			flag = 1;
			break;
		}
		if (flag){
			break;
		}
	}
}
void SeqListBubbleSort(SeqList* psl){
	assert(psl != NULL);
	int size = psl->size-1; //2 1 3 4 0
	                       // 5 4 3 2 1
							//4 3 2 1 5
							//3 2 1 4 5
							//2 1 3 4 5
							//1 2 3 4 5
                            
							
							
	int i = 0;
	int j = 0;
	SLDataType temp = 0;
	for (i=0; i < (int)psl->size; i++){
		for (j=0; j < size; j++){
			if (psl->arry[j] > psl->arry[j + 1]){
				temp = psl->arry[j + 1];
				psl->arry[j + 1] = psl->arry[j];
				psl->arry[j] = temp;
			}
		}
		size--;
	}
}
void SeqListRemoveAll(SeqList* psl, SLDataType x){
	/*
	   推到过程：
	              
 ①不考虑空间复杂度   定义一个新数组 遍历整个旧数组 遇见不是x的数组则保存在新数组中 是x则接着往后遍历
 ②空间复杂度为o（1）：
                      定义i和j 开始时均为顺序表首元素的下表同时往后++ 在遇见x时j不动 i++  
					  直到遇见arr[i]!=x  把arr[i]的值赋给arr[j]  即覆盖掉x   当遍历完成  
					  将j的值赋给psl->size  (即从j处截断该顺序表)达到删除表中所有x发的目的

	上述推导的两种方式时间复杂度均为O（N）  
	*/
//用方法②实现：
	int i = 0;
	int j = 0;
	while (i < (int)psl->size){
		if (i == j){
			if (psl->arry[i] != x){
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		else{
			if (psl->arry[i] != x){
				psl->arry[j] = psl->arry[i];
				i++;
				j++;
			}
			else{
				i++;
			}
		}
	}
	psl->size = j;
}