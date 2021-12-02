#include <iostream>

void Selection(int* _iArr, int _iCount, int _iDir)
{
	// 오름차순
	if (_iDir == 1)
	{
		for (int j = 0; j < _iCount; j++)
		{
			int iMinIndex = j ;

			for (int i = j + 1; i < _iCount; i++)
			{
				if (_iArr[i] < _iArr[iMinIndex])
					iMinIndex = i;
			}

			// 현재 값이 가장 작은 값이 아니라면
			if (j != iMinIndex)
			{
				// 스왑
				int tmp = _iArr[j];
				_iArr[j] = _iArr[iMinIndex];
				_iArr[iMinIndex] = tmp;

			}
		}
	}

	// 내림차순
	else if (_iDir == -1)
	{
		for (int j = 0; j < _iCount; j++)
		{
			int iMaxIndex = j;

			for (int i = j + 1; i < _iCount; i++)
			{
				if (_iArr[i] > _iArr[iMaxIndex])
					iMaxIndex = i;
			}

			// 현재 값이 가장 작은 값이 아니라면
			if (j != iMaxIndex)
			{
				// 스왑
				int tmp = _iArr[j];
				_iArr[j] = _iArr[iMaxIndex];
				_iArr[iMaxIndex] = tmp;

			}
		}
	}
}