#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void _print1(char p[10][30], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s  ", *(p + i));
	}
}


//交换的是内存块,字符串的值;
void _sort1(char p[10][30],int slen)
{
	//char tmp[30];
	//memset(tmp, 0, strlen(tmp)); //strlen(tmp)这里这种用法 导致段错误 因为tmp还没出初始化

	char tmp[30];
	memset(tmp, 0, 30);
	for (int m=0;m<slen;m++)
	{
		for (int k=m;k<slen;k++)
		{
			if (strcmp(p[m],p[k])>0)
			{

				//这里交换的是内存块,即数组里面的指针的指针的值(字符串);
				/*	strcpy(tmp, p[m]);
					strcpy(p[m], p[k]);
					strcpy(p[k], tmp);*/
				strcpy(tmp, *(p + m));
				strcpy(*(p + m), *(p + k));
				strcpy(*(p + k), tmp);
			}
		}
	}
	printf("\n");
}


/**
 * error 错误的!!!
 */
void _sort2(char ***p,int len)
{
	char *tmp=NULL;
	for (int i=0;i<len;i++)
	{
		for (int j=i;j<len;j++)
		{
			if (strcmp(**(p+i),**(p+j))>0)
			{
				tmp = **(p + i);
				**(p + i) = **(p + j);
				**(p + j) = tmp;
			}
		}
	}
}


int main71(int argc,char *argv[])
{
	

	//
	char buf[10][30] = {
		{ "bbbbb" },
		{ "aaaaa" },
		{ "dddd" },
		{ "111111" },
		{ "ddadasdadd" },
		{ "dadaddd" },
	};


	int len = sizeof(buf) / sizeof(*buf);
	_print1(buf, len);
	printf("len=%d\n", len);
	_sort1(buf,len);
	//_sort2(buf, len);  错误的方法
	_print1(buf, len);
	return 0;
}
