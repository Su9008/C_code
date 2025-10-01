#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	// 1. Find the end of the destination string
	while (*dest != '\0')
	{
		dest++;
	}
	// 2. Copy the source string
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	//strcat(arr1, "world");
	my_strcat(arr1, "world");
	/*
	//my_strcat(arr1, arr1); 
	// Append the string to itself
	// Will overwrite '\0' ¡÷ infinite loop
	*/
	printf("%s\n", arr1);

	return 0;
}