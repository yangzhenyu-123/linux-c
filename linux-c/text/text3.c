#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
typedef struct Link_Data{
    int  elem;
    struct Link_Data *next;
}link;
typedef struct Link_Char{
    char  *s;
    struct Link_Char *next;
}link1;
link *p_head = NULL;
link *p_end = NULL;
link * initLink(int i);//初始化链表的函数
link1 *initLink1(char *s);
void display(link *p);//用于输出链表的函数
void display1(link1 *p);
void insertdata();
int main() 
{
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    for (int i = 0; i < 7; i++)
    {
        link *p=initLink(i);
        display(p);
    }
    link1 *q =initLink1("zhuangsan");
    display1(q);

      printf("\n");
    return 0;
}
link * initLink(int i)
{
    link * p=(link*)malloc(sizeof(link));//创建一个头结点
    link * temp=p;//声明一个指针指向头结点，
    
    //生成一个新结点
        link *a=(link*)malloc(sizeof(link));
    //赋值   
        a->elem=i;
        a->next=NULL;
    //链接
        temp->next=a;
        temp=temp->next;   
    return p;
}
link1 * initLink1(char *s)
{
    link1 * p=(link1*)malloc(sizeof(link1));//创建一个头结点
    link1 * temp=p;//声明一个指针指向头结点，
    
    //生成一个新结点
        link1 *a=(link1*)malloc(sizeof(link1));
    //赋值   
        a->s=s;
        a->next=NULL;
    //链接
        temp->next=a;
        temp=temp->next;   
    return p;
}
void display(link *p){
        link* temp=p;//声明一个temp指针重新指向头结点
    while (temp->next) //只要temp指针指向的结点的next不是Null，就执行输出语句。
    {
        temp=temp->next;
        printf("%d\t",temp->elem);
    }
}
void display1(link1 *q)
{
    link1* temp=q;//声明一个temp指针重新指向头结点   
    while (temp->next) 
    {
        temp=temp->next;
        printf("%s\t",temp->s);
    }
}

