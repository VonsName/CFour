#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf2[50] = { 0 };

/**
 * 递归
 */
void inverse_(char *p)
{
	if (p==NULL)
	{
		return;
	}

	if (*p == '\0')
	{
		return;
	}
	inverse_(p + 1);
	strncat(buf2, p,1);
}

/**
 * 字符串反转
 */
void str_change(char *p)
{
	char *tmp = p;
	char *p1 = tmp +strlen(tmp)-1;

	while (tmp<p1)
	{
		char c = *tmp;
		*tmp = *p1; //这里必须注意,p是指向全局区的字符串常量区,不能被改变
		*p1 = c;
		++tmp;
		--p1;
	}
}

void isnospace(char *p);
/**
 * 求非空字符串
 */
void isnospace(const char *p)
{
	char *tmp = p;
	int i = 0;
	int j = 0;
	char buf[10];
	memset(buf, 0, sizeof(buf));
	while (*(tmp + i) != '\0')
	{
		if (!isspace(*(tmp + i)))
		{
			*(buf + j) = *(tmp + i);
			j++;
		}
		i++;
	}
	printf("%s\n", buf);
	printf("buflen=%d\n", strlen(buf));
}

void chang_(int *pa)
{
	*pa = 20;
}

int main51(int argc,char *argv[])
{
	int a = 10;
	int *pa = &a;
	chang_(pa);
	printf("%d\n", *pa);
	printf("hello world\n");


	char *p= "   abd   ";//ps->字符串常量是不能被改变的
	isnospace(p);
	
	char buf[] = "adc";
	str_change(buf);
	printf("%s\n",buf);

	char buf1[] = "qwert";
	
	inverse_(buf1);

	printf("%s\n", buf2);
	return 0;
}
