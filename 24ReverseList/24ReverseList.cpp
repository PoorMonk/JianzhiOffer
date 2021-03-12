// 24ReverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include <iostream>
#include "../Utilities/List.h"
using namespace std;

#pragma comment(lib, "Utilities.lib")

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pReverseHead = nullptr;
	ListNode* pPrev = nullptr;
	ListNode* pNode = pHead;
	ListNode* pNext = nullptr;
	while (pNode)
	{
		pNext = pNode->m_pNext;
		if (pNext == nullptr)
		{
			pReverseHead = pNode;
		}

		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
	printf("The original list is: \n");
	PrintList(pHead);

	ListNode* pReversedHead = ReverseList(pHead);

	printf("The reversed list is: \n");
	PrintList(pReversedHead);

	return pReversedHead;
}

// 输入的链表有多个结点
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

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
	Test(nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();

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
