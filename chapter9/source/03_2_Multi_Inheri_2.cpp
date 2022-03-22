#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3_2 다중상속의 모호성
// 어쩔수 없는경우 등을 제외하고는 사용하지 않는게 좋다

class BaseOne
{
public:
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		BaseOne::SimpleFunc();		// 함수이름이 같은경우 클래스를 지정해줘야함
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	// * 출력결과 *
	// BaseOne
	// BaseTwo

	return 0;
}