#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _myPrintf(char **p);
static int num = 5;

/**
 * 二维数组底层内存模型
 */
char ** myGetMem()
{
	char **p = NULL;
	int i;
	p = (char **)malloc(sizeof(char *) * 5);
	if (p!=NULL)
	{
		for (i=0;i<num;i++)
		{
			p[i] = (char *)malloc(sizeof(char) * 100);
		}
	}
	for (i=0;i<num;i++)
	{
		sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p;
}

/**
 * 打印
 */
void _myPrintf(char **p)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s ", p[i]);
	}
}


void _mySort(char **p)
{
	//char *tmp = NULL;
	char tmp[30] = { 0 };
	for ( int i=0;i<num;i++)
	{
		for (int j=i;j<num;j++)
		{
			if (strcmp(*(p+i),*(p+j))<0)
			{
				//交换指针的指向
				/*	tmp = *(p + i);
					*(p + i) = *(p + j);
					*(p + j) = tmp;*/
					/*tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;*/

				//交换内存块的值
				strcpy(tmp, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], tmp);
			}
		}
	}
}


/**
 * 释放内存
 */
void free_myGetMem(char **p) {
	if (p==NULL)
	{
		return;
	}
	for (int i=0;i<num;i++)
	{
		if (p[i]!=NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}

	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
}
int main81(int argc,char *argv[])
{
	char **p = NULL;
	p=myGetMem();
	printf("排序之前\n");
	_myPrintf(p);

	//排序
	_mySort(p);


	printf("排序之后\n");
	_myPrintf(p);
	//释放内存
	free_myGetMem(p);
	p = NULL;
	return 0;
}
