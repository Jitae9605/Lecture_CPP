#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

// 2_3_�����Լ��� ����
// !!! �����Լ��� ȣ��Ǹ� �������� �ڷ����� ������� ȣ������ �������� �ʰ� [ ������ ������ ������ ����Ű�� ��ü ]�� �����Ͽ� ȣ���� ����� ���� !!!

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

	fptr->MyFunc();	// virtual �Լ� - �������� �ڷ����� �ƴ� ������ ������ ������ ����Ű���ִ� ��ü�� ������� ȣ����(�Լ�)����
	sptr->MyFunc();	// virtual �Լ� - �������� �ڷ����� �ƴ� ������ ������ ������ ����Ű���ִ� ��ü�� ������� ȣ����(�Լ�)����
	tptr->MyFunc();	// virtual �Լ� - �������� �ڷ����� �ƴ� ������ ������ ������ ����Ű���ִ� ��ü�� ������� ȣ����(�Լ�)����

	delete tptr;

	// * ��°�� *
	// ThirdFunc
	// ThirdFunc
	// ThirdFunc

	return 0;
}