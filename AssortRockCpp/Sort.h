#pragma once

// 버블 정렬
void Bubble(int* _pArr, int _iCount, int _iDir); // 배열 주소, 배열 크기, 정렬 방향

// 삽입 정렬
void Insert(int* _pArr, int _iCount, int _iDir);

// 퀵 정렬
void Quick(int* _pArr, int _iCount, int _iDir);

// 선택 정렬
void Selection(int* _iArr, int _iCount, int _iDir);

// 병합 정렬
void Merge(int* _iArr, int _iCounter, int _iDir);

// 랜덤 배열 생성
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