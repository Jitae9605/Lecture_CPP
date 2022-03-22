#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3_3 가상상속

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc(){cout << "BaseOne" << endl; }
};

class MiddleDerivedOne :virtual public Base
{
public:
	MiddleDerivedOne() : Base()
	{
		cout << "MiddleDerivedOne Constructor" << endl;
	}

	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo :virtual public Base				// 가상상속을 통해 Base가 2번 상속되어 2번씩 호출 및 생성되는 것을 예방
{
public:
	MiddleDerivedTwo() : Base()
	{
		cout << "MiddleDerivedTwo Constructor" << endl;
	}

	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() : MiddleDerivedTwo(), MiddleDerivedOne()
	{
		cout << "LastDerived Constructor" << endl;
	}

	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{
	cout << ".........객체생성 전..........." << endl;
	LastDerived Idr;
	cout << "객체생성 후..........." << endl;
	Idr.ComplexFunc();

	// * 출력결과 *
	// .........객체생성 전...........
	// Base Constructor
	// MiddleDerivedOne Constructor
	// MiddleDerivedTwo Constructor
	// LastDerived Constructor
	// .........객체생성 후...........
	// BaseOne
	// MiddleDerivedOne
	// BaseOne
	// MiddleDerivedTwo
	// BaseOne

	return 0;
}