#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

// 2_2 virtual 함수의 이해
// virtual을 선언하면 virtual테이블을 컴파일러가 만든다음 오버라이딩된 함수(virtual이 아닌)를 찾아서 테이블에 저장하고 호출되면 이를 실행 
// 즉, 매우 느리다(테이블 생성, 찾아서 테이블에 등록, 실행할때도 테이블로 가서 실행하고 돌아와야함)
// 
// * 개념 *
// 가상함수는 부모 클래스에서 상속받을 클래스에서 재정의할 것으로 기대하고 정의해놓은 함수
// 파생 클래스에서 재정의하면 이전에 정의되었던 내용들은 모두 새롭게 정의된 내용들로 교체됨.


class Base 
{
public:
	virtual void func1()					// 가상함수화 - 오버라이딩된 함수(자식클래스의 같은 이름의 함수)가 호출됨
	{
		cout << "Base::func1()" << endl;
	}

	virtual void func2()					// 가상함수화 - 오버라이딩된 함수(자식클래스의 같은 이름의 함수)가 호출됨
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
	void func1()							// 오버라이딩된 함수
	{
		cout << "Derived::func1()" << endl;
	}

	void func2()							// 오버라이딩된 함수 
	{
		cout << "Derived::func2()" << endl;
	}

	void func3()							// 오버라이딩된 함수 
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

	p1->func1();		// Base의 func1, func2는 virtual 이 선언되어 있음
	p1->func2();
	p1->func3();

	// * 출력결과 *
	// Derived::func1()
	// Derived::func2()
	// Base::func3()

	return 0;
}