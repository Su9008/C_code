#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) // compare characters one by one
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') // found the substring
		{
			return (char*)p;
		}
		p++;
	}
	return NULL; // substring not found
}
int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("Substring does not exist\n");
	}
	else
	{
		printf("%s\n", ret); // bbcdef
	}
	/*
	char email[] = "zpw@bitejiuyeke.com";
	char substr[] = "bitejiuyeke";
	char* ret2 = strstr(email, substr);
	//char* ret2 = my_strstr(email, substr);
	if (ret2 == NULL)
	{
		printf("Substring does not exist\n");
	}
	else
	{
		printf("%s\n", ret2);
	}
	*/
	return 0;
}