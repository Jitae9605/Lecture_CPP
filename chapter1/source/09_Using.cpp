#include<iostream>

// 9. using

// 1)
namespace Hybrid
{
	void HybFunc(void)
	{
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespacer Hybrid!" << std::endl;
	}
}

// 2)
using std::cin;
using std::endl;
using std::cout;

// 3)
using namespace std;		// std 이름공간내의 모든 함수를 사용할때 std::를 생략

int main(void)
{

	std::cout << "------------ < 1) using을 이용한 이름공간의 명시  > ----------------" << std::endl;
	// 1) using을 이용한 이름공간의 명시

	using Hybrid::HybFunc;				// == HybFunc함수의 앞에 자동으로 Hybrid 이름공간이 명시된다.(단, 지역적임 - 외부나 타 함수 내에서의 사용에는 이름공간 명시해야함)
	HybFunc();							//															(단, using을 전역으로 선언하면 상관없다)

	// * 출력결과 *
	// So simple function!
	// In namespacer Hybrid!

	std::cout << "------------ < 2) using을 이용한 편한 함수사용  > ----------------" << std::endl;
	// 2) using을 이용한 편한 함수사용
	// 전역으로 using을 통해 cin,endl,cout를 사용할때 앞에 std::를 쓰지않아도 되게 함 -> 간편

	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	// * 출력결과 *
	// Hello World!
	// Hello World!
	// 20 A 3.14

	std::cout << "------------ < 3) using을 이용한 편한 이름공간사용  > ----------------" << std::endl;
	// 3) using을 이용한 편한 이름공간사용
	// using namespace std를 이용하면 함수하나하나가 아니라 std내부의 모든것을 std::라는 이름공가 명시없이 사용이 가능함
	
	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	// * 출력결과 *
	// Hello World!
	// Hello World!
	// 20 A 3.14

	return 0;
}