#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList; /* 定义LinkList */

//初始化表头，用一级指针（此方式无效）
Status InitList1(LinkList L)    //等价于Node *L
{
    L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!L) /* 存储分配失败 */
        return ERROR;
    L->next = NULL; /* 指针域为空 */

    return OK;
}

//初始化表头，用二级指针
Status InitList2(LinkList *L)   //等价于Node **L
{
    *L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L)) /* 存储分配失败 */
        return ERROR;
    (*L)->next = NULL; /* 指针域为空 */

    return OK;
}

//初始化表头，用一级指针引用
Status InitList3(LinkList &L)   //等价于Node *&L
{
    L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!L) /* 存储分配失败 */
        return ERROR;
    L->next = NULL; /* 指针域为空 */

    return OK;
}

//清空链表，使用二级指针
Status ClearList1(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;         /*  p指向第一个结点 */
    while (p)               /*  没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;      /* 头结点指针域为空 */
    return OK;
}

//清空链表，使用一级指针
Status ClearList2(LinkList L)
{
    LinkList p, q;
    p = L->next;         /*  p指向第一个结点 */
    while (p)               /*  没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;      /* 头结点指针域为空 */
    return OK;
}

//销毁链表，使用一级指针(此方式无效)
Status DestroyList1(LinkList L)
{
    LinkList p, q;
    p = L->next;         /*  p指向第一个结点 */
    while (p)               /*  没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
    return OK;
}

//销毁链表，使用二级指针
Status DestroyList2(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;         /*  p指向第一个结点 */
    while (p)               /*  没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
    return OK;
}

//销毁链表，使用一级指针引用
Status DestroyList3(LinkList &L)
{
    LinkList p, q;
    p = L->next;         /*  p指向第一个结点 */
    while (p)               /*  没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
    return OK;
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;     /* 声明一结点p */
    p = L->next;     /* 让p指向链表L的第一个结点 */
    j = 1;      /*  j为计数器 */
    while (p && j < i) /* p不为空或者计数器j还没有等于i时，循环继续 */
    {
        p = p->next;  /* 让p指向下一个结点 */
        ++j;
    }
    if ( !p || j > i )
        return ERROR;  /*  第i个元素不存在 */
    *e = p->data;   /*  取第i个元素的数据 */
    return OK;
}


//在中间插入元素，用二级指针
Status ListInsert1(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)     /* 寻找第i个结点 */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;   /* 第i个元素不存在 */
    s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
    s->data = e;
    s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
    p->next = s;          /* 将s赋值给p的后继 */
    return OK;
}
//在中间插入元素，用一级指针
Status ListInsert2(LinkList L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = L;
    j = 1;
    while (p && j < i)     /* 寻找第i个结点 */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;   /* 第i个元素不存在 */
    s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
    s->data = e;
    s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
    p->next = s;          /* 将s赋值给p的后继 */
    return OK;
}
//删除一个元素，用二级指针
Status ListDelete1(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i)  /* 遍历寻找第i个元素 */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;           /* 第i个元素不存在 */
    q = p->next;
    p->next = q->next;            /* 将q的后继赋值给p的后继 */
    *e = q->data;               /* 将q结点中的数据给e */
    free(q);                    /* 让系统回收此结点，释放内存 */
    return OK;
}
//删除一个元素，用一级指针
Status ListDelete2(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = L;
    j = 1;
    while (p->next && j < i)  /* 遍历寻找第i个元素 */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;           /* 第i个元素不存在 */
    q = p->next;
    p->next = q->next;            /* 将q的后继赋值给p的后继 */
    *e = q->data;               /* 将q结点中的数据给e */
    free(q);                    /* 让系统回收此结点，释放内存 */
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    //InitList1(L);   //一级指针方式创建表头，失败
    InitList2(&L);  //二级指针方式创建表头，成功
    //InitList3(L);     //一级指针引用方式创建表头，成功
    for (j = 1; j <= 7; j++)
        ListInsert2(L, 1, j);
    printf("一级指针方式在L的表头依次插入1～7后：");
    ListTraverse(L);

    ListInsert1(&L, 3, 12);
    printf("二级指针方式在L的中间插入12后：");
    ListTraverse(L);

    ListInsert2(L, 5, 27);
    printf("一级指针在L的中间插入27后：");
    ListTraverse(L);

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);

    ListDelete1(&L, 5, &e); /* 删除第5个数据 */
    printf("二级指针方式删除第%d个的元素值为：%d\n", 5, e);
    printf("依次输出L的元素：");
    ListTraverse(L);

    ListDelete2(L, 3, &e); /* 删除第3个数据 */
    printf("一级指针方式删除第%d个的元素值为：%d\n", 3, e);
    printf("依次输出L的元素：");
    ListTraverse(L);

    printf("二级指针方式清空链表\n");
    ClearList1(&L);
    printf("依次输出L的元素：");
    ListTraverse(L);

    for (j = 1; j <= 7; j++)
        ListInsert2(L, j, j);
    printf("在L的表尾依次插入1～7后：");
    ListTraverse(L);

    printf("一级指针方式清空链表\n");
    ClearList2(L);
    printf("依次输出L的元素：");
    ListTraverse(L);

    printf("销毁链表\n");
    DestroyList1(L);   //一级指针方式销毁链表，失败,且出现满屏乱码
    //DestroyList2(&L);  //二级指针方式销毁链表，成功
    //DestroyList3(L);     //一级指针引用方式销毁链表，成功
    ListTraverse(L);

    return 0;
}