#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMem1(char **p)
{
	*p = 900;
	printf("p=%d\n",*p);
}

int main003()
{
	
	int i = 0;
	printf("&i=%p\n", &i);

	char *p = NULL;

	p = 0x77;
	printf("%d\n", p);
	getMem1(&p);
	printf("p自后=%d\n", p);
	return 0;
}

/**
 * C提高第二天第二课时
 */
int main009(int argc,char *argv[])
{
	char *p = 100;//所有指针变量都是占内存4个字节的大小
	int a = 10;//4字节 32位编译器下
	printf("hello world\n");

	char *str = "abc";
//	*(str + 1) = 'g'; //error 指针变量str所指向的内存空间是字符串常量区 ，不能被修改；
	//str = "dfg";//但是可以修改他的指向，重新指向另外的字符串常量内存空间；
	str = str + 1;
//	strcpy(str, "xyz");//error,段错误,strcpy操作的是str指向的内存空间,是字符串常量,不能被改变;
	printf("%s\n", str);

	char buf[] = "123";
	char *p1 = "456";
	//buf = p1; 数组变量是常量，不能重新指向另外的内存空间
	*buf = 'c';//但是可以修改他所指向的内存空间的值
	printf("%s\n", buf);

	return 0;
}
