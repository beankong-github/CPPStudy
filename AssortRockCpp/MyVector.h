#pragma once
#include <assert.h>

// 동적 배열 클래스
template <typename T>
class MyVector
{
	// ==========================================================
	//						 맴버 변수
	// ==========================================================
private:
	T* m_pData;			// 동적 배열의 첫번째 데이터 위치
	int m_iCount;		// 동적 배열에 저장된 데이터 개수
	int m_iCapacity;	// 동적 배열에 할당된 공간의 크기		

public:
	// ==========================================================
	//						 맴버 함수
	// ==========================================================

	// 배열에 저장된 데이터 개수 반환
	int Size() { return m_iCount; }	// 인라인 함수

	// 배열에 할당된 공간 크기 반환
	int Capacity() { return m_iCapacity; }

	// 배열 뒤에 데이터를 추가한다
	void Push_Back(T _tData);

	// 배열의 특정 인덱스의 데이터를 가져온다
	T GetData(int _iIdx)
	{ 
		assert(m_iCount > _iIdx);
		return m_pData[_iIdx];
	}

	// 배열의 특정 인덱스의 데이터를 설정한다
	void SetData(T _tData, int _iIdx) 
	{
		assert(m_iCount > _iIdx);
		m_pData[_iIdx] = _tData;
	}

	// 배열의 공간을 미리 할당받아 놓는다. *예약해둔다
	void Reserve(int _iCount);

	// 배열에 데이터를 넣으며 공간을 확보한다.  
	void Resize(int _iCount);

	// ==========================================================
	//						연산자 오버로딩 
	// ==========================================================

	// []
	// 클래스는 사이즈가 항상 다르므로 cpp 문법에서 []연산자를 이용한 인덱스 접근이 불가능하다.
	// 따라서 연산자 오버로딩을 이용하여 사용자 정의 배열이 일반 배열처럼 사용될 수 있게 한다.
	T& operator [] (int _iIdx)
	{
		return *(m_pData + _iIdx);
	}

	// 반복자

	// 첫번째 데이터 주소를 가르키는 반복자 반환 함수
	
	// 마지막 + 1 주소를 가르키는 반복자 반환 함수 


public:
	// 생성자
	MyVector()
	{}
	// 소멸자
	~MyVector()
	{}

	// 반복자 구현
	class Iterator
	{
	private:
		MyVector* m_pArr;
		T* m_pTarget;
	};

};