#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 5.������
// 2) �Լ������� ���������� �ϴ°͵� ������

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1=0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}

	
	void showdata() const
	{
		cout << num1 << ' ' << num2 << endl;
	}

};

int main(void)
{
	SimpleClass sc1();			// �Լ�����(ȣ���� �ƴ�)
	SimpleClass mysc = sc1();	// == Simpleclass���� myscŬ������ sc1�Լ��� ȣ���Ͽ� ��ȯ���� sc�� ����
	mysc.showdata();

	return 0;
	// * ��°�� *
	// 20 30
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}