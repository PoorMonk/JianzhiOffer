// 0302Duplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
using namespace std;

int CountRange(const int* numbers, int length, int start, int end);

int GetDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;
	// 二分查找
	while (start <= end)
	{
		int middle = start + (end - start) / 2;
		int count = CountRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				return -1;
			}
		}

		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}

	return -1;
}

void Test(const int* numbers, int length)
{
	int result = GetDuplication(numbers, length);
	if (result == -1)
	{
		cout << "Dont have duplication." << endl;
	}
	else
	{
		cout << "duplication number is: " << result << endl;
	}
}

int main()
{
	//int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	//int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	//int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	//int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	//int numbers[] = { 1, 1 };
	//int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	//int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int* numbers = nullptr;
	//Test(numbers, 8);
	//Test(numbers, 9);
	//Test(numbers, 2);
	//Test(numbers, 7);
	//Test(numbers, 6);
	Test(numbers, 0);

	return 0;
}

// 计算范围内数字出现的次数，比如1-4，如果超过4次说明1-4之间有重复的数字
int CountRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] >= start && numbers[i] <= end)
		{
			++count;
		}
	}

	return count;
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
