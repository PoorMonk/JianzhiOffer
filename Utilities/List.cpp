#include "pch.h"
#include "List.h"
#include <iostream>
using namespace std;

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		cout << "Error to connect two nodes" << endl;
		return;
	}

	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		cout << "The node is nullptr" << endl;
	}
	else
	{
		cout << "The key in node is " << pNode->m_nValue << endl;
	}
}

void PrintList(ListNode* pHead)
{
	cout << "PrintList starts." << endl;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}

	cout << endl;
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

