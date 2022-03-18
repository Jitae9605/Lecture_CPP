#include <iostream>
#pragma warning(disable:4996)

// 04.mutable 
// const로 지정된 값의 변경을 한시적 허용하는 함수
// 쓰지말 것! - 그럴거면 const를 하지 말것

using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;

public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{
		// empty
	}

	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() const
	{
		num2 = num1;
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	// * 출력결과 *
	// 1, 2
	// 1, 1

	return 0;
}