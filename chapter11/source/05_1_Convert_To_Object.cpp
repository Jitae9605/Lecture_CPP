#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5. ���δٸ� �ڷ������� ���Կ��� - �ӽÁzü�� ���� �ڵ� ����ȯ

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

	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num = 30;
	num.ShowNumber();

	// * ��°�� *
	// Number(int n=0)
	// Number(int n = 0)
	// operator=()
	// 30
	return 0;
}