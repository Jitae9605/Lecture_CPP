#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4. ����Ҹ���
// virtual �Լ��� ����� �Ҹ���

// 1)
class First_1
{
private:
	char* strOne;

public:
	First_1(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	
	~First_1()
	{
		cout << "~First_1()" << endl;
		delete[]strOne;
	}
};

class Second_1 :public First_1
{
private:
	char* strTwo;
	
public:
	Second_1(const char* str1,const char* str2) :First_1(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}

	~Second_1()
	{
		cout << "~Second()_1" << endl;
		delete[]strTwo;
	}
};

// 2)
class First_2
{
private:
	char* strOne;

public:
	First_2(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}

	virtual ~First_2()						// ����Ҹ��� ����
	{
		cout << "~First_2()" << endl;
		delete[]strOne;
	}
};

class Second_2 :public First_2
{
private:
	char* strTwo;

public:
	Second_2(const char* str1, const char* str2) :First_2(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}

	~Second_2()
	{
		cout << "~Second_2()" << endl;
		delete[]strTwo;
	}
};

class Third_2 :public Second_2
{
private:
	char* strThree;

public:
	Third_2(const char* str1, const char* str2, const char*str3) : Second_2(str1,str2)
	{
		strThree = new char[strlen(str2) + 1];
	}

	~Third_2()
	{
		cout << "~Third_2()" << endl;
		delete[]strThree;
	}
};

int main(void)
{
	cout << "--------------- < 1) �Ҹ����� ��ȣ�� > -----------------------------" << endl << endl;
	//  1) �Ҹ����� ��ȣ��
	First_1* ptr_1 = new Second_1("simple", "complex");
	delete ptr_1;

	// * ��°�� *
	// ~First_1()
	
	// !!! ����� ���� �� �� �ֵ� ~Second()�� ȣ����� ���ߴ� => �޸� �����߻�

	cout << "--------------- < 2) ���� �Ҹ��� > -----------------------------" << endl << endl;
	//  1) �Ҹ����� ��ȣ��
	First_2* ptr_2 = new Third_2("simple", "complex","mixed");
	delete ptr_2;													// ���� �Ҹ��� ����ȣ���

	// * ��°�� *
	// ~Third_2()
	// ~Second_2()
	// ~First_2()

	return 0;
}