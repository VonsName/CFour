#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _myPrintf(char **p);
static int num = 5;

/**
 * ��ά����ײ��ڴ�ģ��
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
 * ��ӡ
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
				//����ָ���ָ��
				/*	tmp = *(p + i);
					*(p + i) = *(p + j);
					*(p + j) = tmp;*/
					/*tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;*/

				//�����ڴ���ֵ
				strcpy(tmp, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], tmp);
			}
		}
	}
}


/**
 * �ͷ��ڴ�
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
	printf("����֮ǰ\n");
	_myPrintf(p);

	//����
	_mySort(p);


	printf("����֮��\n");
	_myPrintf(p);
	//�ͷ��ڴ�
	free_myGetMem(p);
	p = NULL;
	return 0;
}
