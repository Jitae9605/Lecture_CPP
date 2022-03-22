#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. 다중상속
// 어쩔수 없는경우 등을 제외하고는 사용하지 않는게 좋다

class BaseOne
{
public:
	void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
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