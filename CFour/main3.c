#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void my_copy(char *from, char *to)
{
	//int i = 0;
	//while (*(from+i) != '\0')
	//{
	//	*(to + i) = *(from+i);
	//	i++;
	//}
	/*int n = strlen(from);
	for (int i=0;i<n;i++)
	{
		*(to + i) = *(from + i);
	}*/

	/*for (;*from!='\0';from++,to++)
	{
		*to = *from;
	}
	*to = '\0';*/

	//for (;*from!='\0';)
	//{
	//	//后置++先使用再++,++操作符优先级比*高;
	//	*to++ = *from++;
	//}
	while ((*to=*from)!='\0')
	{
		from++;
		to++;
	}
}

int main31(int argc,char *argv[])
{

	char *from = "abcdef";
	char buf[100] = { 0 };

	my_copy(from, buf);

	printf("from=%s\n", from);
	//printf("*from=%c\n", *from+4);
	printf("to=%s\n", buf);
	
	printf("hello world\n");
	return 0;
}
