#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_4. 이니셜라이저르릍 통한 성능향상

class AAA
{
private:
	int num;

public:
	AAA(int n = 0) :num(n)
	{
		cout << "AAA(int n=0)" << endl;
	}

	AAA(const AAA& ref) :num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}

	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref):mem(ref) { }
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) { mem = ref; }
};

int main(void)
{
	AAA obj1(12);
	cout << "**********************" << endl;
	BBB obj2(obj1);
	cout << "**********************" << endl;
	CCC obj3(obj1);

	// * 출력결과 *
	// AAA(int n=0)
	// **********************
	// AAA(const AAA & ref)
	// **********************
	// AAA(int n = 0)
	// operator=(const AAA & ref)

	return 0;
}