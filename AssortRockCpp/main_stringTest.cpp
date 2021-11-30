#include <iostream>
#include "String.h"

int main()
{
	const wchar_t* szpTest1 = L"abc한글";
	const wchar_t* szpTest2 = L"이좋아def";


	int length1 =  My_wcslen(szpTest1);
	int length2 =  My_wcslen(szpTest2);

	wchar_t* wcsResult= My_wcsncat(szpTest1, szpTest2, 12);
	free(wcsResult);

}