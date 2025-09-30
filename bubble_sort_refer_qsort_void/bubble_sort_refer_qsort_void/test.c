#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
// Generic bubble sort implementation suitable for any data type
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++) // Swap byte by byte
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	// Number of passes
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1; // Assume the array is already sorted
		// One pass of bubble sort
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				// Swap elements
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
/*  Example: sorting integers  */
int cmp_int_asc(const void* e1, const void* e2)
{   // void pointers must be cast before dereferencing
	return (*(int*)e1 - *(int*)e2);
}
void test3()
{
	int arr[] = { 4,3,2,1,0,9,8,7,6,5 };
	// Sort the array in ascending order
	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int_asc);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

/*  Example: sorting structs  */
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
#include <string.h>
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//strcmp() returns >0, ==0 or <0
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test4()
{
	struct Stu s[] = { {"zhangsan",15}, {"lisi",30}, {"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	// Test using bubble_sort to sort struct data
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
/*  main  */
int main()
{
	test3();
	test4();
	return 0;
}