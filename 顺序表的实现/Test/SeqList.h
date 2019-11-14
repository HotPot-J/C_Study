#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType  *arry; 
	size_t  size;
	size_t capicity;
}SeqList;
void SeqListPrint(SeqList* psl);//��ӡ������Ա�
void SeqListInit(SeqList* psl);//��ʼ��
void CheckCapacity(SeqList* psl);//��� �ڿռ䲻��ʱ����
void SeqListPushBack(SeqList* psl, SLDataType x);//β������
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* psl);//ͷɾ
int SeqListFind(SeqList* psl, SLDataType x);//����ĳһ����ֵ�������±�
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//��ĳ��λ�ò�������
void SeqListBubbleSort(SeqList* psl);//ð������˳���
void SeqListRemoveAll(SeqList* psl, SLDataType x); //ɾ��˳��������е�x

