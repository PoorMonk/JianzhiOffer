// 01_AssignmentOperator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& Other);
	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
}

#if false
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		delete[] m_pData;
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}

	return *this;
}
#else
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString tempStr(str);

		char* pTempChar = m_pData;
		m_pData = tempStr.m_pData;
		tempStr.m_pData = pTempChar;
	}

	return *this;
}
#endif

void CMyString::Print()
{
	cout << "CMyString: " << m_pData << endl;
}

void Test1()
{
	printf("Test1 begins:\n");

	const char* text = "Hello world";

	CMyString str1(const_cast<char*>(text));
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	const char* text = "Hello world";

	CMyString str1(const_cast<char*>(text));
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	const char* text = "Hello Harkey";

	CMyString str1(const_cast<char*>(text));
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
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
