#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define LINK 1
#ifdef LINK

typedef int data_t;
typedef struct DoubleListNode
{
	struct DoubleListNode *pFront;
	data_t data;
	struct DoubleListNode *pAfter;
} DoubleListNode;


//初始化一个空头节点
void DoubleListInit(DoubleListNode *&pHead);
//创建一个新节点
DoubleListNode *DoubleListNewNode(data_t data);
//尾插法
void DoubleListTailInsert(DoubleListNode *pHead, data_t data);
//头插法
void DoubleListHeadInsert(DoubleListNode *pHead, data_t data);
//头删除
void DoubleListHeadDelete(DoubleListNode *pHead);
//尾删除
void DoubleListTailDelete(DoubleListNode *pHead);
//查找某个节点
DoubleListNode *DoubleListFind(DoubleListNode *pHead, data_t data);
//任意位置节点前插入
void DoubleListInsertOfHead(DoubleListNode *pHead, data_t data_pos, data_t data);

//任意位置节点删除
void DoubleListDelete(DoubleListNode *pHead, data_t data_pos);
//链表释放销毁
void DoubleListDestory(DoubleListNode* &pHead);
//链表打印
void DoubleListPrintf(DoubleListNode *pHead);
//链表数目
int DoubleListNumber(DoubleListNode *pHead);

#endif

void DoubleListInit(DoubleListNode *&pHead)//Dou.. *(*p) dou.. &p =* 用g++编译
{

	assert(pHead);
	pHead = new(DoubleListNode);//(DoubleListNode *)malloc(sizeof(DoubleListNode));//前者为C++函数
	pHead->pFront = pHead;
	pHead->data = 0;
	pHead->pAfter = pHead;
	printf("....wait a minute...\n");
	printf("链表初始化成功\n");

}

DoubleListNode *DoubleListNewNode(data_t data)
{
	DoubleListNode *NewNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));
	if (NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->pFront = NULL;
	NewNode->data = data;
	NewNode->pAfter = NULL;
	return NewNode;
}

void DoubleListTailInsert(DoubleListNode *pHead, data_t data)
{
	DoubleListNode *NewNode = DoubleListNewNode(data);
	if (pHead->pAfter == pHead) //当链表为空
	{
		pHead->pAfter = NewNode;
		NewNode->pFront = pHead;
		NewNode->pAfter = pHead;
		pHead->pFront = NewNode;
	}
	else//当链表不为空
	{
		DoubleListNode *pEnd = pHead->pFront;//找到最后一个节点
		pEnd->pAfter = NewNode;
		NewNode->pFront = pEnd;
		pHead->pFront = NewNode;
		NewNode->pAfter = pHead;
	}

}

void DoubleListHeadInsert(DoubleListNode *pHead, data_t data)
{
	assert(pHead);
	DoubleListNode *pTemp = pHead;
	DoubleListNode *NewNode = DoubleListNewNode(data);
	if (pTemp->pFront == pHead)
	{
		NewNode->pFront = pTemp;
		NewNode->pAfter = pTemp;
		pTemp->pFront = NewNode;
		pTemp->pAfter = NewNode;
		NewNode->data = data;
	}
	else
	{
		NewNode->pAfter = pTemp->pAfter;
		NewNode->pFront = pTemp;
		pTemp->pAfter = NewNode;
		pTemp->pAfter->pFront = NewNode;
		NewNode->data = data;
	}
}

void DoubleListHeadDelete(DoubleListNode *pHead)
{
	DoubleListNode *pTemp = pHead;
	pTemp->pAfter->pAfter->pFront = pTemp;
	pTemp->pAfter = pTemp->pAfter->pAfter;
}

void DoubleListTailDelete(DoubleListNode *pHead)
{
	DoubleListNode *pTemp = pHead;
	pTemp->pFront->pFront->pAfter = pTemp;
	pTemp->pFront = pTemp->pFront->pFront;
}

DoubleListNode *DoubleListFind(DoubleListNode *pHead, data_t data)
{

	DoubleListNode *pTemp = pHead;
	while (pTemp->pAfter != pHead)
	{

		if (pTemp->data == data)
		{
			printf("已找到%d这个节点!\n", data);
			return pTemp;
		}
		pTemp = pTemp->pAfter;
	}
	printf("链表无此节点!---返回链表头指针！\n");
	return pHead;
}

