#include <iostream>
#include "String.h"

int main()
{
	const wchar_t* szpTest1 = L"a";
	const wchar_t* szpTest2 = L"a";

	int length1 =  My_wcslen(szpTest1);
	int length2 =  My_wcslen(szpTest2);

	wchar_t* ncatResult= My_wcsncat(szpTest1, szpTest2, 12);
	free(ncatResult);
	
	int cmpResult = My_wcscmp(szpTest1, szpTest2);
}