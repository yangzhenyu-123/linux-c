#include<stdio.h>
int main(int argc, char const *argv[])
{
	int (*myshow)(const char *, ...);
	printf("+++++hello world!\n");
	printf("the printf adress is %p\n", printf);
	myshow = printf;
	myshow("======\n");
	return 0;
}
