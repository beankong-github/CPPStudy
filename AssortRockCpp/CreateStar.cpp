#include <iostream>

void CreateStar(int _iMaxStar, int _iDir)
{
	switch (_iDir)
	{
		// 정삼각형 출력
	case 1:
		for (int i = 0; i < _iMaxStar; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				printf("*");
			}

			printf("\n");
		}
		break;

		// 역삼각형 출력
	case -1:
		for (int i = 0; i < _iMaxStar; ++i)
		{
			for (int j = _iMaxStar - i; j > 0; --j)
			{
				printf("*");
			}

			printf("\n");
		}
		break;
	}

	return;
}