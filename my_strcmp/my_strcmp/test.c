#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0') // equal
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char arr1[20] = "abca"; // array 1
	char arr2[] = "abcd"; // array 2

	// To compare two strings for equality, we should use strcmp
	// Compare each character's ASCII value from left to right (if equal, move to the next one)
	int ret = strcmp(arr1, arr2);
	if (ret < 0)
		printf("<\n");
	else if (ret == 0)
		printf("==\n");
	else
		printf(">\n");

	int ret_my = my_strcmp(arr1, arr2);
	if (ret_my < 0)
		printf("<\n");
	else if (ret_my == 0)
		printf("==\n");
	else
		printf(">\n");

	return 0;
}