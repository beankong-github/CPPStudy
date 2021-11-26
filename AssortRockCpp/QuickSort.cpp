#include <iostream>

int Partition(int* _pArr, int left, int right)
{
	int pivot = _pArr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (_pArr[low] <= pivot && low < right)	// 조건검사 + 경계검사
		{
			low++;	// 피봇보다 큰 값을 만날때까지 low를 오른쪽으로 이동
		}		
		
		while (_pArr[high] >= pivot && high > (left+1))
		{
			high--; // 피봇보다 작은 값을 만날때까지 high를 왼쪽으로 이동
		}

		// low와 high가 교차되지 않은 상태라면 swap
		if (low <= high)
		{
			int tmp = _pArr[low];
			_pArr[low] = _pArr[high];
			_pArr[high] = tmp;
		}
	}
	// 피봇값과 high값 교환
	int tmp = _pArr[high];
	_pArr[high] = pivot;
	_pArr[left] = _pArr[high];

	return high;
}

void QuickSort(int* _pArr, int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(_pArr, left, right);	// 둘로 나눈다
		QuickSort(_pArr, left, pivot - 1);			// 피봇 기준 왼쪽 영역 정렬
		QuickSort(_pArr, pivot + 1, right);			// 피봇 기준 오른쪽 영역 정렬
	}
}
void Quick(int* _pArr, int _iCount, int _iDir)
{
	QuickSort(_pArr, 0, _iCount-1);
}