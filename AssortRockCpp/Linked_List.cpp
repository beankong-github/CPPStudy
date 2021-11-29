#include <iostream>
#include <assert.h>

#include "Linked_List.h"

// 맨 뒤에 추가
void push_back(tList* _pList, int _iData)
{
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	
	// 할당에 실패하면 함수를 탈출한다. 
	if (pNewNode == NULL) // if(!pNewNode)
		return;
	
	// 새 노드 초기화
	pNewNode->iData = _iData;
	pNewNode->pNextNode = nullptr;	

	// 1. 요소가 0개일 떄
	if (_pList->pHeadNode == nullptr)
	{
		_pList->pHeadNode = pNewNode;
		_pList->pTailNode = pNewNode;
	}

	// 2. 요소가 1개 이상일 때
	else
	{
		// 맨 마지막 요소의 다음 노드로 새 요소를 연결한다.
		(_pList->pTailNode)->pNextNode = pNewNode;
		
		// 테일 노드가 새 요소를 가르키게 한다.
		_pList->pTailNode = pNewNode;
	}

	// 총 요소 개수 1 증가
	++_pList->iCurCount;
}

// 맨 앞에 추가
void push_front(tList* _pList, int _iData)
{
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));

	// 할당에 실패하면 함수를 탈출한다. 
	if (pNewNode == NULL) // if(!pNewNode)
		return;

	// 새 노드 초기화
	pNewNode->iData = _iData;
	pNewNode->pNextNode = nullptr;

	// 1. 요소가 0개일 떄
	if (_pList->pHeadNode == nullptr)
	{
		printf("빈 리스트입니다. PUSH_BACK을 사용하십시오.");
	}	
	// 2. 요소가 1개 이상일 때
	else
	{
		pNewNode->pNextNode = _pList->pHeadNode;
		_pList->pHeadNode = pNewNode;
	}

	// 총 요소 개수 1 감소
	--_pList->iCurCount;
}


// 맨 뒤의 요소 삭제
int pop_back(tList* _pList)
{
	// 요소가 0개 일때
	if (_pList->pTailNode == nullptr)
		return 0;
	else
	{
		tNode* tTmpNode = _pList->pTailNode;
		int iData = (_pList->pTailNode)->iData;
		free(_pList->pTailNode);
		
		tNode* tCurNode = _pList->pHeadNode;
		while ()
		{

		}
	}
	
	return 0;
}

// 맨 앞의 요소 삭제
int pop_front(tList* _pList)
{
	// 요소가 0개 일 때
	if (_pList->pHeadNode == nullptr)
		return 0;
	
	// 요소가 1개 일 때
	else if (_pList->pHeadNode == _pList->pTailNode)
	{ 
		// 임시 노드에 삭제할 노드 정보를 담는다.
		int iData = _pList->pHeadNode->iData;

		free(_pList->pHeadNode);
	
		_pList->pHeadNode = _pList->pTailNode = nullptr;
		
		return iData;
	}

	// 나머지
	else
	{
		// 임시 노드에 삭제할 노드 정보를 담는다.
		tNode tTmpNode;
		tTmpNode.iData = _pList->pHeadNode->iData;
		tTmpNode.pNextNode = _pList->pHeadNode->pNextNode;
		
		// 노드 삭제
		free(_pList->pHeadNode);

		// 해드 노드가 가르킬 주소 전달
		_pList->pHeadNode = tTmpNode.pNextNode;

		// 총 요소 개수 1 감소
		--_pList->iCurCount;

		return tTmpNode.iData;
	}
	
	return 0;
}

// 리스트 삭제
void release(tList* _pList)
{}