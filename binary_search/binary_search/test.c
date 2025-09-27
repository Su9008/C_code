#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// Binary search "target" of an array in ascending order.
// If target exists, then return its index. Otherwise, return -1.
// https://leetcode.com/problems/binary-search/description/

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int nums1[] = { -1,0,3,5,9,12 };
    int target1 = 9;
    int sz1 = sizeof(nums1) / sizeof(nums1[0]);
    int output1 = search(nums1, sz1, target1);
    printf("%d\n", output1); //4

    int target2 = 2;
    int output2 = search(nums1, sz1, target2);
    printf("%d\n", output2); //-1 //2 not exist

    int nums2[] = { 2,5 };
    int target3 = 2;
    int sz2 = sizeof(nums2) / sizeof(nums2[0]);
    int output3 = search(nums2, sz2, target3);
    printf("%d\n", output3); //0

	return 0;
}
