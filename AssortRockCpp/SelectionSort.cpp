#include <iostream>

void Selection(int* _iArr, int _iCount, int _iDir)
{
	// 오름차순
	if (_iDir == 1)
	{
		for (int j = 0; j < _iCount; j++)
		{
			int iMinIndex = j ;

			for (int i = j + 1; i < _iCount - j; i++)
			{
				if (_iArr[i] < _iArr[iMinIndex])
					iMinIndex = i;
			}

			if (j != iMinIndex)
			{
				int tmp = _iArr[j];
				_iArr[j] = _iArr[iMinIndex];
				_iArr[iMinIndex] = tmp;

			}
		}
	}

	// 내림차순
	else if (_iDir == -1)
	{
	}
}