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
SListNode* BuySListNode(SLTDataType x);//创造一个结点
void SListPushFront(SListNode** plist, SLTDataType x);//头插
void SListPopFront(SListNode** pplist);//头删除
SListNode* SListFind(SListNode** plist, SLTDataType x);//找某个节点并返回
void SListInsertAfter(SListNode** pos, SLTDataType x);//在pos后面插入x的值
void SListInsertFront(SListNode* pos, SLTDataType x);//在pos前面插入x的值


