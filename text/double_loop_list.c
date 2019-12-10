//Dlist.h
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define double_1 1

#ifdef double_1

typedef int DataType;
typedef struct DListNode
{
	struct DListNode* _pPre;
	DataType _data;
	struct DListNode* _pNext;
} DListNode;

void test();
// 初始化
void DListInit(DListNode** pHead);
// 双向链表的尾插
void DListPushBack(DListNode* pHead, DataType data);
// 双向链表的尾删
void DListPopBack(DListNode* pHead);
// 双向链表的头插
void DListPushFront(DListNode* pHead, DataType data);
// 双向链表的头删
void DListPopFront(DListNode* pHead);
// 任意位置插入
void DListInsert(DListNode* pos, DataType data);
// 任意位置删除
void DListErase(DListNode* pos);
// 查找值为data的结点
DListNode* DListFind(DListNode* pHead, DataType data);
//创建新节点
DListNode* NewNode(DataType d);
// 销毁
void DListDestroy(DListNode** pHead);
//打印
void PrintDlist(DListNode* pHead);
//Dlist.c
#endif
// 初始化
#ifdef double_1

void DListInit(DListNode** pHead)
{
	assert(pHead);
	(*pHead) = (DListNode*)malloc(sizeof(DListNode));
	(*pHead)->_pNext = (*pHead);
	(*pHead)->_pPre = (*pHead);
	(*pHead)->_data = 0;
}

DListNode* NewNode(DataType d)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->_data = d;
	newNode->_pNext = NULL;

	newNode->_pPre = NULL;
	return newNode;
}
// 双向链表的尾插
void DListPushBack(DListNode* pHead, DataType data)
{
	DListNode* newNode = NewNode(data);
	DListNode* tail = pHead;
	while (pHead != tail->_pNext)
	{
		tail = tail->_pNext;
	}
	tail->_pNext = newNode;
	newNode->_pNext = pHead;

	pHead->_pPre = newNode;
	newNode->_pPre = tail;
}
// 双向链表的尾删
void DListPopBack(DListNode * pHead)
{
	DListNode* tail = pHead;
	if (pHead == pHead->_pNext)
		return;
	while (pHead != tail->_pNext)
	{
		tail = tail->_pNext;
	}
	tail->_pNext = NULL;
	tail->_pPre->_pNext = pHead;
	tail->_pPre = NULL;
	free(tail);
	tail = NULL;
}
// 双向链表的头插
void DListPushFront(DListNode * pHead, DataType data)
{
	DListNode* newNode = NewNode(data);
	pHead->_pNext->_pPre = newNode;
	newNode->_pNext = pHead->_pNext;
	pHead->_pNext = newNode;
	newNode->_pPre = pHead;
}
// 双向链表的头删
void DListPopFront(DListNode * pHead)
{
	DListNode* temp = NULL;
	if (pHead == pHead->_pNext)
		return;
	temp = pHead->_pNext;
	pHead->_pNext->_pPre = NULL;
	pHead->_pNext = pHead->_pNext->_pNext;
	pHead->_pNext->_pPre->_pNext = NULL;
	pHead->_pNext->_pPre = pHead;
	free(temp);
	temp = NULL;
}
// 任意位置前插入
void DListInsert(DListNode * pos, DataType data)
{
	if (pos == pos->_pNext)
	{
		DListPushFront(pos, data);
		return;
	}
	DListNode* newNode = NewNode(data);
	pos->_pPre->_pNext = newNode;
	newNode->_pPre = pos->_pPre;
	newNode->_pNext = pos;
	pos->_pPre = newNode;
}
// 任意位置删除
void DListErase(DListNode * pos)
{
	if (pos == pos->_pNext)
		return;
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	pos->_pPre = NULL;
	pos->_pNext = NULL;
	free(pos);
	pos == NULL;
}
// 查找值为data的结点
DListNode* DListFind(DListNode * pHead, DataType data)
{
	DListNode* cur = pHead;
	while (pHead != cur->_pNext)
	{
		if (data == cur->_data)
			return cur;
		cur = cur->_pNext;
	}
	return NULL;
}
// 销毁
void DListDestroy(DListNode** pHead)
{
	assert(pHead);
	DListNode* cur1 = (*pHead)->_pNext;
	DListNode* cur2 = NULL;
	while ((*pHead) != cur1)
	{
		cur2 = cur1->_pNext;
		free(cur1);
		cur1 = cur2;
	}
	free((*pHead));
	(*pHead) = NULL;
}
//打印
void PrintDlist(DListNode * pHead)
{
	DListNode* cur = pHead;
	if (NULL == pHead)
	{
		printf("NULL\n");
		return;
	}
	while (pHead != cur->_pNext)
	{
		printf("%d-->", cur->_data);
		cur = cur->_pNext;
	}
	printf("%d-->%d\n", cur->_data, pHead->_data);
}
//test.c
void test()
{
	DListNode* pHead;
	// 初始化
	DListInit(&pHead);
	PrintDlist(pHead);
	// 双向链表的尾插
	DListPushBack(pHead, 6);
	DListPushBack(pHead, 7);
	DListPushBack(pHead, 8);
	DListPushBack(pHead, 9);
	DListPushBack(pHead, 10);
	PrintDlist(pHead);
	// 双向链表的尾删
	DListPopBack(pHead);
	PrintDlist(pHead);
	// 双向链表的头插
	DListPushFront(pHead, 4);
	DListPushFront(pHead, 3);
	DListPushFront(pHead, 2);
	DListPushFront(pHead, 1);
	DListPushFront(pHead, 1);
	PrintDlist(pHead);
	// 双向链表的头删
	DListPopFront(pHead);
	PrintDlist(pHead);
	// 查找值为6的结点
	DListNode* pos = DListFind(pHead, 6);
	// pos位置前插入
	DListInsert(pos, 5);
	PrintDlist(pHead);
	// 查找值为7的结点
	pos = DListFind(pHead, 7);
	// 任意位置删除
	DListErase(pos);
	PrintDlist(pHead);
	// 销毁
	DListDestroy(&pHead);
	PrintDlist(pHead);
}
#endif

