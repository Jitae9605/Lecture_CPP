#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 3. ���߻��
// ��¿�� ���°�� ���� �����ϰ�� ������� �ʴ°� ����

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

	// * ��°�� *
	// BaseOne
	// BaseTwo

	return 0;
}