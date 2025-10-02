#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
// memcpy is responsible for copying data between two independent memory blocks
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 }; // 4*5 = 20 bytes
	int arr2[20] = { 0 };
	//memcpy(arr2, arr1, 20);
	char* ret = my_memcpy(arr2, arr1, 20);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]); // 1 2 3 4 5
	}

	return 0;
}