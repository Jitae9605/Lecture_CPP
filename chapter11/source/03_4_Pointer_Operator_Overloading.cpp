#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 3_4. 포인터연산자 오버로딩( -> , * )
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

	// * 출력결과 *
	// 20
	// 30
	// 30

	return 0;



}