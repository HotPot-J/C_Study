#define _CRT_SECURE_NO_WARNINGS 1
#include"QueueStack.h"
void QueuePrint(Queue pp){
	if (pp.front == pp.rear&&pp.front != NULL){
		printf("%d->", pp.front->data);
	}
	else{
		while (pp.front != pp.rear){
			printf("%d->", pp.front->data);
			pp.front = pp.front->next;
			if (pp.front == pp.rear){
				printf("%d", pp.front->data);
			}
		}
	}
	printf("\n");
}
void QueueInit(Queue* pq){
	pq->front = NULL;
	pq->rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x){
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void QueuePush(Queue* pq, QUDataType x){
	QueueNode* newNode = BuyQueueNode(x);
	if (pq->front == pq->rear&&pq->front == NULL){//如果时第一个数据入队
		pq->front = newNode;
		pq->rear = newNode;
	}
	else{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}

}
void QueuePop(Queue* pq){
	if (pq->front != NULL){
		QueueNode* pop = pq->front;
		pq->front = pq->front->next;
		free(pop);
	}
	if (pq->front == NULL){
		pq->rear = NULL;
	}
}
QUDataType QueueFront(Queue* pq){
	QUDataType num = pq->front->data;
	return num;
}
QUDataType QueueBack(Queue* pq){
	QUDataType num = pq->rear->data;
	return num;
}
int QueueEmpty(Queue* pq){
	if (pq->front == NULL && pq->rear == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int QueueSize(Queue pq){
	int flag = 1;
	if (pq.front == NULL && pq.rear == NULL){
		return 0;
	}
	else{
		while (pq.front != pq.rear){
			flag++;
			pq.front = pq.front->next;
		}
		return flag;
	}
}
void QueueDestory(Queue* pq){
	QueueNode* cur = pq->front;
	while (cur != NULL){
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *_MyStack = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&(_MyStack->Q1));
	QueueInit(&(_MyStack->Q2));
	return _MyStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) { //入栈时将数据都存放在不为空的Q中
	if (QueueEmpty(&(obj->Q1))){
		QueuePush(&(obj->Q2), x);
	}
	else{
		QueuePush(&(obj->Q1), x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {  //出栈时先将前N-1放入为空的Q中 再将第N个数据弹出
	int LastData = 0;
	if (QueueEmpty(&(obj->Q2))){ //把Q1中的数据放到Q2中 
		while (obj->Q1.front != obj->Q1.rear){
			QueuePush(&(obj->Q2), QueueFront(&(obj->Q1)));
			QueuePop(&(obj->Q1));
		}
		LastData = (obj->Q1.front)->data;
		QueuePop(&(obj->Q1));
		return LastData;
	}
	else{                                      //把Q2中的数据放到Q1中 
		while (obj->Q2.front != obj->Q2.rear){
			QueuePush(&(obj->Q1), QueueFront(&(obj->Q2)));
			QueuePop(&(obj->Q2));
		}
		LastData = (obj->Q2.front)->data;
		QueuePop(&(obj->Q2));
		return LastData;
	}
}

/* Get the top element. */
int myStackTop(MyStack* obj){
	if (QueueEmpty(&(obj->Q1))){
		return (obj->Q2.rear)->data;
	}
	else{
		return (obj->Q1.rear)->data;
	}
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {  //如果栈中的两个队列均为空 则该队列为空
	if (QueueEmpty(&(obj->Q1)) && QueueEmpty(&(obj->Q2))){
		return 1;
	}
	else{
		return 0;
	}
}

void myStackFree(MyStack* obj) {
	QueueDestory(&(obj->Q1));
	QueueDestory(&(obj->Q2));
}
