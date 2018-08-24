#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int num = 5;
/**
 * 3级指针
 */
void myGetMem91(char ***p)
{
	if (p==NULL)
	{
		return;
	}
	//char **tmp = NULL;
	int i;
	*p = (char **)malloc(sizeof(char *) * 5);
	if (*p != NULL)
	{
		for (i = 0; i < num; i++)
		{
			//(*p)[i] = (char *)malloc(sizeof(char) * 100);
			*(*p+i) = (char *)malloc(sizeof(char) * 100);
		}
	}
	for (i = 0; i < num; i++)
	{
		sprintf((*p)[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	//*p = tmp;
}



/**
* 打印
*/
void _myPrintf91(char ***p)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s ", (*p)[i]);//这里[]的优先级比*高,所以要();
	}
}


/**
 * 释放内存
 */


void _freeGetMem91(char ***p)
{

	if (p==NULL)
	{
		return;
	}

	for (int i=0;i<num;i++)
	{
		if (*(*p+i)!=NULL)
		{
			free(*(*p + i));
			*(*p + i) = NULL;
		}
	}
	
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

int main91(int argc,char *argv[])
{

	char **p = NULL;
	myGetMem91(&p);

	_myPrintf91(&p);

	_freeGetMem91(&p);
	return 0;
}
