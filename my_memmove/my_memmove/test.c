#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Sometimes we need to process data from front to back
// Sometimes we need to process data from back to front
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		// Copy src from front to back
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		// Copy src from back to front
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//memmove(arr1 + 2, arr1, 20); // 1 2 1 2 3 4 5 8 9 10
	//my_memmove(arr1 + 2, arr1, 20); // 1 2 1 2 3 4 5 8 9 10
	my_memmove(arr1, arr1 + 2, 20); // 3 4 5 6 7 6 7 8 9 10
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}