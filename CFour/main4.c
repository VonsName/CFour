#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * C��ߵ�����
 */
void evenOld(char *src, char *des1, char *des2);


void evenOld(char *src, char *des1, char *des2)
{
	int i = 0;
	int j = 0, k = 0;
	while (*(src+i)!='\0')
	{
		if ((i+1)%2==0)
		{
			*(des1 + j) = *(src + i);
			j++;
		}
		else {
			*(des2 + k) = *(src + i);
			k++;
		}
		i++;
	}
}

void trim_str(char *src, char *des);

void trim_str(char *src, char *des)
{
	if (src==NULL||des==NULL)
	{
		return;
	}
	char *tmp = src;

	int i = 0;
	int j = 0;
	while (*(src+i)!='\0')
	{
		if (*(src + i)!=' ')
		{
			*(des + j) = *(src + i);
			j++;
		}
		i++;
	}
}


//����ԭ��
int numcout(char *src, char *des, int *num);

//����ʵ��
int numcout(char *src, char *des, int *count)
{
	char *tmp = src;
	int tmpCount = 0;

	if (src==NULL||des==NULL||count==NULL)
	{
		return -1;
	}

	//do 
	//{
	//	tmp =strstr(tmp, des);//����abd���ַ����е�λ��,�ҵ��򷵻ص�һ�γ��ֵĵ�ַ
	//	if (tmp !=NULL)
	//	{
	//		tmpCount++;
	//		tmp = tmp + strlen(des);
	//	}
	//	else
	//	{
	//		break;
	//	}
	//} while (*tmp!='\0');

	while ((tmp=strstr(tmp,des)))
	{
		tmpCount++;
		tmp = tmp + strlen(des);
	}
	*count = tmpCount;
	return tmpCount;
}

int main45(int argc,char *argv[])
{
	int counter = 0;
	char *str = "1abd123abd451bca";
	char buf[] = "abd";
	//do 
	//{
	//	str=strstr(str, "abd");//����abd���ַ����е�λ��,�ҵ��򷵻ص�һ�γ��ֵĵ�ַ
	//	if (str!=NULL)
	//	{
	//		counter++;
	//		str = str + strlen("abd");
	//	}
	//	else
	//	{
	//		break;
	//	}
	//} while (*str!='\0');

	/*while ((str=strstr(str,"abd"))!=NULL)
	{
		counter++;
		str = str + strlen("abd");
	}
	printf("%d\n", counter);*/

	counter= numcout(str, buf, &counter);
	printf("%d\n", counter);
	printf("hello world\n");

	char *src = "   aabbcc  ";
	char  *des = (char *)malloc(sizeof(char) * 100);
	memset(des, 0,strlen(des));
	trim_str(src, des);
	printf("%s\n", des);


	char *p = "12badlasd";

	char *pp1 = NULL;
	pp1 =(char *)malloc(strlen(p)/2+1);
	memset(pp1, 0, strlen(p)/2+1);

	char *p2 = NULL;
	p2=	(char *)malloc(strlen(p)/2+1);
	//printf("p2strlen=%d\n", strlen(p2));//�δ���!!!����ʹ�� strlen(p2)�Ǵ��������,
																//���ʱ����ֻ�Ƿ������ڴ�
																//����ԭ����;
	memset(p2, 0, strlen(p)/2+1);

	evenOld(p, pp1, p2);
	printf("pp1=%s\n", pp1);
	printf("p2=%s\n", p2);

	if (pp1 != NULL)
	{
		free(pp1);
		pp1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	return 0;
}