int main()
{
	test();
	//system("pause");
	return 0;
}

// #ifdef double_2
// typedef int CLDataType;
// //结点类型
// typedef struct ListNode
// {
// 	CLDataType _data;
// 	struct ListNode* _next;
// 	struct ListNode* _prev;
// } ListNode;
// //链表的头
// typedef struct List
// {
// 	ListNode* _head;
// } List;
// void test();
// //创建一个双向循环链表结点
// ListNode* BuyListNode(CLDataType x);
// //初始化双向循环带头链表
// void ListInit(List* pcl);
// //销毁双向循环带头链表
// void ListDestory(List* pcl);
// //尾插
// void ListPushBack(List* pcl, CLDataType x);
// //头插
// void ListPushFront(List* pcl, CLDataType x);
// //指定位置插入结点
// void ListInsert(ListNode* pos, CLDataType x);
// //尾删
// void ListPopBack(List* pcl);
// //头删
// void ListPopFront(List* pcl);
// //指定位置删除(不能是头结点)
// void ListErase(List* pcl, ListNode* pos);
// //遍历打印链表
// void ListPrint(List* pcl);
// //链表的长度
// int ListSize(List* pcl);
// //判断链表是否为空(为空返回0，非空返回1)
// int ListEmpty(List* pcl);
// //寻找指定数据的结点(找到返回地址，找不到返回NULL)
// ListNode* FindListNode(List* pcl, CLDataType x);
// #endif



