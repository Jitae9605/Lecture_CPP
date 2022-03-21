#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

// 2_2 virtual �Լ��� ����
// virtual�� �����ϸ� virtual���̺��� �����Ϸ��� ������� �������̵��� �Լ�(virtual�� �ƴ�)�� ã�Ƽ� ���̺� �����ϰ� ȣ��Ǹ� �̸� ���� 
// ��, �ſ� ������(���̺� ����, ã�Ƽ� ���̺� ���, �����Ҷ��� ���̺�� ���� �����ϰ� ���ƿ;���)
// 
// * ���� *
// �����Լ��� �θ� Ŭ�������� ��ӹ��� Ŭ�������� �������� ������ ����ϰ� �����س��� �Լ�
// �Ļ� Ŭ�������� �������ϸ� ������ ���ǵǾ��� ������� ��� ���Ӱ� ���ǵ� ������ ��ü��.


class Base 
{
public:
	virtual void func1()					// �����Լ�ȭ - �������̵��� �Լ�(�ڽ�Ŭ������ ���� �̸��� �Լ�)�� ȣ���
	{
		cout << "Base::func1()" << endl;
	}

	virtual void func2()					// �����Լ�ȭ - �������̵��� �Լ�(�ڽ�Ŭ������ ���� �̸��� �Լ�)�� ȣ���
	{
		cout << "Base::func2()" << endl;
	}

	void func3() 
	{
		cout << "Base::func3()" << endl;
	}
};

class Derived : public Base 
{
public:
	void func1()							// �������̵��� �Լ�
	{
		cout << "Derived::func1()" << endl;
	}

	void func2()							// �������̵��� �Լ� 
	{
		cout << "Derived::func2()" << endl;
	}

	void func3()							// �������̵��� �Լ� 
	{
		cout << "Derived::func3()" << endl;
	}

	void func4() 
	{
		cout << "Derived::func4()" << endl;
	}
};

int main(void) 
{
	Base* p1 = new Derived();

	p1->func1();		// Base�� func1, func2�� virtual �� ����Ǿ� ����
	p1->func2();
	p1->func3();

	// * ��°�� *
	// Derived::func1()
	// Derived::func2()
	// Base::func3()

	return 0;
}