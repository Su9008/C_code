#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// Least common multiple
int find_LCM(int numA, int numB)
{
	int i = 1;
	while ((numA * i) % numB)
	{
		i++;
	}
	return numA * i;
}
int main()
{
	int numA = 0;
	int numB = 0;
	scanf("%d %d", &numA, &numB);
	int LCM = find_LCM(numA, numB);
	printf("%d\n", LCM);

	return 0;
}