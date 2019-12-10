
#include <stdio.h>
#include <stdlib.h>

//结点结构体
struct Node
{
	int a;
	struct Node * pNext;
};

//链表头尾指针
struct Node * g_pEnd = NULL;//这里的null没有意义，因为在主函数开始会直接给head和end申请地址，成为空头
struct Node * g_pHead = NULL;

void InitListHead();
struct Node * CreatNode(int a);
void AddListTail(int a);
void AddListHead(int a);
void ScanList();



int main()
{
	InitListHead();
	//操作
	//在这里不能头添加删尾，原因不清楚
	//以后熟练之前暂时都使用有空头尾添加
	AddListTail(10);
	AddListTail(20);
	AddListTail(30);
	AddListTail(40);
	DeleteListRand(20);

	ScanList();
	system("Pause");
}


//空头链表初始化
void InitListHead()
{
	//链表空头
	g_pHead = (struct Node *)malloc(sizeof(struct Node)); //此时head是有地址的，成为空头
	g_pHead->pNext = NULL;
	g_pEnd = g_pHead;//刚开始的时候，end地址就是head地址，表示一个空头结点
}

//链表首节点的创建
struct Node * CreatNode(int a)
{
	//创建一个结点
	struct Node *pTemp = (struct Node *)malloc(sizeof(struct Node));
	//结点成员赋值
	pTemp->a = a;
	pTemp->pNext = NULL;
	return pTemp;
}

//尾添加
void AddListTail(int a)
{
	struct Node *pTemp = CreatNode(a);
	//链接
	g_pEnd->pNext = pTemp;
	g_pEnd = pTemp;


}

//头添加
void AddListHead(int a)
{
	struct Node *pTemp = CreatNode(a);

	//链接
	pTemp->pNext = g_pHead->pNext;
	g_pHead->pNext = pTemp;
}

//遍历整个链表
void ScanList()
{
	struct Node *pTemp = g_pHead->pNext; //由于第一个是空头g_pHead，所以遍历的时候直接从g_pHead指向的下一个结点开始遍历
	while (pTemp)
	{
		printf("%d\n", pTemp->a);
		pTemp = pTemp->pNext;
	}
}


