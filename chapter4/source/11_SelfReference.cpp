#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 12. selfreference의 반환
// 클래스함수의 반환값을 자기참조자형태로 하고 반환하는 return을 본인의 주소값으로(*this) 한다.

using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelfRef& Adder(int n)			// 본인을 참조할수 있는 참조정보(*this)가 반환됨
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return*this;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);		// obj의 num(= 3)에 2를 더함(by Adder(2)) =>	obj의 num = 5

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	// 자기참조자 덕분에 이런게 가능
	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	// obj의 num(= 5)에 1를 더하고(by Adder(1))	=> obj의 num = 6
															// 2를 더함(by Adder(2))						=> obj의 num = 8

	// * 출력결과 *
	// 객체생성
	// 5
	// 5
	// 6
	// 8
	
	return 0;
}