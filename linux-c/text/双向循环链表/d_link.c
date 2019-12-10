#include"link.h"

void PrintDlist(DListNode* pHead)
{
	DListNode* cur = pHead;
	short i = 0;
	if (NULL == pHead)
	{
		printf("NULL\n");
		return;
	}
	while (pHead != cur->next)//最后一个节点的next指向头指针
	{
		printf("%d-->", cur->data);
		cur = cur->next;
		i++;
	}
	printf("%d-->%d\n", cur->data, pHead->data);

	printf("总共有%d个节点\n", i );
}

//头节点初始化
void DListInit(DListNode** pHead)
{
	assert(pHead);

	(*pHead) = (DListNode*)malloc(sizeof(DListNode));
	(*pHead)->next = (*pHead);
	(*pHead)->previous = (*pHead);
	(*pHead)->data = 0;
}

//创建一个节点
DListNode *BuyListNode(DataType data)
{
	DListNode *ret = (DListNode *)malloc(sizeof(DListNode));//动态分配一块节点大小的空间
	if (NULL == ret)
	{
		assert(0);
	}
	else
	{
		ret->data = data; //给节点中的数据块赋值
		ret->next = NULL;//给节点的前后指针域赋值
		ret->previous = NULL;
	}
	return ret;//返回节点的地址
}

//双向链表的尾插
void DListPushBack(DListNode *pHead, DataType data)
{
	DListNode *cur = NULL;
	//如果链表内只有头节点
	if (pHead->next == pHead)
	{
		cur = BuyListNode(data);
		pHead->next = cur;
		cur->previous = pHead;
		cur->next = pHead;
		pHead->previous = cur;
	}
	//如果链表内有其他节点
	else
	{
		cur = BuyListNode(data);
		pHead->previous->next  = cur;
		cur->previous = pHead->previous;
		pHead->previous = cur;
		cur->next = pHead;
	}
}

//双向链表的尾删
void DListPopBack(DListNode *pHead)
{
	DListNode *cur = NULL;//用来表示要删除的节点
	//如果链表内只有头节点，不用删除，直接返回
	if (pHead == pHead->next)
		return;
	else
	{
		cur = pHead->previous;//记录要删除的节点
		pHead->previous = cur->previous;//将头节点的prev域指向倒数最后一个节点
		cur->previous->next = pHead;//将删除节点的前一个节点的prev域指向头节点
		free(cur);
		cur = NULL;
	}
}

//头插
void DListPushFront(DListNode *pHead, DataType data)
{
	DListNode *cur = BuyListNode(data);
	//当链表只有头节点时
	if (pHead->next == pHead)
	{
		pHead->next = cur;
		cur->next = pHead;
		cur->previous = pHead;
		pHead->previous = cur;
	}
	else
	{
		cur->next = pHead->next;//将新节点的next域指向原链表中头节点后面的节点
		pHead->next ->previous = cur;//然后将原头节点中后面节点prev域指向新节点
		cur->previous = pHead;//将新节点prev域指向头节点
		pHead->next = cur;//将头节点的next域指向新节点
	}
}

//双向链表的头删
void DListPopFront(DListNode *pHead)
{
	DListNode *cur = pHead->next;
	if (pHead->next == pHead) //如果链表为空，直接返回
		return;
	else
	{
		pHead->next = cur->next;//将头节点的next域指向要删除节点下面的一个节点
		cur->next->previous = pHead;//将要删除节点的下一个节点的prev域指向头节点
		free(cur);
		cur = NULL;
	}
}


//在任意位置插入
void DListInsert(DListNode *pos, DataType data)
{
	DListNode *cur = BuyListNode(data);
	if (NULL == pos)
		return;
	//在指定位置之后插入一个节点
	else
	{
		cur->next = pos->next;
		cur->previous = pos;
		pos->next = cur;
		cur->next->previous = cur;
	}
}
//任意位置删除
void DListErase(DListNode *pos)
{
	if (pos == NULL) //如果指定位置为空的话
		return ;
	else
	{
		pos->previous->next = pos->next;//将指定位置前面节点的next域指向pos后面的节点
		pos->next->previous = pos->previous;//将指定位置后面节点的prev域指向pos前面的节点
		free(pos);
		pos = NULL;
	}
}

//其他的基本操作：

//查找Data数据的节点
DListNode *DListFind(DListNode *pHead, DataType data)
{
	DListNode *cur = pHead->next;//用来记录头节点的位置
	while (cur != pHead)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//销毁双向循环链表
void DListDestroy(DListNode *pHead)
{
	DListNode *cur = pHead->next;
	while (cur != pHead)
	{
		DListNode *ret = cur;
		cur = cur->next;
		free(ret);
		ret = NULL;
	}
	free(pHead);
	pHead = NULL;
}

//main.c


void Text()
{
	DListNode *pHead = NULL;
	DListInit(&pHead);
	PrintDlist(pHead);

	//DListDestroy(pHead);
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushFront(pHead, 4);
	DListPushFront(pHead, 5);
	PrintDlist(pHead);

	DListPopFront(pHead);
	PrintDlist(pHead);

	DListInsert(DListFind(pHead, 3), 6);
	PrintDlist(pHead);

	DListErase(DListFind(pHead, 4));
	PrintDlist(pHead);

	DListDestroy(pHead);
}

int main()
{
	Text();
	return 0;
}