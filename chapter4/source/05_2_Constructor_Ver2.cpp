#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 5.생성자
// 2) 함수선언을 지역적으로 하는것도 가능함

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1=0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}

	
	void showdata() const
	{
		cout << num1 << ' ' << num2 << endl;
	}

};

int main(void)
{
	SimpleClass sc1();			// 함수선언(호출이 아님)
	SimpleClass mysc = sc1();	// == Simpleclass형의 mysc클래스에 sc1함수를 호출하여 반환값인 sc를 대입
	mysc.showdata();

	return 0;
	// * 출력결과 *
	// 20 30
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}