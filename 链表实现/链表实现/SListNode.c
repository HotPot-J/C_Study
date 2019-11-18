#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"
//newhead = tail = (ListNode *)malloc(sizeof(ListNode));//Ϊ�����ռ�newhead��tail��ָ��ͬһ����ַ
void SListprint(SListNode **pplist){
	SListNode *cur = *pplist;
	while (cur){
		printf("->%d", ((cur)->data));
		cur = cur->next;
	}
	printf("\n");
}

SListNode* BuySListNode(SLTDataType x){
	SListNode *Node = (SListNode*)malloc(sizeof(SListNode));
	Node->data = x;
	Node->next = NULL;
	return Node;
}
void SListPushFront(SListNode** pplist, SLTDataType x){
	SListNode *NewNode =  BuySListNode(x);
	if (*pplist == NULL){
		*pplist= NewNode;
	}
	else{
		NewNode->next = *pplist;
		*pplist = NewNode;
	}
}
void SListPopFront(SListNode** pplist){
	assert(*pplist);
	SListNode *del = *pplist;
	if ((*pplist)->next == NULL){
		return;
	}
	if ((*pplist)->next == NULL){
		free(del);
		*pplist = NULL;
	}
	else{
		SListNode *next = del->next;
		free(del);
		*pplist = next;
	}
}
SListNode* SListFind(SListNode** pplist, SLTDataType x){
	SListNode *find = *pplist;
	while (find){
		if (find->data == x){
			return find;
		}
		else{
			find = find->next;
		}
	}
	return find; //���ִ�иò� ˵��δ�ҵ�x ����NULL
}

void SListInsertAfter(SListNode** pos, SLTDataType x){ //��pos�������x��ֵ
	SListNode *newNode = BuySListNode(x);
	SListNode *next = (*pos)->next;
	if (*pos == NULL){
		*pos = newNode;
	}
	(*pos)->next = newNode;
	newNode->next = next;
}

