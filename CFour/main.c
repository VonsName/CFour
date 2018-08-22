#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/**
 * 这里return的是内存的首地址,而不是整个内存块
 *因为这是在栈空间,编译器自动分配和释放内存
 *函数结束内存释放
 *指针变量和他所指向的内存空间是两个不同的概念
 */
char *getMem()
{
	char buf[64]="hello";
	//strcpy(buf, "hello");
	printf("%s\n", buf);
	return buf;
}

/**
 * 字符串全局常量区 
 */
char *getMem2()
{
	char *p = "hello";
	return p;
}

/**
 * C提高13课时
 */
int main1()
{
	int a[10];
	printf("a=%d\n", a);
	printf("a+1=%d\n", a+1);//加了4个字节
	
	/************************************************************************/
	/* a和&a代表的数据类型不一样
	*	a代表数组首元素的地址
	*	&a代表的是整个数组的地址
	*/
	/************************************************************************/
	printf("&a=%d\n", &a);
	printf("&a+1=%d\n", &a+1);//加了40个字节,整个数组所有元素的大小
	

	printf("%d\n", sizeof(a));//40


	/************************************************************************/
	/* 栈的开口方向默认是向下的      即先定义的变量的内存地址大于后定义的变量内存地址
	*/
	/************************************************************************/
	int c;
	int d;
	printf("c=%d,d=%d\n", &c, &d);

	//char *buf = getMem();
	//printf("%s\n", buf); 段错误

	char *p = getMem2();//ok
	printf("%s\n", p);
	return 0;
}