#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QUDataType;
typedef struct QueueNode{
	struct QueueNode* next;
	QUDataType data;
}QueueNode;
typedef struct Queue{
	QueueNode* front;
	QueueNode* rear;
}Queue;
typedef struct {
	Queue Q1;
	Queue Q2;
} MyStack;

void QueuePrint(Queue pq);
void QueueInit(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue pq);
void QueueDestory(Queue* pq);

/** Initialize your data structure here. */

MyStack* myStackCreate();

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x);

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj);

/** Get the top element. */
int myStackTop(MyStack* obj);

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj);

void myStackFree(MyStack* obj);