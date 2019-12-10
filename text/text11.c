#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Elment
{
	int id;
	char* name;
} Data;

typedef struct Node
{
	Data data;
	struct Node* prior;     //指向前驱
	struct Node* next;      //指向后继
} Node;

Node* g_phead = NULL;
Node* g_ptail = NULL;
int length;

void InitList();
void InsertTail(Node* DuLinkList, Data* data);
void PrintList(Node* DuLikList);
void DeleNode(Node* DuLinkList, int pos);
void  InsertHead(Node* DuLinkList, Data* data);


void InitList()
{
	//初始化头结点
	g_phead = (Node*)malloc(sizeof(Node));
	g_phead->next = NULL;
	g_phead->prior = NULL;
	g_ptail = g_phead;
}

//头插法
void  InsertHead(Node* DuLinkList, Data* data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	//链表为空时
	if (g_phead->next == NULL)
	{
		g_phead->next = new_node;
		new_node->prior = g_phead;
		//只需要一开始只有一个结点时，这个结点指向自己就可以形成循环了
		new_node->next = g_phead;
		g_phead->prior = new_node;
	}
	else
	{
		new_node->next = g_phead->next;
		g_phead->next = new_node;
	}
}

//尾插法
void InsertTail(Node* DuLinkList, Data* data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	//链表为空时
	if (g_phead->next == NULL)
	{
		g_phead->next = new_node;
		new_node->prior = g_phead;
		//只需要一开始只有一个结点时，这个结点指向自己就可以形成循环了
		new_node->next = g_phead;
		g_phead->prior = new_node;
	}
	else
	{
		g_ptail->next = new_node;
		g_ptail = new_node;
	}
}

void InsertNode(Node* DuLinkList, int pos, Data* data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = *data;
	new_node->next = NULL;
	new_node->prior = NULL;

	//如果链表为空
	if (g_phead->next == NULL)
	{
		g_phead->next = new_node;
		new_node->prior = g_phead;
		//只需要一开始只有一个结点时，这个结点指向自己就可以形成循环了
		new_node->next = g_phead;
		g_phead->prior = new_node;
	}
	else
	{
		//找到要插入位置的前置结点
		Node* pTemp = g_phead;
		for (int i = 0; i < pos - 1; i++)
		{
			pTemp = pTemp->next;
		}
		//如果要插在尾部
		if (pTemp->next == NULL)
		{
			new_node->prior = pTemp;
			pTemp->next = new_node;

		}
		//如果插在中间或者第一
		else
		{
			//先连
			new_node->prior = pTemp;
			new_node->next = pTemp->next;
			//后断
			pTemp->next->prior = new_node;
			pTemp->next = new_node;
		}
	}
	//移动尾指针

	length++;
}

void DeleNode(Node* DuLinkList, int pos)
{
	Node* pTemp = g_phead->next;
	Node* pFree = g_phead->next;

	if (pos > length)
	{
		printf("删除位置错误，删除失败\n");
		return;
	}

	//找到要删除的结点
	for (int i = 0; i < pos - 1; i++)
	{
		pFree = pFree->next;
	}

	//双向循环链表的删除分为删除尾结点和删除其它结点两种情况
	if (pFree->next == g_phead->next)
	{
		pFree->prior->next = g_phead;
		g_phead->prior = pFree->prior;
	}
	else
	{
		//要删除结点的前驱的next直接指向要删除结点的后继
		pFree->prior->next = pFree->next;
	}

	free(pFree);
	length--;
}

void PrintList(Node* DuLikList)
{
	Node* pTemp = g_phead->next;
	int i = 0;
	while (i < length)
	{
		printf("%d  %s-->  \t", pTemp->data.id, pTemp->data.name);
		pTemp = pTemp->next;
		i++;
	}

	printf("\n");
}

int main(void)
{
	Data da1;
	da1.id = 1;
	da1.name = "sdfgjhl";
	Data da2;
	da2.id = 2;
	da2.name = "thout";

	InitList();

	InsertNode(g_phead, 1, &da1);
	InsertNode(g_phead, 2, &da1);
	InsertNode(g_phead, 2, &da2);
	InsertNode(g_phead, 1, &da2);

	PrintList(g_phead);

	DeleNode(g_phead, 4);

	PrintList(g_phead);
	InsertHead(g_phead, );


	return 0;
}
