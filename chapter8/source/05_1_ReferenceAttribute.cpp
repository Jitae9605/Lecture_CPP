#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5. ������

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }	// �����Լ�
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
	obj.SimpleFunc();			// �����Լ�

	Second& sref = obj;			// Second�� ������ sref�� Third�� ��ü obj�� ������
	sref.FirstFunc();			// �������� �ڷ����� �������� �Լ��� ����� ����(= Second�� ���ǵ� �Լ� + ��ӹ��� �Լ��� ��밡��)
	sref.SecondFunc();
	sref.SimpleFunc();			// �����Լ�

	First& fref = obj;			// First�� ������ fref�� Third�� ��ü obj�� ������
	fref.FirstFunc();			// �������� �ڷ����� �������� �Լ��� ����� ����(= First�� ���ǵ� �Լ��� ��밡��)
	fref.SimpleFunc();			// �����Լ�

	// * ��°�� *
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