#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * C提高第二天第二课时
 */
int main(int argc,char *argv[])
{
	char *p = 100;//所有指针变量都是占内存4个字节的大小
	int a = 10;//4字节 32位编译器下
	printf("hello world\n");

	char *str = "abc";
//	*(str + 1) = 'g'; //error 指针变量str所指向的内存空间是字符串常量区 ，不能被修改；
	str = "dfg";//但是可以修改他的指向，重新指向另外的内存空间；
	printf("%s\n", str);

	char buf[] = "123";
	char *p1 = "456";
	//buf = p1; 数组变量是常量，不能重新指向另外的内存空间
	*buf = 'c';//但是可以修改他所指向的内存空间的值
	printf("%s\n", buf);

	return 0;
}
