#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * �ַ������ڴ��������ڶ���,Ҳ������ջ��,Ҳ��������ȫ�ֳ�����
 */
int main22(int argc,char *argv[])
{
	
	/**
	 * ��ʼ���ַ����ļ��ַ�ʽ
	 *����Ҳ��һ����������,��һ���̶���С���ڴ���
	 */
	char buf[] = "abc";

	printf("sizeof=%d\n", sizeof(buf));//4 �����С,����\0
	printf("strlen=%d\n", strlen(buf));//3 �ַ�������,������\0

	char buf1[] = { 'b','c','d','\0'};
	//char buf2[2] = "qwe";//��buf2��: ����������
	char buf2[3] = "xy";//���ֳ�ʼ����ʽ����Ҫ��Ԥ��һ���ֽڵ�λ�������洢0,������������
	printf("buf2[2]=%d\n", buf2[2]);
	char buf3[3] = {'q','w','\0'};

	printf("buf=%s\n", buf);
	printf("buf1=%s\n", buf1);
	printf("buf2=%s\n", buf2);
	printf("buf3=%s\n", buf3);

	printf("hello world\n");
	return 0;
}
