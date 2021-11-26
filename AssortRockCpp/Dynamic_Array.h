#pragma once
struct tArr
{
	int* pInt;			// 동적 배열의 시작 주소
	int  iMaxCount;		// 동적 배열의 최대 인덱스 값
	int  iCurCount;		// 동적 배열의 마지막으로 저장된 데이터의 인덱스 값
};


// 동적 배열 생성(초기화)
void InitArr(tArr* _pArr);

// 동적 배열 할당 해제
void FreeArr(tArr* _pArr);

// 동적 배열 확장
void Resize(tArr* _pArr, int _iMaxCount);

// 값 추가
void Push(tArr* _pArr, int _data);

// 값 가져오기
int Get(tArr* _pArr, int _iIndex);