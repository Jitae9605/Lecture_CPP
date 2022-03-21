#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5. 참조자

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }	// 가상함수
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();			// 가상함수

	Second& sref = obj;			// Second형 참조자 sref가 Third형 객체 obj를 참조함
	sref.FirstFunc();			// 참조자의 자료형을 기준으로 함수의 사용이 가능(= Second에 정의된 함수 + 상속받은 함수만 사용가능)
	sref.SecondFunc();
	sref.SimpleFunc();			// 가상함수

	First& fref = obj;			// First형 참조자 fref가 Third형 객체 obj를 참조함
	fref.FirstFunc();			// 참조자의 자료형을 기준으로 함수의 사용이 가능(= First에 정의된 함수만 사용가능)
	fref.SimpleFunc();			// 가상함수

	// * 출력결과 *
	// FirstFunc()
	// SecondFunc()
	// ThirdFunc()
	// Third's SimpleFunc()
	// FirstFunc()
	// SecondFunc()
	// Third's SimpleFunc()
	// FirstFunc()
	// Third's SimpleFunc()
	
	return 0;
}