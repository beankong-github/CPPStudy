#pragma once


struct tNode
{
	int		iData;
	tNode* pNextNode;
};

struct tList
{
	tNode* pHeadNode;
	tNode* pTailNode;
	int     iCurCount;
};



void push_back(tList* _pList, int _iData);
void push_front(tList* _pList, int _iData);

int pop_back(tList* _pList);
int pop_front(tList* _pList);



void release(tList* _pList);