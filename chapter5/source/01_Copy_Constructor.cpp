#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 1. ���������
// ��ü�� �����ϰ� �ٸ� �̹̻����� ��ü�� ���Կ�����(=)�� ���������ν� ��� ����� ���� �����ؼ� �����ü� �ְ�
// �̸� ��������ڶ�� �Ѵ�.

using namespace std;

class Sosimple
{
private:
	int num1;
	int num2;
public:
	Sosimple(int n1, int n2) :num1(n1), num2(n2)
	{
		// empty
	}

	Sosimple(Sosimple& copy) :num1(copy.num1), num2(copy.num2)		// ����������� ����Ʈ - ���� ��޾��ص� ��������(�������� �Ⱥ��ϻ�)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	Sosimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	Sosimple sim2 = sim1;				// ����������̿� ( Sosimple sim2(sim1) ���� ��ȯ�ȴ�)
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleData();				// �����߉���� ����غ�

	// * ��°�� *
	// ���� �� �ʱ�ȭ ����
	// Called Sosimple(Sosimple & copy)
	// ���� �� �ʱ�ȭ ����
	// 15
	// 30

	return 0;
}