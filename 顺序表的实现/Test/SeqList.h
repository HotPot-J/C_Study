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
void SeqListPrint(SeqList* psl);//打印输出线性表
void SeqListInit(SeqList* psl);//初始化
void CheckCapacity(SeqList* psl);//检查 在空间不足时扩容
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插数据
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);//头插
void SeqListPopFront(SeqList* psl);//头删
int SeqListFind(SeqList* psl, SLDataType x);//查找某一个数值并返回下标
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//在某个位置插入数据
void SeqListBubbleSort(SeqList* psl);//冒泡排序顺序表
void SeqListRemoveAll(SeqList* psl, SLDataType x); //删除顺序表中所有的x

