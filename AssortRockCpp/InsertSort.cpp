#include <iostream>

void Insert(int* _pArr, int _iCount, int _iDir)
{
	int i, j;

	for (i = 1; i < _iCount; i++)
	{
		int key = _pArr[i];

		// 오름차순 정렬
		if (_iDir == 1)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (_pArr[j] > key)
				{
					//밀기
					_pArr[j + 1] = _pArr[j];
				}
				else
					break;
			}

			// 키 값 넣기
			_pArr[j + 1] = key;
		}

		// 내림차순 정렬
		else if (_iDir == -1)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (_pArr[j] < key)
				{
					//밀기
					_pArr[j + 1] = _pArr[j];
				}
				else
					break;
			}
			// 키 값 넣기
			_pArr[j + 1] = key;

		}
	}

}