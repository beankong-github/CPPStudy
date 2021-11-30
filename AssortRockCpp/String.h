#pragma once

// 문자열 길이
int My_wcslen(const wchar_t* _spString);

// 문자열 복사
void My_wmemcpy(const wchar_t* _spTo, const wchar_t* _spFrom);

// 문자열 결합
wchar_t* My_wcsncat(const wchar_t* _spTarget, const wchar_t* _spAdd, int _count);

// 문자열 비교
int My_wcascmp(const wchar_t* _spTarget, const wchar_t* _spAdd);

