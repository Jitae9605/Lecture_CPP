#include <iostream>
#pragma warning(disable:4996)

// 7. �̴ϼȶ������� �̿��� ��������� �������� �����غ���

using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl;
	}

	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;						// AAA�� ������ ref�� ����� ����
	const int& num;

public:
	BBB(AAA& r, const int& n)
		:ref(r), num(n)
	{
		// empty constuructor body
	}
	
	void ShowYourName()
	{
		ref.ShowYourName();						// AAA�� ShowYourName()�� ȣ��ȴ�
		cout << "and" << endl;
		cout << "I'm ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);			// obj2���� AAA�� obj1�� ������ ref�� 20�� ����� ������ ����
	obj2.ShowYourName();

	return 0;

	// * ��°�� *
	// empty object				// AAA�� �����ڸ���κ�
	// I'm class AAA			
	// and
	// I'm ref num20
}