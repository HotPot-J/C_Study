#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef char SLDataType;
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
void SeqListDestory(SeqList* psl); //����˳���
int Pow_int(int resource, int pow); //�Զ����ݺ���
int System_10(SeqList* psl, int bits, int System); //�����н�������ת��Ϊ10��������
int System16_10(SeqList* psl, int bits, int System);//��16��������ת��Ϊ10��������
void System_N(SeqList* psl, int Num_10, int SystemNum);//��10������ת��ΪN��������
