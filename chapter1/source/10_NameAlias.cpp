#include <iostream>
using namespace std;

// 10. 이름공간 별칭지정
// namespace가 중첩되어있을때 이들의 이름을 한번에 묶어 간편하게 만들수있따

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1, num2;
		}
	}
}

int main(void)
{
	
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;		// AAA::BBC::CCC 를 ABC로 별칭을 만듬(typedef랑 비슷)
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	// * 출력결과 *
	// 20
	// 30

	return 0;
}