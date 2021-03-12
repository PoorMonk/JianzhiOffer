// 23EntryNodeInListLoop.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？
/*
1 用快慢两个指针来判断是否有环，如果有环两个指针一定会相遇，找到相遇的节点，遍历这个节点来计算环的长度l，再从头节点开始，让一个指针先走l步，
再同时让两个指针走，相遇的点即为环的入口点
*/

#include <iostream>
#include "../Utilities/List.h"
using namespace std;

#pragma comment(lib, "Utilities.lib")

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == nullptr)
	{
		return nullptr;
	}

	ListNode* pFast = pSlow->m_pNext;
	while (pSlow != nullptr || pFast != nullptr)
	{
		if (pSlow == pFast)
		{
			return pSlow;
		}

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast)
		{
			pFast = pFast->m_pNext;
		}
	}

	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
	{
		return nullptr;
	}

	int nodesInLoop = 1;
	ListNode* pNode = meetingNode;
	while (pNode->m_pNext != meetingNode)
	{
		pNode = pNode->m_pNext;
		++nodesInLoop;
	}

	pNode = pHead;
	for (int i = 0; i < nodesInLoop; ++i)
	{
		pNode = pNode->m_pNext;
	}

	ListNode* pBehide = pHead;
	while (pNode != pBehide)
	{
		pNode = pNode->m_pNext;
		pBehide = pBehide->m_pNext;
	}

	return pNode;
}

// ==================== Test Code ====================
void Test(const char* testName, ListNode* pHead, ListNode* entryNode)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (EntryNodeOfLoop(pHead) == entryNode)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);

	Test("Test1", pNode1, nullptr);

	DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ConnectListNodes(pNode1, pNode1);

	Test("Test2", pNode1, pNode1);

	delete pNode1;
	pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
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
	ConnectListNodes(pNode5, pNode3);

	Test("Test3", pNode1, pNode3);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
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
	ConnectListNodes(pNode5, pNode1);

	Test("Test4", pNode1, pNode1);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
	ConnectListNodes(pNode5, pNode5);

	Test("Test5", pNode1, pNode5);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

	Test("Test6", pNode1, nullptr);

	DestroyList(pNode1);
}

// Empty list
void Test7()
{
	Test("Test7", nullptr, nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

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
