#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode{
	SLTDataType data;
	struct SListNode *next;
}SListNode;

void SListprint(SListNode **pplist);
SListNode* BuySListNode(SLTDataType x);//����һ�����
void SListPushFront(SListNode** plist, SLTDataType x);//ͷ��
void SListPopFront(SListNode** pplist);//ͷɾ��
SListNode* SListFind(SListNode** plist, SLTDataType x);//��ĳ���ڵ㲢����
void SListInsertAfter(SListNode** pos, SLTDataType x);//��pos�������x��ֵ
void SListInsertFront(SListNode* pos, SLTDataType x);//��posǰ�����x��ֵ


