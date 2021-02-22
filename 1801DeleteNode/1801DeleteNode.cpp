// 1801DeleteNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。

#include <iostream>
#include "../Utilities/List.h"
using namespace std;

#pragma comment(lib, "Utilities.lib")

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (pHead == nullptr || pToBeDeleted == nullptr)
	{
		return;
	}

	// 要删除的节点不是尾节点
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == pToBeDeleted)	// 链表只有一个节点
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pHead = nullptr;
	}
	else //要删除的节点是尾节点
	{
		ListNode* pNode = *pHead;
		while (pNode && pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = nullptr;

		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void Test(ListNode* pHead, ListNode* pNode)
{
	cout << "The original list is: " << endl;
	PrintList(pHead);

	cout << "The node to be deleted is: " << endl;
	PrintListNode(pNode);

	DeleteNode(&pHead, pNode);

	cout << "The result list is: " << endl;
	PrintList(pHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
	Test(nullptr, nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
