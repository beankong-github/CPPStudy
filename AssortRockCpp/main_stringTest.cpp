#include <iostream>
#include "String.h"

int main()
{
	wchar_t myString[100] = L"안녕하세요 반갑습니다.";

	const wchar_t* szpTest1 = L"a";
	const wchar_t* szpTest2 = L"김철수 씨";

	int length1 =  My_wcslen(szpTest1);
	int length2 =  My_wcslen(szpTest2);

	
 	wchar_t* ncatResult= My_wcsncat(myString, szpTest2, 100);

	int cmpResult = My_wcscmp(szpTest1, szpTest2);
}