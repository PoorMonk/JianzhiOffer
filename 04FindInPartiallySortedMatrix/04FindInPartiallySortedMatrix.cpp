// 04FindInPartiallySortedMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>
using namespace std;

bool FindInMatrix(int* matrix, int rows, int cols, int value)
{
	if (matrix == nullptr)
	{
		return false;
	}

	int row = 0;
	int col = cols - 1;

	while (row < rows || col >= 0)
	{
		if (matrix[row * cols + col] == value)
		{
			return true;
		}
		else if (matrix[row * cols + col] > value)
		{
			col--;
		}
		else
		{
			row++;
		}
	}

	return false;
}

void Test(const char* testName, int* matrix, int rows, int columns, int number)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	 
	if (FindInMatrix(matrix, rows, columns, number))
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test1", (int*)matrix, 4, 4, 7);
	Test("Test2", (int*)matrix, 4, 4, 5);
	Test("Test3", (int*)matrix, 4, 4, 1);
	Test("Test4", (int*)matrix, 4, 4, 15);
	Test("Test5", (int*)matrix, 4, 4, 0);
	Test("Test6", (int*)matrix, 4, 4, 16);
	Test("Test7", nullptr, 0, 0, 16);
}

int main()
{
	Test();

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
