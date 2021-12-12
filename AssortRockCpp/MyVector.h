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


	// ==========================================================
	//							반복자
	// ==========================================================
	class Iterator;

	// 첫번째 데이터 주소를 가르키는 반복자 반환 함수
	Iterator begin();

	// 마지막 + 1 주소를 가르키는 반복자 반환 함수 
	Iterator end();


public:
	// 생성자
	MyVector();

	// 소멸자
	~MyVector();

	// 반복자 구현
	class Iterator
	{
	private:
		MyVector* m_pArr;
		T* m_pTarget;
	
	public:
		Iterator& operator ++()
		{
			// 만약 현재 이터레이터가 이미 end 이터레이터(nullptr)이면 assert
			assert(m_pTarget);
			
			// 현재 이터레이터 다음이 end 이터레이터이면 다음 이터레이터를 end 이터레이터(nullptr)로 설정

			// 그 외의 경우

		}

		Iterator operator ++(int)
		{

		}

		Iterator& operator--()
		{}

		Iterator& operator--(int)
		{}

		T& operator *()
		{}

		bool operator ==(const Iterator& _other)
		{}

		bool operator !=(const Iterator& _other)
		{}

	public:
		Iterator();
		Iterator(MyVector<T>*_pArr, T* m_pTarget, int _iDataCount);
		~Iterator();
	};
};


// ==========================================================
//					MyVector 멤버 함수 구현
// ==========================================================


template <typename T>
MyVector<T>::MyVector()
	:m_pData(nullptr),
	m_iCapacity(2),
	m_iCount(0)
{
	m_pData = new T[m_iCapacity];
}

template <typename T>
MyVector<T>::MyVector()
{
	delete[] m_pData;
}

template <typename T>
void MyVector<T>::Push_Back(T _tData)
{
	// 배열이 꽉 차있으면 2배씩 재할당
	if (m_iCount >= m_iCapacity)
		Reserve(m_iCapacity * 2);

	m_pData[m_iCount++] = _tData;
}

template <typename T>
void MyVector<T>::Reserve(int _iSize)
{
	assert(_iSize >= m_iCapacity);

	// 새로 이전 할 공간 생성
	T* newSpace = (T*)malloc(sizeof(T) * _iSize);

	// 기존에 입력된 데이터를 새로운 공간으로 복사
	for (int i = 0; i < m_iCount; i++)
	{
		newSpace + i = GetData(i);
	}

	// 기존 공간 해제
	delete[] m_pData;

	// 동적 배열의 포인터가 새로운 공간의 주소를 가르킴
	m_pData = newSpace;

	// 최대 개수를 _iSize로 갱신한다
	m_iCapacity = _iSize;
}

template<typename T>
void MyVector<T>::Resize(int _iCount)
{
}


template<typename T>
typename MyVector<T>::Iterator MyVector<T>::begin()
{
	return Iterator(this, this->m_pData, this->m_iCount);


}

template<typename T>
typename MyVector<T>::Iterator MyVector<T>::end()
{
	return Iterator(this, nullptr, this->m_iCount);
}


// ==========================================================
//					Iterator 멤버 함수 구현
// ==========================================================

template<typename T>
MyVector<T>::Iterator::Iterator()
	: m_pArr(nullptr),
	m_pTarget(nullptr)
{
}

template<typename T>
MyVector<T>::Iterator::Iterator(MyVector* _pArr, T* _pTarget, int _iDataCount)
	: m_pArr(_pArr),
	m_pTarget(_pTarget)
{
}

template<typename T>
MyVector<T>::Iterator::~Iterator()
{
}