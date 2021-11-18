#include <iostream>
#pragma warning(disable:6031)
#pragma warning(disable:4996)
#define MAX 100

int largestAge;
int smallestAge;

void CompareAge(int cur)
{
	// 가장 작은 나이 초기화
	if (smallestAge == 0)
		smallestAge = cur;

	if (cur > largestAge)
		largestAge = cur;
	else if (cur < smallestAge)
		smallestAge = cur;

	return;
}

int main()
{
	int count;
	int ages[MAX] = {};

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{	
		scanf("%d", ages+i);
		CompareAge(ages[i]);
	}

	printf("%d", largestAge-smallestAge);
	return 0;
}