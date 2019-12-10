#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int DataType;

typedef struct DListNode
{
	DataType data;
	struct DListNode *next;
	struct DListNode *previous;
} DListNode;

DListNode *BuyListNode(DataType data);
void DListInit(DListNode **pHead);
void DListPushBack(DListNode *pHead, DataType data);
void DListPopBack(DListNode *pHead);
void DListPushFront(DListNode *pHead, DataType data);
void DListPopFront(DListNode *pHead);
void DListInsert(DListNode *pos, DataType data);
void DListErase(DListNode *pos);
DListNode *DListFind(DListNode *pHead, DataType data);
void DListDestroy(DListNode *pHead);
void test();
void PrintDlist(DListNode* pHead);
#endif //_LINKLIST_H_