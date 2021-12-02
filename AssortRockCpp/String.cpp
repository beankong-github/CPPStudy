#include "String.h"
#include <atomic>
#include <cassert>

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
int My_wmemcpy(wchar_t* _dest, size_t destSize, const wchar_t* _src, size_t count)
{
	if (count > destSize || count < 0)
		return 0;

	for (size_t i = 0; i < count; i++)
	{
		_dest[i] = _src[i];
	}

}

// 문자열 복사2
int My_wmemmove(wchar_t* _dest, size_t _destSize, const wchar_t* _src, size_t count)
{
	if (count > _destSize || count < 0)
		return 0;

	wchar_t* srcCpy = (wchar_t*)malloc(sizeof(wchar_t) * (count + 1));

	for (int i = 0; i < count; i++)
	{
		srcCpy[i] = _src[i];
		srcCpy[i+1] = L'\0';
	}

	for (int i = 0; i < count; i++)
	{
		_dest[i] = srcCpy[i];
	}

}

// 문자열 결합
wchar_t* My_wcsncat(wchar_t* _spTarget, const wchar_t* _spAdd, int _count)
{
	int iTargetLen = My_wcslen(_spTarget);
	int iAddLen = My_wcslen(_spAdd);
	int i, j = 0;

	if (iTargetLen + iAddLen >= _count)
		assert(nullptr);

	
	for (i = 0; i <= iAddLen; i++)
	{
		_spTarget[iTargetLen + i] = _spAdd[i];
	}

	return _spTarget;
}

// 문자열 비교
int My_wcscmp(const wchar_t* _spString1, const wchar_t* _spString2)
{
	int i = 0;
	wchar_t wcChar1 = _spString1[i];
	wchar_t wcChar2 = _spString2[i];

	while (wcChar1 != '\0' || wcChar2 != '\0')
	{
		// 두 문자가 같을 때
		if (wcChar1 == wcChar2)
		{
			++i;
			wcChar1 = _spString1[i];
			wcChar2 = _spString2[i];
			continue;
		}

		// 두 문자가 다를 때
		if (wcChar1 > wcChar2)
			return 1;
		
		else if (wcChar1 < wcChar2)
			return -1;
	}

	return 0;
}

