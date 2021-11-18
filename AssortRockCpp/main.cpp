#include <iostream>
#include "Assignment.h"


int main()
{
	// =========
	// 별찍기 과제
	// =========
	//CreateStar(5, 1);

	//printf("\n");
	//CreateStar(5, -1);

	//printf("\n");
	//CreateStar(3, 1);

	//printf("\n");
	//CreateStar(3, -1);

	// ==============
	// 버블 정렬 과제
	// ==============
	int iArr1[5] = {};
	int iArr2[5] = {};
	
	RandomArray(iArr1, 5, 0, 10);
	RandomArray(iArr2, 5, 100, 110);

	Sort(iArr1, 5, 1);
	Sort(iArr2, 5, -1);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", iArr1[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", iArr2[i]);
	}
}
