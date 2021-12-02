#include<iostream>

void MMerge(int* _iArr, int _iFirst, int _iMid, int _iEnd, int _iDir)
{
	int iLeft = _iFirst;	// 첫번째 배열 시작 점
	int iMid = _iMid + 1;	// 두번째 배열 시작 점
	int iRight = _iEnd;		// 두번째 배열 끝 점

	int iCounter = 0;

	// 두 배열을 정렬하여 합친 새 배열을 저장할 곳
	int* pMergedArr = (int*)malloc(sizeof(int) * ((iRight - iLeft) + 1));
	
	// 오름차순 정렬
	if (_iDir == 1)
	{
		// 두 배열이 모두 합병이 끝나지 않았을 때, 두 배열을 비교하여 더 작은 수를 결과 배열에 넣어준다
		while (iLeft < _iMid +1 && iMid <= _iEnd)
		{
			if (_iArr[iLeft] <= _iArr[iMid])
			{
				pMergedArr[iCounter] = _iArr[iLeft];
				iLeft++;
				iCounter++;
			}
			else if (_iArr[iLeft] > _iArr[iMid])
			{
				pMergedArr[iCounter] = _iArr[iMid];
				iMid++;
				iCounter++;
			}
		}

		// 첫번째 배열 요소가 모두 합병되지 않았다면, 남은 요소들을 순차적으로 동적 배열에 옯겨준다
		if (iLeft <= _iMid)
		{
			for (int j = iLeft; j <= _iMid; j++)
			{
				pMergedArr[iCounter] = _iArr[j];
				iCounter++;
			}
		}

		// 두번째 배열 요소가 모두 합병되지 않았다면, 남은 요소들을 순차적으로 동적 배열에 옯겨준다
		else if (iMid <= _iEnd)
		{
			for (int j = iMid; j <= _iEnd; j++)
			{
				pMergedArr[iCounter] = _iArr[j];
				iCounter++;
			}
		}
	}

	// 내림차순 정렬
	else if (_iDir == -1)
	{

		// 두 배열이 모두 합병이 끝나지 않았을 때, 두 배열을 비교하여 더  수를 결과 배열에 넣어준다
		while (iLeft < iMid && iMid <= _iEnd)
		{
			if (_iArr[iLeft] >= _iArr[iMid])
			{
				pMergedArr[iCounter] = _iArr[iLeft];
				iLeft++;
				iCounter++;
			}
			else if (_iArr[iLeft] < _iArr[iMid])
			{
				pMergedArr[iCounter] = _iArr[iMid];
				iMid++;
				iCounter++;
			}
		}

		// 첫번째 배열 요소가 모두 합병되지 않았다면, 남은 요소들을 순차적으로 동적 배열에 옯겨준다
		if (iLeft <= _iMid)
		{
			for (int j = iLeft; j <= _iMid; j++)
			{
				pMergedArr[iCounter] = _iArr[j];
				iCounter++;
			}
		}

		// 두번째 배열 요소가 모두 합병되지 않았다면, 남은 요소들을 순차적으로 동적 배열에 옯겨준다
		else if (iMid <= _iEnd)
		{
			for (int j = iMid; j <= _iEnd; j++)
			{
				pMergedArr[iCounter] = _iArr[j];
				iCounter++;
			}
		}
	}

	// 동적 배열에 저장된 데이터를 원본 배열에 반영하기
 	if (iCounter == _iEnd - _iFirst + 1)
	{
		int i = 0;
		for (int j = _iFirst; j <= _iEnd; j++)
		{
			_iArr[j] = pMergedArr[i];
			i++;
		}
	}

	free(pMergedArr);
}

// 재귀를 이용하여 분할 정복
void MSort(int* _iArr, int _iFirst, int _iEnd, int _iDir)
{
	if (_iFirst < _iEnd)
	{
		int mid = (_iFirst + _iEnd) / 2;
		MSort(_iArr, _iFirst, mid, _iDir);
		MSort(_iArr, mid + 1, _iEnd, _iDir);

		MMerge(_iArr, _iFirst, mid, _iEnd, _iDir);
	}
}

void Merge(int* _iArr, int _iCounter, int _iDir)
{
	MSort(_iArr, 0, _iCounter-1, _iDir);
}
