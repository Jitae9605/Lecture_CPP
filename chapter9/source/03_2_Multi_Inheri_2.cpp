#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3_2 ���߻���� ��ȣ��
// ��¿�� ���°�� ���� �����ϰ�� ������� �ʴ°� ����

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
		BaseOne::SimpleFunc();		// �Լ��̸��� ������� Ŭ������ �����������
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	// * ��°�� *
	// BaseOne
	// BaseTwo

	return 0;
}