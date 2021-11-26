#include "Dynamic_Array.h"

#include <iostream>
#include <assert.h>


// 동적 배열 초기화
void InitArr(tArr* _pArr)
{
	// 1. 배열의 크기를 정한다.
	_pArr->iMaxCount = 2;

	// 2. 배열의 크기만큼 동적할당한다.
	_pArr->pInt = (int*)malloc(sizeof(int) * _pArr->iMaxCount);

	// 3. 배열의 현재 인덱스를 0으로 초기화한다.
	_pArr->iCurCount = 0;
}


void FreeArr(tArr* _pArr)
{
	// 동적 할당 해제
	free(_pArr->pInt);

	// 데이터 초기화
	_pArr->pInt = nullptr;
	_pArr->iCurCount = 0;
	_pArr->iMaxCount = 0;
}


void Resize(tArr* _pArr, int _iMaxCount) 
{
	// 기존의 동적 배열보다 더 작은 값이 Max로 들어오면 크러시
	if (_pArr->iMaxCount >= _iMaxCount)
		assert(nullptr);

	// 새로운 공간 할당 받기
	int* pNewArr = (int*)malloc(sizeof(int) * _iMaxCount);

	// 기존 동적 배열의 값 복사해오기
	for (int i = 0; i < _pArr->iCurCount; ++i)
	{
		pNewArr[i] = _pArr->pInt[i];
	}

	_pArr->pInt = pNewArr;
	_pArr->iMaxCount = _iMaxCount;
}

void Push(tArr* _pArr, int _data)
{
	// 만약 현재 배열이 꽉 차있다면 배열을 2배 확장해서 데이터를 추가한다.
	if (_pArr->iCurCount >= _pArr -> iMaxCount)
		Resize(_pArr, _pArr->iMaxCount * 2);
	
	_pArr->pInt[++_pArr->iCurCount] = _data;
}


int Get(tArr* _pArr, int _iIndex)
{
	// 인덱스가 배열의 최대 인덱스를 초과하거나 음수일 때 크러시
	if (_iIndex > _pArr->iMaxCount || _iIndex < 0)
		assert(nullptr);

	return _pArr->pInt[_iIndex];
}