#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector()
: m_pData(nullptr)
, m_iCount(0)
, m_iCapacity(2)
{
	m_pData = new int(m_iCapacity) // new : 클래스 동적할당 키워드
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

	// 기존에 입력된 데이터를 새로운 공간으로 복사

	// 기존 공간 해제

	// 동적 배열의 포인터가 새로운 공간의 주소를 가르킴

	// 최대 개수를 _iSize로 갱신한다

}