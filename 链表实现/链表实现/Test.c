#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"
int main(){
	SListNode *plist = NULL;
	SListPushFront(&plist,1 );
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListprint(&plist);
	SListNode *a = (SListFind(&plist, 3));
	SListNode *b = (SListFind(&plist, 1));
	SListNode *c = (SListFind(&plist, 2));
	SListInsertAfter(&a, 4);
	SListInsertAfter(&b, 4);
	SListInsertAfter(&c, 4);
	SListprint(&plist);
	

}