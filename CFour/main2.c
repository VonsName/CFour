#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 字符串的内存分配可以在堆上,也可以在栈上,也可以是在全局常量区
 */
int main22(int argc,char *argv[])
{
	
	/**
	 * 初始化字符串的几种方式
	 *数组也是一种数据类型,是一个固定大小的内存块儿
	 */
	char buf[] = "abc";

	printf("sizeof=%d\n", sizeof(buf));//4 数组大小,包括\0
	printf("strlen=%d\n", strlen(buf));//3 字符串长度,不包括\0

	char buf1[] = { 'b','c','d','\0'};
	//char buf2[2] = "qwe";//“buf2”: 数组界限溢出
	char buf2[3] = "xy";//这种初始化方式必须要多预留一个字节的位置用来存储0,否则会出现乱码
	printf("buf2[2]=%d\n", buf2[2]);
	char buf3[3] = {'q','w','\0'};

	printf("buf=%s\n", buf);
	printf("buf1=%s\n", buf1);
	printf("buf2=%s\n", buf2);
	printf("buf3=%s\n", buf3);

	printf("hello world\n");
	return 0;
}
