#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 5.������

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass()		// ������ = Ŭ�����̸��� ���� �̸� + ��ȯ������ X
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
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
	SimpleClass sc1;
	sc1.showdata();

	SimpleClass sc2(100);
	sc2.showdata();

	SimpleClass sc3(100,200);
	sc3.showdata();

	// * ��� ��� *
	// 0 0
	// 100 0
	// 100 200

	return 0;
}