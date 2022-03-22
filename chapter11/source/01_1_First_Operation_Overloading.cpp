#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1. 대입연산자 오버로딩

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) :num1(n1), num2(n2)
	{ }

	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;

public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{ }

	void ShowData() { cout << num3 << ", " << num4 << endl; }

	Second& operator=(const Second& ref)		// 멤버대 멤버로 복사가 이루어 지게끔 대입연산자오버로딩 = 깊은 복사
	{
		cout << "Secnod& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;

	fcpy = fsrc;
	scpy = ssrc;

	fcpy.ShowData();
	scpy.ShowData();

	cout << endl << "--------------" << endl << endl;

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();

	// * 출력결과 *
	// Secnod& operator=()
	// 111, 222
	// 333, 444
	// 
	// --------------
	// 
	// Secnod & operator=()
	// Secnod & operator=()
	// 111, 222
	// 111, 222
	// 333, 444
	// 333, 444

	return 0;
}