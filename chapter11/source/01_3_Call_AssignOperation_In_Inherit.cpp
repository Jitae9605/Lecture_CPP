#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 1_3. 상속구조에서의 대입연산자 호출

class First
{
private:
	int num1, num2;
public:
	First(int n1, int n2) :num1(n1), num2(n2)
	{ }

	void ShowData() { cout << num1 << ", " << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;

public:
	Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4)
	{ }

	void ShowData() 
	{ 
		First::ShowData();
		cout << num3 << ", " << num4 << endl; 
	}

	Second& operator=(const Second& ref)		// 멤버대 멤버로 복사가 이루어 지게끔 대입연산자오버로딩 = 깊은 복사
	{
		cout << "Secnod& operator=()" << endl;
		First::operator=(ref);					// 기초클래스의 대입연산자호출을 명령
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);

	scpy = ssrc;
	scpy.ShowData();



	// * 출력결과 *
	
	return 0;
}