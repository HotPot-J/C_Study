#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListPrint(SeqList* psl){
	size_t i = 0;
	for (i = 0; i < psl->size; i++){
		printf("%c", psl->arry[i]);
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
	if (psl->size>0){
		psl->size--;
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
		for (i; i >= 0; i--){
			psl->arry[i + 1] = psl->arry[i];
		}
		psl->arry[0] = x;
		psl->size++;
	}
}
void SeqListPopFront(SeqList* psl){
	assert(psl != NULL);
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
void SeqListDestory(SeqList* psl){
	free(psl->arry);
	psl->arry = NULL;
	psl->capicity = 0;
	psl->size = 0;
}
