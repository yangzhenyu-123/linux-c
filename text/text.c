#include <stdio.h>
 
char *str (char a[],char b[]);

void cal(float (*op)(float,float),float a,float b);
float add(float a,float b);
float sub(float a,float b);


int main()
{
	
	// char a[2][3] = {{'a','b','c'},{'e','f','g'}};
	// char (*p)[3]=a;//数组指针 类似于指针访问二维数组
	// printf("%c\n",*(*(p+1)+2));
	// printf("%d\n",*(*(p+1)+2));	
	// printf("%d\n",*(*(a+1)+2));
	// printf("%s\n",*(p+1));
	
	// char *q[3]={"qwe","wed","fds"};//指针数组 用于处理字符串
	// for(int i=0;i<3;i++)
	// {
	// 	printf("%s\n",q[i]);//q[i]是指针 指向第i个字符串的首字母
	// 	printf("%d\n",*q[i]);
	// 	printf("%c\n",*q[i]);
	// 	printf("%s\n",&(*q[i]));
	// 	puts(q[1]);
	// 	putchar(*q[2]);
	// 	puts("you not da sha bi"+3);
	// 	printf("\n");
	// }
	// printf("%d,%d,%d\n",*("qwe"),'w','f');//  *("qwe") = 'q'
 //    printf("\n");

 // 	char *w = "abcd";//字符指针 w是指针指向->字符串首字母的地址 该指针只能读取常量 不能修改指向字符串的值
 // 	printf("%s\n","abcd"+1 );
	// printf("%c\n",*("abcd"+1));
	// printf("%d\n",*w);
	// printf("%d\n",*(w+1));
	// printf("%s\n",w);
	// printf("%s\n",w+1);
	// printf("%c\n",*w);//w是指针=地址 *w代表该地址存的数据='a'

	/*
	指针函数  用于字符串处理 指针类型的函数
	 */
	// char s1[20] = "chinese";
	// char s2[10] = "dream";
 //    char *p = str (s1,s2);
	// puts(p);
	// return 0;
	
	//函数指针 指向函数的指针 保存函数地址
	printf("int put: 1:+ ;2:- :");
	int d;
	float x,y;
	scanf("%d",&d);
	printf("input two number:");
	scanf("%f,%f",&x,&y);

	switch(d)
	{
		case 1:
		cal(add,x,y);
	break;

		case 2:
		cal(sub,x,y);
	break;	
	}
	return 0;

}

float add(float a,float b){
		float c = a+b;
	printf("result is:%f\n",c);
    return c;
}
float sub(float a,float b){
		float c = a - b;
		printf("result is:%f\n",c);
		return c;

}
void cal(float (*op)(float,float),float a,float b){
	op(a,b);

}
char *str (char *a,char *b)
{
	char *p = a;
	char *q = b;
	while(*p != '\0' )
		p++;
	*p++ = ' ';
	while(*q != '\0')
	{
		*p++ = *q++;
	}
	while(*p != '\0' )
		p++;
	*p++ = '!';
return a;
}