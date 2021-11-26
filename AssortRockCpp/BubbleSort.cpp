#include <iostream>
#include <time.h>

void RandomArray(int* _pArr, int _iCount,int _iMin, int _iMax) // 배열 주소, 배열 크기, 최소값, 최대값
{
	srand(time(nullptr));

	for (int i = 0; i < _iCount; i++)
	{
		// _iMan 이상 _iMax 이하의 랜덤 수 생성
		int random = (rand() % ((_iMax - _iMin) + 1));
		random += _iMin;

		// 랜덤 수 배열에 대입
		*(_pArr + i) = random;
	}

}

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
