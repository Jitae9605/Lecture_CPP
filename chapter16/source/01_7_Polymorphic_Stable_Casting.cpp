#include<iostream>
using namespace std;

//1_7.vritual�� �ִ� �θ�Ŭ�������� dynamic�� ����ȴ�.

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
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// ���������� ���� ����ȯ�� �õ��ϸ� dynamic_cast�� NULL�� ��ȯ�Ѵ�.
	if (comPtr == NULL)
		cout << "�� ��ȯ ����" << endl;
	else
		comPtr->ShowSimpleInfo();

	return 0;
}