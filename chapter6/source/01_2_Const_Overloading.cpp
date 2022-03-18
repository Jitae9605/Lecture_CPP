#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

// 1_2. Const 함수 오버로딩
// 

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{ }

	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void SimpleFunc() 
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)
{
	obj.SimpleFunc();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();			// 자동으로 const가 실행

	YourFunc(obj1);				// obj1이 const SoSimple &obj 로 매개변수로 들어가면서 const 함수가 되어 const 함수를 실행함
	YourFunc(obj2);				

	// *출력결과 *
	// SimpleFunc : 2
	// const SimpleFunc : 7
	// const SimpleFunc : 2
	// const SimpleFunc : 7


	return 0;
}