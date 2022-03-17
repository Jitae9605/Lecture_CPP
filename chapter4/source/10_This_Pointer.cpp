#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 10. this포인터의 이해와 사용
// this는 객체자신을 가리키는 용도로 사용되는 포인터

using namespace std;

// 1)
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num<<", ";
		cout << "address = " << this << endl;			// 생성자호출과 동시에 생성된 객체의 주소값을 출력한다.
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{
		return this;
	}

};

// 2)
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)		// 원래 변수가 같으면 안되는데 c++은 this의 개념이 있어 이를 허락해준다.
	{
		this->num1 = num1;				// 이렇게 구별이 가능하므로
		this->num2 = num2;				// 근데 별로 좋지 못한 방법임.
	}
	
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{
	std::cout << "------------ < 1) this포인터의 이해와 사용 > ----------------" << std::endl;
	// 1) this포인터의 이해와 사용
	SoSimple sim1(100);							// 생성자호출 - 동시에 멤버변수값(= 100), 주소값(= this 값)이 출력된
	SoSimple* ptr1 = sim1.GetThisPointer();		// ptr1에 this를 이용해 객체의 주소값을 전달
	cout << ptr1 << ", ";						// ptr1 출력
	ptr1->ShowSimpleData();

	SoSimple sim2(200);							// 생성자호출 - 동시에 멤버변수값(= 200), 주소값(= this 값)이 출력된
	SoSimple* ptr2 = sim2.GetThisPointer();		// ptr2에 this를 이용해 객체의 주소값을 전달
	cout << ptr2 << ", ";						// ptr2 출력
	ptr2->ShowSimpleData();	

	// * 출력결과 *
	// num = 100, address = 008FF9A4
	// 008FF9A4, 100
	// num = 200, address = 008FF98C
	// 008FF98C, 200

	std::cout << "------------ < 2) this 포인터의 유용성 > ----------------" << std::endl;
	// 2) this 포인터의 유용성
	TwoNumber two(2, 4);
	two.ShowTwoNumber();

	// * 출력결과 *
	// 2
	// 4

	return 0;
}

	
