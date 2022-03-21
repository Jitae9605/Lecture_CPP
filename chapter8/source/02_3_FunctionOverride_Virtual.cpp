#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

// 2_3_가상함수의 원리
// !!! 가상함수가 호출되면 포인터의 자료형을 기반으로 호출대상을 결정하지 않고 [ 포인터 변수가 실제로 가리키는 객체 ]를 참조하여 호출의 대상을 결정 !!!

class First
{
public:
	virtual void MyFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};


int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();	// virtual 함수 - 포인터의 자료형이 아닌 포인터 변수가 실제로 가리키고있는 객체를 기반으로 호출대상(함수)결정
	sptr->MyFunc();	// virtual 함수 - 포인터의 자료형이 아닌 포인터 변수가 실제로 가리키고있는 객체를 기반으로 호출대상(함수)결정
	tptr->MyFunc();	// virtual 함수 - 포인터의 자료형이 아닌 포인터 변수가 실제로 가리키고있는 객체를 기반으로 호출대상(함수)결정

	delete tptr;

	// * 출력결과 *
	// ThirdFunc
	// ThirdFunc
	// ThirdFunc

	return 0;
}