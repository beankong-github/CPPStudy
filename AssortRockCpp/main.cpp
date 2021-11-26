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
	// 정렬 과제
	// ==============
	int iArr1[5] = {5,4,3,2,1};
	int iArr2[5] = {9,8,7,6,5};
	
	//RandomArray(iArr1, 5, 0, 10);
	//RandomArray(iArr2, 5, 100, 110);


	// 버블
	//Bubble(iArr1, 5, 1);
	//Bubble(iArr2, 5, -1);

	// 삽입
	//Insert(iArr1, 5, 1);
	//Insert(iArr2, 5, -1);
	
	// 퀵
	Quick(iArr1, 5, 1);
	

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", iArr1[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", iArr2[i]);
	}

	return 0;
}
