#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3_3 ������

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

class MiddleDerivedTwo :virtual public Base				// �������� ���� Base�� 2�� ��ӵǾ� 2���� ȣ�� �� �����Ǵ� ���� ����
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
	cout << ".........��ü���� ��..........." << endl;
	LastDerived Idr;
	cout << "��ü���� ��..........." << endl;
	Idr.ComplexFunc();

	// * ��°�� *
	// .........��ü���� ��...........
	// Base Constructor
	// MiddleDerivedOne Constructor
	// MiddleDerivedTwo Constructor
	// LastDerived Constructor
	// .........��ü���� ��...........
	// BaseOne
	// MiddleDerivedOne
	// BaseOne
	// MiddleDerivedTwo
	// BaseOne

	return 0;
}