#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//C��ߵ��������



/**
 * ��ά�����Ӧ��2,(ʹ������ָ��ı����ָ��)
 *��ά����ĵײ��ڴ�ģ��
 */
void splitString1(char ***buf, const char *tag, const char *src, int *num)
{

	char *p = NULL;
	char *tmpsrc = src;
	int count = 0;

	//����ָ�������ַ�������
	while ((p = strtok(tmpsrc, tag)) != NULL)
	{
		//printf("%s\n", p);
		count++;
		tmpsrc = tmpsrc + strlen(p) + 1;
	}

	//Ϊ����ָ���Լ�һ��ָ������ڴ�
	char **tmp = NULL;
	tmp = (char **)malloc(sizeof(char *)*count);
	for (int i=0;i<count;i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * 100);
		memset(tmp[i], 0, 100);
	}

	//Ϊÿ��һ��ָ�븳ֵ,����ָ���൱�ڶ�ά����,��������ÿ��Ԫ�ض���ָ��
	p = NULL;
	tmpsrc = src;
	int i = 0;
	while ((p = strtok(tmpsrc, tag)) != NULL)
	{
		strcpy(tmp[i], tmpsrc);
		tmpsrc = tmpsrc + strlen(p) + 1;
		i++;
	}
	*num = count;
	*buf = tmp;
}


void _freeGetMem101(char ***p,int count)
{
	if (p==NULL)
	{
		return;
	}
	char **tmp = *p;
	for (int i=0;i<count;i++)
	{
		if (tmp[i]!=NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}
	free(tmp);
	tmp = NULL;
}

/**
 * ��ά�����Ӧ��1
 */
void splitString(char buf[10][30],const char *tag,const char *src,int *num)
{
	char *p = NULL;
	
	int count = 0;

	while ((p = strtok(src, tag))!=NULL)
	{
		//printf("%s\n", p);
		strcpy(buf[count], p);
		count++;
		src = src + strlen(p)+1;
	}

	int len = sizeof(src) / sizeof(*src);
	*num = count;
}


int main(int argc,char *argv[])
{
	
	char src[] = "abcdef,advad,1111,bojad,1oias,";
	char *tag = ",";
	int num = 0;
	//char buf[10][30] = { 0 };
	//splitString(buf, tag, src, &num);

	//for (int i=0;i<num;i++)
	//{
	//	printf("%s ", buf[i]);
	//}
	//printf("\n");
	//printf("num=%d\n", num);

	char **p = NULL;

	splitString1(&p,tag,src,&num);

	for (int i=0;i<num;i++)
	{
		printf("%s ", p[i]);
	}

	_freeGetMem101(&p, num);

	return 0;
}
