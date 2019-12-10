#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>

typedef struct Node {
	int number;
	char *name;
	struct Node *pNext;
} SNode;

SNode *p_Head = NULL;
SNode *p_End = NULL;


void initList();//链表初始化
void addEnd(int a, char *name); //尾添加
void addHead(int a, char *name);//头添加
void ScanList();
int main()
{
	initList();
	addHead(1, "we");
	addHead(2, "er");
	addHead(3, "er");
	addHead(24, "er");
	addHead(25, "er");
	addHead(26, "er");
	addHead(27, "er");
	ScanList();
	return 0;
}
void ScanList()
{
	struct Node *pTemp = p_Head;
	while (pTemp != NULL)
	{
		printf("(%d --- %s)\t", pTemp->number, pTemp->name); //printf("%s\t",pTemp->a);
		pTemp = pTemp->pNext;

	}
	printf("\n");
}
void addEnd(int a , char *name)//尾添加
{
//创建一个节点
	struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
	pTemp->number = a;
	pTemp->name = name;
	pTemp->pNext = NULL;
//链接
	if (p_Head == NULL) //头、尾节点都为NULL
	{
		p_Head = pTemp;
		p_End = pTemp;
	}
	else
	{
		p_End->pNext = pTemp;
		p_End = pTemp;
	}
}

void addHead (int a, char *name) //头添加
{
//创建一个节点
	struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
	pTemp->number = a;
	pTemp->name = name;
	pTemp->pNext = NULL;
//链接
	// if (p_Head == NULL) //头、尾节点都为NULL
	// {
	// 	p_Head = pTemp;
	// 	p_End = pTemp;
	// }
	// else
	// {
	// 	pTemp->pNext = p_Head;
	// 	p_Head = pTemp;
	// }
	pTemp->pNext = p_Head;
	p_Head = pTemp;
}
void initList() {

	SNode *p_Head = (SNode *)malloc(sizeof(SNode *));
	p_Head->pNext = NULL;
	p_Head = p_End;

}
