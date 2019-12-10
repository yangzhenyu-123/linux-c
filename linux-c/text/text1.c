#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
#define N 4
struct Node {
    int  a;
    char *name;
    struct Node *pNext;
};

struct Node *g_pHead = NULL;//创建头指针
struct Node *g_pEnd = NULL;//创建尾指针

void AddListEnd(int a , char *name);//尾添加
void AddListHead(int a , char *name);//头添加
void ScanList();//遍历
struct Node *SleectList(int a);//查找
void FreeList();//释放
void AddListAppoint(int dex , int a, char *name);//插入
void deleteListHead();//头删除
void deleteListEnd();//尾删除
void deleteListAppoint(int a);//删除指定任意节点
int main()
{
    char *name[N];//指针数组 存的是地址
    //int *number[12];
    for (int i = 0; i < N; i++)
    {
        name[i] =  (char*)malloc(sizeof(char));//申请空间
        // number[i] = (int *)malloc(sizeof(int));
        printf("%s\n", "input name:" );
        scanf("%s", name[i]);
        // printf("%s\n", "input number: ");
        // scanf("%d", number[i]);
    }
    //初始化链表（1，2，3，4）
    for (int i = 0; i < N; i++)
    {
        AddListEnd(i, *(name + i));
        AddListHead(i, *(name + i));
    }
    ScanList();
    struct Node *find = SleectList(2);

    if (find != NULL)
    {
        printf("已经找到数据：%d\t%s\n", find->a, find->name);
    }
    else
    {
        printf("没有这个数据！\n");
    }
    AddListAppoint(1, 4, "SBSBSB");
    ScanList();
    deleteListAppoint(2);
    ScanList();
    FreeList();
    return 0;
}

void AddListEnd(int a , char *name)//尾添加
{
//创建一个节点
    struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
    pTemp->a = a;
    pTemp->name = name;
    pTemp->pNext = NULL;
//链接
    if (g_pHead == NULL) //头、尾节点都为NULL
    {
        g_pHead = pTemp;
        g_pEnd = pTemp;
    }
    else
    {
        g_pEnd->pNext = pTemp;
        g_pEnd = pTemp;
    }
}

void AddListHead (int a, char *name) //头添加
{
//创建一个节点
    struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
    pTemp->a = a;
    pTemp->name = name;
    pTemp->pNext = NULL;
//链接
    if (g_pHead == NULL) //头、尾节点都为NULL
    {
        g_pHead = pTemp;
        g_pEnd = pTemp;
    }
    else
    {
        pTemp->pNext = g_pHead;
        g_pHead = pTemp;
    }
}

//遍历链表
void ScanList()
{
    struct Node *pTemp = g_pHead;
    while (pTemp != NULL)
    {
        printf("(%d --- %s)\t", pTemp->a, pTemp->name); //printf("%s\t",pTemp->a);
        pTemp = pTemp->pNext;

    }
    printf("\n");
}
struct Node *SleectList(int a)//查询指定节点
{
    struct Node *pTemp = g_pHead;
    while (pTemp != NULL)
    {
        if (a == pTemp->a)
        {
            return pTemp;
        }
        pTemp = pTemp->pNext;

    }
    return NULL;
}

void FreeList()
{
    struct Node *pTemp = g_pHead;
    while (pTemp != NULL)
    {
        struct Node *pt = pTemp;
        pTemp = pTemp->pNext;
        free(pt);

    }
    //释放链表一定要头尾清
    g_pHead = NULL;
    g_pEnd = NULL;
}

void AddListAppoint(int dex, int a, char *name)
{
    if (g_pHead == NULL)
    {
        printf("该链表为空！\n" );
        return;
    }
    struct Node *pt = SleectList(dex);

    if (pt == NULL)
    {
        printf("没有指定结点！\n");
        return;
    }

    struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
    //赋值
    pTemp->a = a;
    pTemp->name = name;
    pTemp-> pNext = NULL;
    //链接
    if (pt == g_pEnd)
    {
        g_pEnd->pNext = pTemp;
        g_pEnd = pTemp;
    }
    else
    {
        pTemp->pNext = pt->pNext;
        pt->pNext = pTemp;
    }
}

void deleteListHead()
{
    struct Node *pTemp = g_pHead;

    if (NULL == g_pHead)
    {
        printf("无需释放！\n");
        return;
    }
    else
        g_pHead = g_pHead->pNext;
    free(pTemp);
}

void deleteListEnd()
{


    if (NULL == g_pHead)
    {
        printf("无需释放！\n");
        return;
    }
    //只有一个结点
    if (g_pHead == g_pEnd)
    {
        free(g_pEnd);
        g_pEnd = NULL;
        g_pHead = NULL;
    }
    else
    {
        struct Node *pTemp = g_pHead;
        //找到尾巴前一个节点
        while (pTemp->pNext != g_pEnd)
        {
            pTemp = pTemp->pNext;
        }
        //找到后 释放尾结点
        free(g_pEnd);
        //尾巴前移
        g_pEnd = pTemp;

        g_pEnd->pNext = NULL;
    }


}
void deleteListAppoint(int a)//
{

    if (NULL == g_pHead)
    {
        printf("无需释放！\n");
        return;
    }

    struct Node *pTemp = SleectList(a);
    if (NULL == pTemp)
    {
        printf("没有这个节点！\n");
        return;
    }

    if (g_pEnd == g_pHead)//只有一个节点
    {
        deleteListHead();
    }
    else if (g_pHead->pNext == g_pEnd) //有两个节点
    {
        if (g_pEnd == pTemp)
        {
            deleteListEnd();
        }
        else
            deleteListHead();
    }
    else//有多个节点
    {
        if (g_pEnd == pTemp)
        {
            deleteListEnd();
        }
        else if (g_pHead == pTemp)
        {
            deleteListHead();
        }
        else
        {
            struct Node *pt = g_pHead;
            while (pt->pNext != pTemp  )
            {
                pt = pt->pNext;
            }
            //找到后 将pt的next 指向找到的ptemp的next
            pt->pNext = pTemp->pNext;
        }
        printf("已删除%d\n", a );
    }
    free(pTemp);

}