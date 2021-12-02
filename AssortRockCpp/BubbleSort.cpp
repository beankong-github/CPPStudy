#include <iostream>
#include <time.h>

void Bubble(int* _pArr, int _iCount, int _iDir) // 배열 주소, 배열 크기, 정렬 방향
{
	// 포인터 초기화
	int* front = nullptr;
	int* back = nullptr;

	// 정방향 버블 정렬
	if (_iDir == 1)
	{
		for (int i = 0; i < _iCount-1; ++i)
		{
			bool bSwap = false;

			for (int j = 0; j < _iCount-(i+1); ++j)
			{
				front = _pArr + j;
				back = front + 1;
				
				if (*front > *back)
				{
					// 교환
					int tmp = *front;
					*front = *back;
					*back = tmp;

					bSwap = true;
				}
			}

			if (!bSwap)
				break;
		}
	}

	// 역방향 버블 정렬
	else if (_iDir == -1)
	{
		for (int i = 0; i < _iCount - 1; ++i)
		{
			bool bSwap = false;

			for (int j = 0; j < _iCount - (i + 1); ++j)
			{
				front = _pArr + j;
				back = front + 1;

				if (*front < *back)
				{
					// 교환
					int tmp = *front;
					*front = *back;
					*back = tmp;

					bSwap = true;
				}
			}
			if (!bSwap)
				break;
		}
	}


	return;
}
