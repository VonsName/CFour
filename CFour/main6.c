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
				//��������ָ�����������Ԫ��,��ָ���ֵ(����ÿ��Ԫ�ض���һ��ָ��,
						//�洢�����ַ������׵�ַ,���ｻ������ÿ��ָ��洢�ĵ�ַ,�൱�ڸı�ָ���ָ��)
				tmp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = tmp;
			}
		}
	}
}

int main61(int argc,char *argv[])
{
	//const int a = 10;//C������const���εı����Ǽٵ�,����ͨ��ָ���޸�;
	////a = 20; error,��const���� ���ܱ��޸�

	//int *p = &a;
	//*p = 100;
	//printf("%d\n", a);
	//printf("hello world\n");


	char *buf[] = {"ccsc","aasa","ddd"};
	int len = sizeof(buf) / sizeof(*buf);
	printf("����֮ǰ\n");
	_print(&buf[0], len);


	//printf("%s\n", *(buf + 0));
	//printf("%s\n", buf[0]);

	printf("\n");
	_sort(buf, len);
	printf("����֮��\n");
	_print(buf, len);
	return 0;
}
