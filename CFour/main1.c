#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * C��ߵڶ���ڶ���ʱ
 */
int main(int argc,char *argv[])
{
	char *p = 100;//����ָ���������ռ�ڴ�4���ֽڵĴ�С
	int a = 10;//4�ֽ� 32λ��������
	printf("hello world\n");

	char *str = "abc";
//	*(str + 1) = 'g'; //error ָ�����str��ָ����ڴ�ռ����ַ��������� �����ܱ��޸ģ�
	str = "dfg";//���ǿ����޸�����ָ������ָ��������ڴ�ռ䣻
	printf("%s\n", str);

	char buf[] = "123";
	char *p1 = "456";
	//buf = p1; ��������ǳ�������������ָ��������ڴ�ռ�
	*buf = 'c';//���ǿ����޸�����ָ����ڴ�ռ��ֵ
	printf("%s\n", buf);

	return 0;
}
