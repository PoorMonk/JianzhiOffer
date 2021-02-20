// ReplaceSpaces.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <iostream>

using namespace std;

void ReplaceSpaces(char* str, int length);
void Test(char str[], int length);

int main()
{
	const int length = 100;
	//char str[length] = "Hello World";
	//char str[length] = " HelloWorld";
	//char str[length] = "HelloWorld ";
	//char str[length] = "Hello  World";
	//char str[length] = "HelloWorld";
	//char str[length] = "";
	//char str[length] = " ";
	char str[length] = "   ";
	Test(str, length);
	Test(nullptr, length);

	return 0;
}

// length表示字符串的总长度，能容纳扩充后的长度
void ReplaceSpaces(char* str, int length)
{
	if (str == nullptr || length <= 0)
	{
		return;
	}

	int originIndex = 0, newIndex = 0;
	int spaceCount = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		originIndex++;
		if (str[i] == ' ')
		{
			spaceCount++;
		}
	}

	newIndex = originIndex + spaceCount * 2;
	if (newIndex > length)
	{
		return;
	}

	while (originIndex >= 0 && originIndex < newIndex)
	{
		if (str[originIndex] != ' ')
		{
			str[newIndex--] = str[originIndex];
		}
		else
		{
			// 替换成%20
			str[newIndex--] = '0';
			str[newIndex--] = '2';
			str[newIndex--] = '%';
		}

		originIndex--;
	}
}

void Test(char str[], int length)
{
	ReplaceSpaces(str, length);
	if (str)
	{
		cout << str << endl;
	}
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
