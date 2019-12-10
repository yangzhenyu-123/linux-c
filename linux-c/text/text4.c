#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
#define N 3
struct Node {
    char  *number;
    char *name;
    struct Node *pNext;
};

struct Node *g_pHead = NULL;//创建头指针
struct Node *g_pEnd = NULL;//创建尾指针

void AddListEnd(char *number , char *name);//尾添加
void AddListHead(char *number , char *name);//头添加
void ScanList();//遍历
struct Node *SleectList(char *a);//查找
void FreeList();//释放
void AddListAppoint(char *dex , char *number, char *name);
int main()
{
    char *name[12];//指针数组 存的是地址
    char *number[12];
    for (int i = 0; i < N; i++)
    {
        name[i] =  (char*)malloc(sizeof(char));//申请空间
        number[i] = (char *)malloc(sizeof(char));
        printf("%s\n", "input name:" );
        scanf("%s", name[i]);
        printf("%s\n", "input number: ");
        scanf("%s", number[i]);
    }
    //初始化链表（1，2，3，4）
    for (int i = 0; i < N; i++)
    {
        AddListHead(*(number + i), *(name + i));
        //AddListEnd(i);
    }
    ScanList();
    struct Node *find = SleectList("No.2");
    if (find != NULL)
    {
        printf("已经找到数据：%s\n", find->number);
    }
    else
    {
        printf("没有这个数据！\n");
    }

    char *location;//指针数组 存的是地址
    char *Number;
    char *Name;

    location =  (char*)malloc(sizeof(char));//申请空间
    Number =  (char*)malloc(sizeof(char));//申请空间
    Name =  (char*)malloc(sizeof(char));//申请空间
    printf("input location:\n");
    scanf("%s", location);
    printf("input Number:\n");
    scanf("%s", Number);
    printf("input Name:\n");
    scanf("%s", Name);

    AddListAppoint(location, Number, Name);

    ScanList();
    FreeList();
    return 0;
}

void AddListEnd(char *number , char *name)//尾添加
{
//创建一个节点
    struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
    pTemp->number = number;
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

void AddListHead (char *number, char *name) //头添加
{
//创建一个节点
    struct Node *pTemp = (struct Node*)malloc(sizeof(struct Node));
//赋值
    pTemp->number = number;
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
        printf("%s\t", pTemp->number);//printf("%s\t",pTemp->number);
        printf("%s\t", pTemp->name);
        pTemp = pTemp->pNext;
        printf("\n");
    }

}
struct Node *SleectList(char *a)//查询指定节点
{
    struct Node *pTemp = g_pHead;
    while (pTemp != NULL)
    {
        if (a == pTemp->number)
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
    //释放链表一定要头尾清空
    g_pHead = NULL;
    g_pEnd = NULL;
}

void AddListAppoint(char *dex, char *number, char *name)
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
    pTemp->number = number;
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

