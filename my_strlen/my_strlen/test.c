#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//Coding my strlen 
#include<assert.h>
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

#include<string.h>
int main()
{
	char arr1[] = "hello world";
	int sz_h = strlen(arr1);
	printf("%d\n", sz_h);
	int sz_me = my_strlen(arr1);
	printf("%d\n", sz_me);
	return 0;
}
