#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 3_1. ��������� ��ȭ
// ��ȯ�� ���� ��������� ȣ�� (�ӽð�ü�� ����)

using namespace std;

class Sosimple
{
private:
	int num;

public:
	Sosimple(int n) :num(n)
	{
		// empty
	}

	Sosimple(const Sosimple& copy) :num(copy.num)		// ����������� ����Ʈ - ���� ��޾��ص� ��������(�������� �Ⱥ��ϻ�)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}
};

void simplefuncobj(Sosimple ob)
{
	ob.ShowSimpleData();
}

int main(void)
{
	Sosimple obj(7);
	cout << "�Լ� ȣ����" << endl;
	simplefuncobj(obj);
	cout << "�Լ� ȣ����" << endl;
	
	// * ��°�� *
	// �Լ� ȣ����
	// Called Sosimple(Sosimple & copy)
	// 7
	// �Լ� ȣ����

	return 0;
}