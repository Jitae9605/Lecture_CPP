#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 3_4. �����Ϳ����� �����ε�( -> , * )
class Number
{
private:
	int num;
public:
	Number(int n):num(n) { }
	void ShowData() { cout << num << endl; }

	Number* operator->()
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();
	
	(*num)=30;
	num->ShowData();
	(*num).ShowData();

	// * ��°�� *
	// 20
	// 30
	// 30

	return 0;



}