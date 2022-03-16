#include <iostream>
#pragma warning(disable:4996)

// 7. 이니셜라이저를 이용해 멤버변수로 참조차를 선언해보자

using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl;
	}

	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;						// AAA의 참조자 ref를 멤버로 가짐
	const int& num;

public:
	BBB(AAA& r, const int& n)
		:ref(r), num(n)
	{
		// empty constuructor body
	}
	
	void ShowYourName()
	{
		ref.ShowYourName();						// AAA의 ShowYourName()이 호출된다
		cout << "and" << endl;
		cout << "I'm ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);			// obj2에는 AAA의 obj1의 참조자 ref와 20을 멤버로 가지고 있음
	obj2.ShowYourName();

	return 0;

	// * 출력결과 *
	// empty object				// AAA의 생성자몸통부분
	// I'm class AAA			
	// and
	// I'm ref num20
}