#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5_2. 형변환연산자 오버로딩

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
	operator int()		// 형 변환 연산자의 오버로딩
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

	// * 출력결과 *
	// Number(int n = 0)
	// Number(int n = 0)
	// operator=()
	// Number(int n = 0)
	// 50
	return 0;
}