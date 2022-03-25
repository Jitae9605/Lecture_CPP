#include<iostream>
using namespace std;

//1_7.vritual이 있는 부모클래스로의 dynamic은 혀용된다.

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// 안정적이지 못한 형변환을 시도하면 dynamic_cast는 NULL을 반환한다.
	if (comPtr == NULL)
		cout << "형 변환 실패" << endl;
	else
		comPtr->ShowSimpleInfo();

	return 0;
}