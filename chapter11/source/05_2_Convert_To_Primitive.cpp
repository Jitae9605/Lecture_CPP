#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5_2. ����ȯ������ �����ε�

class Number
{
private:
	int num;
public:
	Number(int n = 0) :num(n)
	{
		cout << "Number(int n=0)" << endl;
	}

	Number& operator = (const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()		// �� ��ȯ �������� �����ε�
	{
		return num;
	}

	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20;
	num2.ShowNumber();

	// * ��°�� *
	// Number(int n = 0)
	// Number(int n = 0)
	// operator=()
	// Number(int n = 0)
	// 50
	return 0;
}