#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4. 가상소멸자
// virtual 함수로 선언된 소멸자

class Base
{
	int num1;
public:
	Base(int an)
	{
		num1 = an;
		cout << num1 << " : Base 생성자" << endl;
	}

	virtual ~Base()
	{
		cout << num1 << " : Base 소멸자" << endl;
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
		cout << num2 << " : Derived 생성자" << endl;
	}

	~Derived()
	{
		cout << num2 << " : Derived 소멸자" << endl;
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

	// * 출력결과 *
	// 1 : Base 생성자
	// Base::func()
	// 
	// 2 : Base 생성자
	// 22 : Derived 생성자
	// Derived::func()
	// 22 : Derived 소멸자
	// 2 : Base 소멸자
	// 1 : Base 소멸자

	cout << "--------------- 여기까지 문제없음" << endl << endl;

	Base* pb = new Derived(3, 33);
	pb->func();
	delete pb;

	// * 출력결과 *
	// 3 : Base 생성자
	// 33 : Derived 생성자
	// Derived::func()
	// 3 : Base 소멸자

	// !!! 33 : Derived 가 소멸되지 않음 !!!
	// 이를 해결하려면 소멸자도 virtual 선언해야함 (최상단 부모에게) = Base클래스의 ~Base()를 virtual ~Base()로 수정

	// * 삽입후 출력결과 * 
	// 3 : Base 생성자
	// 33 : Derived 생성자
	// Derived::func()
	// 33 : Derived 소멸자
	// 3 : Base 소멸자


	return 0;
}