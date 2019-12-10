#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define MaxListLength 20

#define SingleList 1

#ifdef SingleList
#define SingleListMode (1)
typedef struct ListNode
{
	int value;
	struct ListNode *pNext;
} ListNode;
#endif

#ifdef DoubleList
#define DoubleListMode (1)
typedef struct ListNode
{
	int value;
	struct ListNode *pNext;
	struct ListNode *pLast;
} ListNode;
#endif

#ifdef LoopList
#define LoopListMode (1)
typedef struct ListNode
{
	int value;
	struct ListNode *pNext;
	struct ListNode *pLast;
} ListNode;
#endif

typedef unsigned int ListState;

int List_GetListNodeCnt(ListNode *pHead);

ListState List_Init(ListNode * pHead, const int value);
ListState List_InsertNode(ListNode *pHead, const int node , const int value);
ListState List_DeleteNode(ListNode *pHead, const int node);
ListState List_DeleteVal (ListNode *pHead, const int value);
ListNode* List_GetValueList (ListNode *pHead, const int value);

#endif


static ListNode ListResult = {0};

/**
  * @name   List_Init.
  * @brief  Creat a list head.
  * @param  ListNode * pHead: Head of the list.
	    int   value: Value of the head.
  * @retval 0               : Succeed.
	    1    	    : There is no stack of head.
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30.
  **/
ListState List_Init(ListNode * pHead, const int value)
{
// 	pHead = (ListNode *)malloc(sizeof(ListNode));
	if (pHead == NULL)
		return 1;
#ifdef SingleListMode
	pHead->pNext = NULL;
	pHead->value = value;
#endif

#ifdef DoubleListMode
	pHead->pNext = NULL;
	pHead->value = value;
	pHead->pLast = NULL;
#endif

#ifdef LoopListMode
	pHead->pNext = pHead;
	pHead->value = value;
	pHead->pLast = pHead;
#endif

	return 0;
}
/**
  * @name   List_NodeCnt.
  * @brief  Get list counters.
  * @param  ListNode * pHead: Head of the list.
  * @retval length      : list counters.
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30.
  **/
static int List_NodeCnt(ListNode *pHead)
{
	ListNode * next = pHead;
	int length = 0;

#ifdef LoopListMode
	while (next->pNext != pHead)
	{	length ++;
		next = next->pNext;
	}
#endif

#ifndef LoopListMode
	while (next->pNext != NULL)
	{	length ++;
		next = next->pNext;
	}
#endif

	return length;

}
int List_GetListNodeCnt(ListNode *pHead)
{
	return (List_NodeCnt(pHead));
}
/**
  * @name   List_InsertNode.
  * @brief  Insert a value at node in list.
  * @param  ListNode * pHead: Head of the list.
	    int   node : The place where you insert the value in the list.
  	    int   value: Value you will insert.
  * @retval 0               : Succeed.
	    1		    : You can't insert value in front of the head.
	    2               : The current list length is langer than MaxListLength.
	    3               : Head of list is NULL
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30
  **/
ListState List_InsertNode(ListNode *pHead, const int node , const int value)
{
	ListNode * curr = (ListNode *)malloc(sizeof(ListNode));
	ListNode * next = pHead;
	int   temp = 0, length = 0;
	if (pHead == NULL)
		return 3;
	length = List_GetListNodeCnt(next);

	if (length > MaxListLength)
		return 2;
	if (node == 0)
		return 1;
	/*	4               : The insert node is beyond current list length.  */
// 	if(node > ListLength)
// 		return 4;
#ifdef SingleListMode

	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == NULL)
			break;
		next = next->pNext;
	}

	curr->pNext = next->pNext;
	curr->value = value;
	next->pNext = curr;
#endif

#ifdef DoubleListMode

	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == NULL)
			break;
		next = next->pNext;
	}

	curr->value = value;
	curr->pLast = next;
	curr->pNext = next->pNext;
	if (next->pNext != NULL)
		next->pNext->pLast = curr;
	next->pNext = curr;
#endif

#ifdef LoopListMode

	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == pHead)
			break;
		next = next->pNext;
	}

	curr->value = value;
	curr->pLast = next;
	curr->pNext = next->pNext;

	next->pNext->pLast = curr;
	next->pNext = curr;

#endif
	return 0;
}

/**
  * @name   List_DeleteNode.
  * @brief  Delete a node in list.
  * @param  ListNode * pHead: Head of the list.
	    int   node : The place where you delete the value in the list.
  * @retval 0               : Succeed.
	    1		    : The delete node is beyond current list length.
	    2               : The current list length is langer than MaxListLength.
	    3		    : The head of the list can't be deleted.
	    4               : Head of list is NULL
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30
  **/
ListState List_DeleteNode(ListNode *pHead, const int node)
{
	ListNode * next = pHead;
	ListNode * curr;
	int temp = 0;
	int length = 0;
	if (pHead == NULL)
		return 4;
	length = List_GetListNodeCnt(next);

	if (length > MaxListLength)
		return 2;
	if (node > length)
		return 1;
	if (node == 0)
		return 3;
#ifdef SingleListMode
	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == NULL)
			break;
		next = next->pNext;
	}
	curr = next->pNext;

	next->pNext = curr->pNext;
	free(curr);

	return 0;
#endif

#ifdef DoubleListMode
	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == NULL)
			break;
		next = next->pNext;
	}
	curr = next->pNext;
	curr->pNext->pLast = next;
	next->pNext = curr->pNext;
	free(curr);

	return 0;
#endif

#ifdef LoopListMode
	for (temp = 0; temp < node - 1; temp++)
	{
		if (next->pNext == pHead)
			break;
		next = next->pNext;
	}
	curr = next->pNext;
	curr->pNext->pLast = next;
	next->pNext = curr->pNext;
	free(curr);

	return 0;
#endif
}
/**
  * @name   List_DeleteVal.
  * @brief  Delete a value list.
  * @param  ListNode * pHead: Head of the list.
	    int   value: The value which you delete in the list.
  * @retval 0               : Succeed.
	    1		    : The delete node is beyond current list length.
	    2               : Head of list is NULL
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30
  **/
ListState List_DeleteVal(ListNode *pHead, const int value)
{
	ListNode *next = pHead;
	int i = 0;
	int temp = 0;
	int length = 0;
	if (pHead == NULL)
		return 2;
	length = List_GetListNodeCnt(next);

	do
	{
		i++;
		next = next->pNext;
		if (next->value == value)
		{
			List_DeleteNode(pHead, i - temp);
			temp ++;
		}
	} while (i < length);

	if (temp == 0)
		return 1;
	return 0;
}
/**
  * @name   List_FindValue.
  * @brief  Delete a value list.
  * @param  ListNode * pHead: Head of the list.
	    int   value: The value which you delete in the list.
  * @retval 0               : Succeed.
	    1		    : The delete node is beyond current list length.
	    2               : Head of list is NULL
	* @author Jiao Wo Yi Sheng Xiao Ming Ge.
	* @Date   2018.5.30
  **/
static ListNode*  List_FindValue (ListNode *pHead, const int value)
{
	ListNode *next = pHead;
	int temp = 0, i = 0;
	int length = GetListNodeCnt(pHead);
	ListInit(&ListResult, 0);

	do
	{
		if (next->value == value)
		{
			temp ++;
			List_InsertNode(&ListResult, temp, i);
		}
		i++;
		next = next->pNext;
	} while (i < length);


	return (&ListResult);
}
ListNode* List_GetValueList(ListNode *pHead, const int value)
{
	return (List_FindValue(pHead, value));
}



