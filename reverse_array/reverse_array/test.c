#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

// Write a function that reverses a string. The input string is given as an array of characters s.
// https://leetcode.com/problems/reverse-string/description/
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
// Reverse int array
void reverse_int_array(int arr[], int sz){
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}
int main()
{
    // reverse char array by Func. reverseString
    char s_char1[] = "Hannah";
    char s_char2[] = { 'h','e','l','l','o','\0' };
    int sz1 = strlen(s_char1);
    reverseString(s_char1, sz1);
    printf("%s\n", s_char1);
    int sz2 = strlen(s_char2);
    reverseString(s_char2, sz2);
    printf("%s\n", s_char2);

    // reverse int array by Func. reverse_int_array
    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    reverse_int_array(arr, sz);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}