#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() :num1(1), num2(2), num3(3)
	{
		// empty
	}
};

class Derived:protected Base { };

int main()
{
	Derived drv;
	//cout << drv.num3 << endl;			// 오류발생 - 상속을 protected로 했기때문에 유도생성자 및 함수로만 접근가능
	return 0;
}

