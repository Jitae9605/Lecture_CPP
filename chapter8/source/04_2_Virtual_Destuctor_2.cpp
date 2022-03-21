#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4. ����Ҹ���
// virtual �Լ��� ����� �Ҹ���

class Base
{
	int num1;
public:
	Base(int an)
	{
		num1 = an;
		cout << num1 << " : Base ������" << endl;
	}

	virtual ~Base()
	{
		cout << num1 << " : Base �Ҹ���" << endl;
	}

	virtual void func()
	{
		cout << "Base::func()" << endl;
	}
};

class Derived :public Base
{
	int num2;
public:
	Derived(int an1, int an2)
		: Base(an1)
	{
		num2 = an2;
		cout << num2 << " : Derived ������" << endl;
	}

	~Derived()
	{
		cout << num2 << " : Derived �Ҹ���" << endl;
	}

	void func()
	{
		cout << "Derived::func()" << endl;
	}

};

int main(void)
{
	/*
	Base b(1);
	b.func();

	cout << endl;

	Derived d(2, 22);
	d.func();
	*/

	// * ��°�� *
	// 1 : Base ������
	// Base::func()
	// 
	// 2 : Base ������
	// 22 : Derived ������
	// Derived::func()
	// 22 : Derived �Ҹ���
	// 2 : Base �Ҹ���
	// 1 : Base �Ҹ���

	cout << "--------------- ������� ��������" << endl << endl;

	Base* pb = new Derived(3, 33);
	pb->func();
	delete pb;

	// * ��°�� *
	// 3 : Base ������
	// 33 : Derived ������
	// Derived::func()
	// 3 : Base �Ҹ���

	// !!! 33 : Derived �� �Ҹ���� ���� !!!
	// �̸� �ذ��Ϸ��� �Ҹ��ڵ� virtual �����ؾ��� (�ֻ�� �θ𿡰�) = BaseŬ������ ~Base()�� virtual ~Base()�� ����

	// * ������ ��°�� * 
	// 3 : Base ������
	// 33 : Derived ������
	// Derived::func()
	// 33 : Derived �Ҹ���
	// 3 : Base �Ҹ���


	return 0;
}