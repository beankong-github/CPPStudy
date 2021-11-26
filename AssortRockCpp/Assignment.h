#pragma once

// 삼각형으로 별찍기
void CreateStar(int, int);	// 최대 별 개수, 방향

// 버블 정렬
void Bubble(int* _pArr, int _iCount, int _iDir); // 배열 주소, 배열 크기, 정렬 방향

// 삽입 정렬
void Insert(int* _pArr, int _iCount, int _iDir);

// 퀵 정렬
void Quick(int* _pArr, int _iCount, int _iDir);

// 랜덤 배열 생성
void RandomArray(int* _pArr, int _iCount, int _iMin, int _iMax); // 배열 주소, 배열 크기, 최소값, 최대값