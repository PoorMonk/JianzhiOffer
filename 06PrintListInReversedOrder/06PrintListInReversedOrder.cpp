// 06PrintListInReversedOrder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include "../Utilities/List.h"
#include <iostream>
#include <stack>
using namespace std;

#pragma comment(lib, "Utilities.lib")

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->m_nValue << " ";
		nodes.pop();
	}

	cout << endl;
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead)
	{
		ListNode* pNode = pHead;

		if (pNode->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pNode->m_pNext);
		}

		cout << pNode->m_nValue << " ";
	}
}

void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	cout << endl;
	PrintListReversingly_Recursively(pHead);
}

void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	printf("\nTest3 begins.\n");

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
