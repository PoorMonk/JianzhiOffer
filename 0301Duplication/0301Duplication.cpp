// 0301Duplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
using namespace std;

/*
如果数组中没有重复数字，由于所有数字都在0-n之间，所以一定是每个下标对应相应的数字 a[0]=0,a[1]=1;
如果有重复数字：
从a[0]开始，比较a[0]和所对应的数字a[a[0]]是否一致，不一致则交换数字，再重新比较，直到找到重复的数字为止。
*/

bool Duplication(int arr[], int length, int* duplication)
{
	if (arr == nullptr)
	{
		return false;
	}

	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < 0 || arr[i] >= length)
		{
			return false;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*duplication = arr[i];
				return true;
			}

			int temp = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp;
		}
	}

	return false;
}

void Test(int* arr, int length, int* duplication)
{
	bool isHas = Duplication(arr, length, duplication);
	if (isHas)
	{
		cout << "duplication number is: " << *duplication << endl;
	}
	else
	{
		cout << "Dont have duplication." << endl;
	}
}

int main()
{
	//int numbers[] = { 2, 1, 3, 1, 4 };
	//int numbers[] = { 2, 4, 3, 1, 4 };
	//int numbers[] = { 2, 4, 2, 1, 4 };
	//int numbers[] = { 2, 1, 3, 0, 4 };
	//int numbers[] = { 2, 1, 3, 5, 4 };
	int* numbers = nullptr;
	int duplication = -1;
	Test(numbers, 5, &duplication);


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