// #ifdef double_2
// //创建一个双向循环链表结点
// ListNode* BuyListNode(CLDataType x)
// {
// 	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
// 	if (cur == NULL)
// 	{
// 		perror("use malloc");
// 		exit(1);
// 	}
// 	cur->_data = x;
// 	cur->_next = NULL;
// 	cur->_prev = NULL;
// 	return cur;
// }
// //初始化双向循环带头链表
// void ListInit(List* pcl)
// {
// 	assert(pcl);
// 	ListNode* head = BuyListNode(0);
// 	pcl->_head = head;
// 	pcl->_head->_next = pcl->_head;
// 	pcl->_head->_prev = pcl->_head;
// }
// //销毁双向循环带头链表
// void ListDestory(List* pcl)
// {
// 	assert(pcl);
// 	ListNode* cur = pcl->_head->_next;
// 	while (cur != pcl->_head)
// 	{
// 		ListNode* tmp = cur->_next;
// 		free(cur);
// 		cur = tmp;
// 	}
// 	free(pcl->_head);
// 	pcl->_head = NULL;
// }
// //尾插
// void ListPushBack(List* pcl, CLDataType x)
// {
// 	assert(pcl);
// 	//尾插和在头结点前面插入一个结点一样
// 	ListInsert(pcl->_head, x);
// }
// //头插
// void ListPushFront(List* pcl, CLDataType x)
// {
// 	assert(pcl);
// 	//头插和在第一个结点前面插入一样
// 	ListInsert(pcl->_head->_next, x);
// }
// //指定位置前面插入结点
// void ListInsert(ListNode* pos, CLDataType x)
// {
// 	assert(pos);
// 	ListNode* newnode = BuyListNode(x);
// 	//保存前面结点(建议这么写，如果直接用指针完会太绕了)
// 	ListNode* prev = pos->_prev;
// 	//prev-newnode-pos指针连接起来
// 	prev->_next = newnode;
// 	newnode->_prev = prev;
// 	newnode->_next = pos;
// 	pos->_prev = newnode;
// }
// //尾删
// void ListPopBack(List* pcl)
// {
// 	assert(pcl);
// 	//尾删和在删除指定最后一个结点一样
// 	ListErase(pcl, pcl->_head->_prev);
// }
// //头删
// void ListPopFront(List* pcl)
// {
// 	assert(pcl);
// 	//头删和删除指定第一个结点一样
// 	ListErase(pcl, pcl->_head->_next);
// }
// //指定位置删除结点
// void ListErase(List* pcl, ListNode* pos)
// {
// 	assert(pos);
// 	//删除的结点不能是头结点
// 	assert(pos != pcl->_head);
// 	//保存pos前面结点
// 	ListNode* prev = pos->_prev;
// 	//保存pos后面结点
// 	ListNode* next = pos->_next;
// 	//prev pos next(pos为删除结点)
// 	prev->_next = next;
// 	next->_prev = prev;
// 	free(pos);
// 	pos = NULL;
// }
// //遍历打印链表
// void ListPrint(List* pcl)
// {
// 	assert(pcl);
// 	ListNode* cur = pcl->_head->_next;
// 	//从头结点的下一个结点开始遍历
// 	while (cur != pcl->_head)
// 	{
// 		printf("%d-->", cur->_data);
// 		cur = cur->_next;
// 	}
// 	printf("over\n");
// }
// //链表的长度
// int ListSize(List* pcl)
// {
// 	assert(pcl);
// 	ListNode* cur = pcl->_head->_next;
// 	int count = 0;
// 	//遍历一遍链表(不算头结点)
// 	while (cur != pcl->_head)
// 	{
// 		count++;
// 		cur = cur->_next;
// 	}
// 	return count;
// }
// //判断链表是否为空(为空返回0，非空返回1)
// int ListEmpty(List* pcl)
// {
// 	assert(pcl);
// 	//prev和next如果都指向自己，则链表为空
// 	return ((pcl->_head->_next == pcl->_head) && (pcl->_head->_prev == pcl->_head)) ? 0 : 1;
// }
// //寻找指定数据的结点(找到返回地址，找不到返回NULL)
// ListNode* FindListNode(List* pcl, CLDataType x)
// {
// 	assert(pcl);
// 	ListNode* cur = pcl->_head->_next;
// 	//遍历链表找到相同数据返回地址，找不到则返NULL
// 	while (cur != pcl->_head)
// 	{
// 		if (cur->_data == x)
// 		{
// 			return cur;
// 		}
// 		cur = cur->_next;
// 	}
// 	return NULL;
// }
// void test()
// {
// 	List* pHead;
// 	ListInit(pHead);
// //销毁双向循环带头链表
// //尾插
// 	ListPushBack(pHead, 1);
// 	ListPushBack(pHead, 2);
// 	ListPushBack(pHead, 3);
// 	ListPushBack(pHead, 4);
// 	ListPushBack(pHead, 5);
// //头插
// 	ListPrint(pHead);
// 	ListPushFront(pHead, 1);
// 	ListPushFront(pHead, 6);
// 	ListPushFront(pHead, 3);
// 	ListPushFront(pHead, 4);
// 	ListPushFront(pHead, 5);
// 	ListPrint(pHead);
// //指定位置插入结点
// 	//ListInsert(FindListNode(pHead, 6), 8);
// 	//ListPrint(pHead);
// //尾删
// 	ListPopBack(pHead);
// 	ListPrint(pHead);
// //头删
// 	ListPopFront(pHead);
// 	ListPrint(pHead);
// //指定位置删除(不能是头结点)
// 	ListErase(pHead, FindListNode(pHead, 5));
// //遍历打印链表
// 	ListPrint(pHead);
// 	ListDestory(pHead);
// }
// #endif
