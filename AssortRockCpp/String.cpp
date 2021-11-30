#include "String.h"
#include <atomic>

// 문자열 길이 구하기
int My_wcslen(const wchar_t* _spString)
{
	int counter = 0;
	wchar_t curChar = *_spString;

	while (true)
	{
		curChar = *(_spString + counter);
		
		if ('\0' == curChar)
			break;
		
		++counter;
	}

	return counter;
}

// 문자열 복사
void My_wmemcpy(const wchar_t* _spTo, const wchar_t* _spFrom)
{
	
}

// 문자열 결합
wchar_t* My_wcsncat(const wchar_t* _spTarget, const wchar_t* _spAdd, int _count)
{
	int iTargetLen = My_wcslen(_spTarget);
	int iAddLen = My_wcslen(_spAdd);
	wchar_t* wcsNew = (wchar_t*)malloc(sizeof(wchar_t) * _count);
	int i, j;

	if (wcsNew == nullptr)
		return nullptr;

	if (iTargetLen + iAddLen >= _count)
		return nullptr;

	
	for (i = 0; i < iTargetLen; i++)
	{
		wcsNew[i] = _spTarget[i];
	}

	for (j = 0; j < iAddLen; j++)
	{
		wcsNew[i + j] = _spAdd[j];
	}

	wcsNew[i + j] = L'\0';
	
	return wcsNew;

}

// 문자열 비교
int My_wcascmp(const wchar_t* _spTarget, const wchar_t* _spAdd)
{

	return 0;
}

