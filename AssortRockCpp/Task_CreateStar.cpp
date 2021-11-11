#include <iostream>

void CreateStar(int _iMaxStar, int _iDir)
{
	switch (_iDir)
	{
		// 삼각형 모양으로 출력
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

		// 역삼각형 모양으로 출력
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

int main()
{
	CreateStar(5, 1);

	printf("\n");
	CreateStar(5, -1);

	printf("\n");
	CreateStar(3, 1);

	printf("\n");
	CreateStar(3, -1);
}