void DoubleListInsertOfHead(DoubleListNode *pHead, data_t data_pos, data_t data)
{
	DoubleListNode *pTemp = DoubleListFind(pHead, data_pos);
	if (pTemp == NULL)
	{
		printf("....wait a minute...\n");
		printf("插入失败！\n");
	}
	else if (pTemp == pTemp->pAfter)
	{
		DoubleListHeadInsert(pHead, data);
		printf("....wait a minute...\n");
		printf("链表为NULL！头插成功\n");
		return;
	}
	else
	{
		DoubleListNode *NewNode = DoubleListNewNode(data);
		pTemp->pFront->pAfter = NewNode;
		NewNode->pFront = pTemp->pFront;
		NewNode->pAfter = pTemp;
		pTemp->pFront = NewNode;
		printf("....wait a minute...\n");
		printf("已经在%d前插入%d\n", data_pos, data);
	}
}

void DoubleListDelete(DoubleListNode *pHead, data_t data_pos)
{
	DoubleListNode *pT = DoubleListFind(pHead, data_pos);
	if (pT == NULL)
	{
		printf("Fail Delete!\n");
		return;
	}
	else if (pT == pHead)
	{
		printf("Fail Delete!\n");

		return;
	}
	else
	{
		pT->pAfter->pFront = pT->pFront;
		pT->pFront->pAfter = pT->pAfter;
		printf("....wait a minute...\n");
		printf("已经成功删除%d\n", data_pos);
	}

}

void DoubleListPrintf(DoubleListNode *pHead)
{
	assert(pHead);
	DoubleListNode *pT = pHead;
	if (pT->pAfter == pHead)
	{
		printf("Warning:The List Is NULL!\n");
		return;

	}
	else
	{
		printf("....wait a minute...\n");
		while (pHead != pT->pAfter)
		{
			printf("%d-->", pT->data );
			pT = pT->pAfter;
		}
		printf("%d-->%d\n", pT->data, pHead->data);
	}
	printf("链表打印成功！\n");
}

int DoubleListNumber(DoubleListNode *pHead)
{
	DoubleListNode *pT = pHead;
	int i = 0;
	while (pHead != pT->pAfter)
	{
		i++;
		pT = pT->pAfter;
	}
	printf("list's data number is %d\n", i);
	return i;
}

void DoubleListDestory(DoubleListNode *&pHead)
{
	assert(pHead);
	DoubleListNode *pTemp = pHead;
	DoubleListNode *pT = NULL;
	if (pTemp->pAfter == pHead)
	{
		printf("链表为NULL！\n");
		return;
	}
	else
	{
		pHead->pAfter = pTemp;
		pHead->pFront = pTemp;
		free(pTemp);
		pTemp = pT;
	}
	free(pHead);
}

int main(int argc, char const *argv[])
{
	DoubleListNode *pHead;
	int i = 0;
	DoubleListInit(pHead);
	DoubleListPrintf(pHead);
	DoubleListTailInsert(pHead, 1);
	DoubleListTailInsert(pHead, 2);
	DoubleListTailInsert(pHead, 3);
	DoubleListTailInsert(pHead, 4);
	DoubleListTailInsert(pHead, 5);
	DoubleListTailInsert(pHead, 6);
	i = DoubleListNumber(pHead);
	DoubleListPrintf(pHead);
	DoubleListHeadInsert(pHead, 2);
	DoubleListHeadInsert(pHead, 1);
	DoubleListHeadInsert(pHead, 15);
	i = DoubleListNumber(pHead);
	DoubleListPrintf(pHead);
	DoubleListHeadDelete(pHead);
	DoubleListPrintf(pHead);
	DoubleListTailDelete(pHead);
	DoubleListPrintf(pHead);
	DoubleListHeadDelete(pHead);
	DoubleListPrintf(pHead);
	DoubleListInsertOfHead(pHead, 4, 36);
	DoubleListInsertOfHead(pHead, 36, 38);
	i = DoubleListNumber(pHead);
	DoubleListPrintf(pHead);
	DoubleListDelete(pHead, 36);
	DoubleListPrintf(pHead);
	DoubleListDestory(pHead);
	DoubleListPrintf(pHead);


	return 0;
}