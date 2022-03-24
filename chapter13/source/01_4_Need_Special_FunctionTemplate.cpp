#include<iostream>
using namespace std;

// 1_4 함수템플릿의 특수화의 필요성

template <typename T>		// 함수템플릿
T Max(T a, T b)		// 여기서 T는 임의의 자료형이다 나중에 우리가 지정
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;		// 얘는 의미가 없다 - 주소값의 크기를 비교하게된다.

	// * 출력결과 *
	// 15
	// T
	// 7.5
	// Simple

	return 0;

}

