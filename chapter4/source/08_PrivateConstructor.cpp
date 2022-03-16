#include <iostream>
#pragma warning(disable:4996)

// 8. 생성자를 private으로 지정하는것도 가능
// 하지만 그러면 생성을 객체내부에서만 진행해야한다.

using namespace std;

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {}	// 디폴트 생성자
	AAA& CreateInitObj(int n) const						// 
	{
		AAA* ptr = new AAA(n);							// AAA(n)으로 생성하고 이 대상을 가리키는 AAA* ptr을 만들어서 이를 반환
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private:
	AAA(int n) : num(n) {}								// 17행의 AAA(n)에서 AAA 가 생성되게 하는 목적의 생성자				
};

int main(void)
{
	AAA base;											// 디폴트생성자에 의해 생성
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);					// == [AAA& obj1] = [AAA* ptr] = [AAA(3)]
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);					// == [AAA& obj2] = [AAA* ptr] = [AAA(12)]
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;

	// * 출력결과 *
	// 0
	// 3
	// 12
}