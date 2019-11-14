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
	return - 1;//����û�ҵ�
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x){
	assert(psl!= NULL);
	int i = 0;
	int j = psl->size - 1;
	int flag = 0; //��������������������ѭ��
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
	   �Ƶ����̣�
	              
 �ٲ����ǿռ临�Ӷ�   ����һ�������� �������������� ��������x�������򱣴����������� ��x������������
 �ڿռ临�Ӷ�Ϊo��1����
                      ����i��j ��ʼʱ��Ϊ˳�����Ԫ�ص��±�ͬʱ����++ ������xʱj���� i++  
					  ֱ������arr[i]!=x  ��arr[i]��ֵ����arr[j]  �����ǵ�x   ���������  
					  ��j��ֵ����psl->size  (����j���ضϸ�˳���)�ﵽɾ����������x����Ŀ��

	�����Ƶ������ַ�ʽʱ�临�ӶȾ�ΪO��N��  
	*/
//�÷�����ʵ�֣�
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