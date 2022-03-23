#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 5. 서로다른 자료형간의 대입연산 - 임시걕체를 통한 자동 형변환

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

	// * 출력결과 *
	// Number(int n=0)
	// Number(int n = 0)
	// operator=()
	// 30
	return 0;
}