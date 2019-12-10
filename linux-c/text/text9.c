#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//节点结构体
typedef struct Node
{
	int a;
	struct Node* pNext;
} node;

node* g_phead = NULL;
node* g_pend = NULL;
//初始化空头链表
void InitList();
//尾添加
void AddListEnd(int a);
//头添加
void AddListHead(int a);
//创建结点并返回
node* CreatNode(int a);
//遍历链表
void ScanList();
//任意位置添加结点
void AddOneNode(int data, int a);
//查找函数
node* FindNode(int a);
//修改指定结点
void ChangeNodeData(int data, int a);
//删除指定数据结点
void DeleteNode(int a);
//遍历清空链表
void FreeList();
//尾删除
void DeleteListTail();
//头删除
void DeleteListHead();

//尾添加结点
void AddListEnd(int a)
{
	//接收创建结点函数创建的节点
	node* new_node = CreatNode(a);

	//接入链表
	g_pend->pNext = new_node;
	g_pend = new_node;

}

//初始化空头链表
void InitList()
{
	//注意，有空头链表的头指针不能变位置
	g_phead = (node*)malloc(sizeof(node));    //创建一个结点，让头指针指向它，即链表的空头,是有实体的，让头指针有明确指向，而无空头的是将第一个结点当成头
	g_phead->pNext = NULL;
	g_pend = g_phead;                       //头尾指针都指向头结点，方便添加
}

void AddListHead(int a)
{
	//接收创建结点函数的指针
	node* new_node = CreatNode(a);

	if (new_node == NULL)
	{
		printf("创建结点失败，内存不足\n");
		return;
	}

	new_node->pNext = g_phead->pNext;
	g_phead->pNext = new_node;

	//头添加尾删除时的特殊：头添加的时候0是尾。。。然后如果一直移动的话尾指针又会到9，不动的话又是一直在头结点，所以只能在0(也就是尾巴的时候)移动一次。。。
	if (a == 0)
	{
		g_pend = new_node;
	}
}

//创建结点并返回该结点
node* CreatNode(int a)
{
	node* new_node = (node*)malloc(sizeof(node));

	if (new_node == NULL)
	{
		printf("内存不足，申请空间失败\n");
		return NULL;
	}

	new_node->a = a;
	new_node->pNext = NULL;

	return new_node;
}

void ScanList()
{
	node* pTemp = g_phead->pNext;     //头结点的下一个才是装数据的结点，所以应该从头结点的下一个结点开始遍历，也就是node* pTemp=g_phead->pNext

	if (pTemp == NULL)
	{
		printf("这是个空链表，别看了\n");
		return;
	}

	while (pTemp != NULL)
	{
		printf("%d-->", pTemp->a);
		pTemp = pTemp->pNext;
	}
	printf("NULL");
	printf("\n");
}

//在指定数据后面添加结点a
void AddOneNode(int data, int a)
{
	if (g_phead->pNext == NULL || g_pend->pNext == NULL)
	{
		printf("链表中无结点, 添加失败\n");
		return;
	}

	node* pFind = FindNode(data);
	//没有找到指定数据
	if (pFind == NULL)
	{
		printf("链表中无该数据，后插入失败");
		return;
	}

	//找到了指定数据
	node* new_node = CreatNode(a);
	//如果添加是添加在最后的话，逻辑稍微不同，直接用尾添加函数即可
	if (pFind == g_pend)
	{
		AddListEnd(a);
	}
	//如果不是尾添加的话，都是一种情况(因为永远不会添加到头结点后面)
	else
	{
		//先连
		new_node->pNext = pFind->pNext;
		//后断
		pFind->pNext = new_node;
	}

}

//查找函数,返回指定结点(的地址)
node* FindNode(int a)
{
	node* pFind = g_phead->pNext;

	while (pFind != NULL)
	{
		if (pFind->a == a)
		{
			return pFind;
		}
		pFind = pFind->pNext;
	}

	return NULL;
}

//将指定结点数据data改为数据a
void ChangeNodeData(int data, int a)
{
	node* new_data = FindNode(data);

	new_data->a = a;
}

//随你删除，不能删除算我输
void DeleteNode(int a)
{
	if (g_phead->pNext == NULL)
	{
		printf("链表为空，删除失败\n");
		return;
	}
	//如果链表不为空，先找到要删除的结点
	node* delete_node = FindNode(a);
	if (delete_node == NULL)
	{
		printf("链表中没有该数据，删除失败\n");
		return;
	}
	//如果要删除的结点是第一个结点（其实我们可以看到，删中间的和删第一个的算法是一样的，因为有个头结点，嘻嘻，所以可以只分为删尾和删其它位置两种算法即可）
	else if (g_pend != delete_node)
	{
		node* pTemp = g_phead;
		//一样，遍历查找要删除结点的前一个结点
		while (pTemp->pNext != delete_node)
		{
			pTemp = pTemp->pNext;
		}

		pTemp->pNext = delete_node->pNext;
		free(delete_node);
	}
	//如果要删除的结点是最后一个结点
	else if (g_pend == delete_node) {
		node* pTemp = g_phead;
		//循环找到尾结点的前一个，这样才能删除尾结点
		while (pTemp->pNext != g_pend)
		{
			pTemp = pTemp->pNext;
		}
		//找到了尾结点的前一个，开删
		g_pend = pTemp;
		pTemp->pNext = NULL;
		free(delete_node);
	}
	//删除中间的(算法合并了，这里放下历史遗迹)
	/*else
	{
		node* pTemp = g_phead;
		//一样，遍历查找要删除结点的前一个结点
		while (pTemp->pNext != delete_node)
		{
			pTemp = pTemp->pNext;
		}

		pTemp->pNext = delete_node->pNext;
		free(delete_node);
	}*/
}
//头删除
void DeleteListHead()
{
	node* pTemp = g_phead->pNext;

	g_phead->pNext = pTemp->pNext;
	free(pTemp);
}
//尾删除
void DeleteListTail()
{
	node* pTemp = g_phead->pNext;


	while (pTemp->pNext != g_pend)
	{
		pTemp = pTemp->pNext;
	}

	free(g_pend);
	g_pend = pTemp;
	pTemp->pNext = NULL;

}

//遍历清空列表
void FreeList()
{
	node* pTemp = g_phead;

	while (pTemp != NULL)
	{
		node* pTemp2 = pTemp;
		pTemp = pTemp->pNext;
		free(pTemp2);
	}

	g_pend = NULL;
	g_phead = NULL;

	printf("清空链表成功，哈哈\n");
}

int main(void)
{
	InitList();

	for (int i = 0; i < 10; i++)
	{
		AddListHead(i);
		AddListEnd(i - 10);
	}
	ScanList();
	DeleteListTail();
	DeleteListTail();
	ScanList();
	DeleteNode(0);
	ChangeNodeData(3, 90);
	ScanList();
	FreeList();
	return 0;
}


