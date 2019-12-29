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
void SeqListPrint(SeqList* psl);//打印输出线性表
void SeqListInit(SeqList* psl);//初始化
void CheckCapacity(SeqList* psl);//检查 在空间不足时扩容
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插数据
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);//头插
void SeqListPopFront(SeqList* psl);//头删
void SeqListDestory(SeqList* psl); //销毁顺序表
int Pow_int(int resource, int pow); //自定义幂函数
int System_10(SeqList* psl, int bits, int System); //将所有进制数都转化为10进制数；
int System16_10(SeqList* psl, int bits, int System);//将16进制数都转化为10进制数；
void System_N(SeqList* psl, int Num_10, int SystemNum);//将10进制数转化为N进制数；
