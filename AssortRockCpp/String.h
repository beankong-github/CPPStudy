#pragma once

// 문자열 길이
int My_wcslen(const wchar_t* _spString);

// 문자열 복사
int My_wmemcpy(wchar_t* _dest, size_t destSize, const wchar_t* _src, size_t count);

// 문자열 결합
wchar_t* My_wcsncat(const wchar_t* _spTarget, const wchar_t* _spAdd, int _count);

// 문자열 비교
int My_wcscmp(const wchar_t* _spString1, const wchar_t* _spString2);

