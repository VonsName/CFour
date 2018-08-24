#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void _print(char **p,int len)
{
	for (int i=0;i<len;i++)
	{
		printf("%s  ", *(p+i));
		//printf("%p\n",*( p + i));
	}
}

void _sort(char **p, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			char *tmp = NULL;
			if (strcmp(*(p+i), *(p+j)) > 0)
			{
				//交换的是指针数组的数组元素,即指针的值(数组每个元素都是一个指针,
						//存储的是字符串的首地址,这里交换的是每个指针存储的地址,相当于改变指针的指向)
				tmp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = tmp;
			}
		}
	}
}

int main61(int argc,char *argv[])
{
	//const int a = 10;//C语言中const修饰的变量是假的,可以通过指针修改;
	////a = 20; error,被const修饰 不能被修改

	//int *p = &a;
	//*p = 100;
	//printf("%d\n", a);
	//printf("hello world\n");


	char *buf[] = {"ccsc","aasa","ddd"};
	int len = sizeof(buf) / sizeof(*buf);
	printf("排序之前\n");
	_print(&buf[0], len);


	//printf("%s\n", *(buf + 0));
	//printf("%s\n", buf[0]);

	printf("\n");
	_sort(buf, len);
	printf("排序之后\n");
	_print(buf, len);
	return 0;
}
