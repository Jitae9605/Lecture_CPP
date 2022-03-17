#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 1. 복사생성자
// 객체를 생성하고 다른 이미생성된 객체에 대입연산자(=)를 적용함으로써 모든 멤버의 값을 복사해서 가져올수 있고
// 이를 복사생성자라고 한다.

using namespace std;

class Sosimple
{
private:
	int num1;
	int num2;
public:
	Sosimple(int n1, int n2) :num1(n1), num2(n2)
	{
		// empty
	}

	Sosimple(Sosimple& copy) :num1(copy.num1), num2(copy.num2)		// 복사생성자의 디폴트 - 따로 언급안해도 원래있음(숨겨져서 안보일뿐)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	Sosimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	Sosimple sim2 = sim1;				// 복사생성자이용 ( Sosimple sim2(sim1) 으로 변환된다)
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();				// 복사잘됬는지 출력해봄

	// * 출력결과 *
	// 생성 및 초기화 직전
	// Called Sosimple(Sosimple & copy)
	// 생성 및 초기화 직후
	// 15
	// 30

	return 0;
}