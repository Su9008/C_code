#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++) //copy until *src='\0' 
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "abcdef"; //abcdef\0
	char arr2[20] = { 0 }; //[7]
	//strcpy(arr2, arr1);
	my_strcpy(arr2, arr1);
	printf("%s\n", arr2);
	return 0;
}