//查找指定结点，并且返回结点地址
struct Node * SelectNode(int index)
{
	struct Node *pTemp = g_pHead->pNext; //由于第一个是空头g_pHead，所以遍历的时候直接从g_pHead指向的下一个结点开始遍历
	while (pTemp)
	{
		if (index == pTemp->a)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}

//任意位置添加结点(根据链表中的某个值，在后面添加)
void AddListRank(int index, int a)
{
	//判断链表有没有东西
	if (NULL == g_pHead->pNext)
	{
		printf("链表无节点");
	}
	//找index结点
	struct Node *pTemp = SelectNode(index);
	if (NULL == pTemp)
	{
		printf("查无此结点\n");
	}

	//找到了，连接到指定位置
	struct Node * pNode = CreatNode(a);
	if (pNode == g_pEnd)
	{
		g_pEnd->pNext = pNode;
		g_pEnd = pNode;
	}
	else
	{
		pNode->pNext = pTemp->pNext;
		pTemp->pNext = pNode;

		　　//在这里有瑕疵，如果插入的值不是g_pEnd，可以不修改g_pEnd的值，但是如果插入的值就在g_pEnd，则应该将g_pEnd指针指向pNode

		　/* if (NULL == NewNode->pNext)
    {
        g_pEnd = NewNode;
    }

　*/
	}
}



//struct Node * Find(int index)
//{
//    int cnt = 0;
//    //判断链表有没有东西
//    if (NULL == g_pHead->pNext)
//    {
//        printf("链表无节点");
//    }
//    //找index结点
//    struct Node *pTemp = g_pHead;
//    while(pTemp)
//    {
//        pTemp = pTemp->pNext;
//        if (cnt == index)
//        {
//            return pTemp;
//        }
//        cnt++;
//    }
//}
//
//void AddListNum(int a, int index)
//{
//    struct Node * pNode = CreatNode(a);
//    struct Node * pTemp = Find(index);
//    if (pTemp == g_pEnd)
//    {
//        g_pEnd->pNext = pNode;
//        g_pEnd = pNode;
//    }
//    else
//    {
//        pNode->pNext = pTemp->pNext;
//        pTemp->pNext = pNode;
//    }
//}

//删头
void DeleteListHead()
{
	//判断链表有没有东西
	if (NULL == g_pHead->pNext)
	{
		printf("链表无头");
		return;
	}
	struct Node * pTemp = g_pHead->pNext;
	//变头
	g_pHead->pNext = g_pHead->pNext->pNext;
	//释放
	free(pTemp);
}

//删尾
void DeleteListTail()
{
	//判断链表有没有东西
	if (g_pHead->pNext == NULL)
	{
		printf("链表无尾");
		return;
	}

	　　//这里用了多个if 和一个else可能会造成混乱，建议if else 在else下再if else，确保正确
	//有一个结点
	if (g_pHead->pNext == g_pEnd)
	{
		free(g_pEnd);
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
	}

	else
	{
		//找到尾结点的下一个
		struct Node *pTemp = g_pHead->pNext; //由于第一个是空头g_pHead，所以遍历的时候直接从g_pHead指向的下一个结点开始遍历
		while (pTemp)
		{
			if (g_pEnd == pTemp->pNext)
			{
				break;
			}
			pTemp = pTemp->pNext;
		}
		//pTemp是尾巴的前一个
		free(g_pEnd);
		//变新尾巴
		g_pEnd = pTemp;
		//尾巴下一个赋值空
		g_pEnd->pNext = NULL;

	}
}
//删指定结点
void DeleteListRand(int a)
{
	//判断链表有没有东西
	if (NULL == g_pHead->pNext)
	{
		printf("链表无节点");
	}
	//找index结点
	struct Node *pTemp = SelectNode(a);
	if (NULL == pTemp)
	{
		printf("查无此结点\n");
	}
	//找到结点
	//头，尾和中间
	//找到前一个结点
	//只有一个结点
	if (pTemp == g_pEnd)
	{
		DeleteListTail();
	}
	else
	{
		struct Node *pT = g_pHead;
		while (pT)
		{
			if (pTemp == pT->pNext)
			{
				break;
			}
			pT = pT->pNext;
		}
		//删除
		pT->pNext = pTemp->pNext;
		//释放
		free(pTemp);
	}

}


//释放链表
void FreeList()
{
	struct Node * pTemp = g_pHead;
	while (pTemp != NULL)
	{
		struct Node *pT = pTemp;
		pTemp = pTemp->pNext;
		free(pT);
	}
	g_pHead = NULL;
	g_pEnd = NULL;
}


//对链表进行排序

void SortList()
{


	int i, j, t;
	struct Node * p = g_pHead->pNext;
	struct Node * q = p->pNext;
	while (p != NULL)
	{
		while (q != NULL)
		{
			if (p->a > q->a)
			{
				t = p->a;
				p->a = q->a;
				q->a = t;
			}
			q = q->pNext;
		}
		p = p->pNext;
		q = p; //关键，如果不加则q为NULL,如果q = p->pNext，则当q指向NULL时，p指向NULL指向的下一个，程序崩溃
	}
}

// 删除的思路都是：

// 　　先找到删除的结点的前一个结点，然后设pT = 删除的结点，前一个结点的指向地址变为删除结点指向的地址，free掉pT



//         特殊情况考虑：

//         　　删头：考虑找不到结点情况；　　考虑空链表 g_pHead->pNext == NULL；　  不用考虑一个结点的情况！！（因为直接free）；　　其余

//         　　删尾：考虑找不到结点情况；　　考虑空链表 g_pHead->pNext == NULL；　　考虑只有一个结点 g_pHead->pNext == g_pEnd; （因为找不到那个结点前面的值）；　　其余

// 　　删指定：考虑找不到结点情况；　　考虑空链表 g_pHead->pNext == NULL; 　　考虑只有一个结点 g_pHead->pNext == g_pEnd; （因为找不到那个结点前面的值）；　　其余