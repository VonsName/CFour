#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMem1(char **p)
{
	*p = 900;
	printf("p=%d\n",*p);
}

int main003()
{
	
	int i = 0;
	printf("&i=%p\n", &i);

	char *p = NULL;

	p = 0x77;
	printf("%d\n", p);
	getMem1(&p);
	printf("p�Ժ�=%d\n", p);
	return 0;
}

/**
 * C��ߵڶ���ڶ���ʱ
 */
int main009(int argc,char *argv[])
{
	char *p = 100;//����ָ���������ռ�ڴ�4���ֽڵĴ�С
	int a = 10;//4�ֽ� 32λ��������
	printf("hello world\n");

	char *str = "abc";
//	*(str + 1) = 'g'; //error ָ�����str��ָ����ڴ�ռ����ַ��������� �����ܱ��޸ģ�
	//str = "dfg";//���ǿ����޸�����ָ������ָ��������ַ��������ڴ�ռ䣻
	str = str + 1;
//	strcpy(str, "xyz");//error,�δ���,strcpy��������strָ����ڴ�ռ�,���ַ�������,���ܱ��ı�;
	printf("%s\n", str);

	char buf[] = "123";
	char *p1 = "456";
	//buf = p1; ��������ǳ�������������ָ��������ڴ�ռ�
	*buf = 'c';//���ǿ����޸�����ָ����ڴ�ռ��ֵ
	printf("%s\n", buf);

	return 0;
}
