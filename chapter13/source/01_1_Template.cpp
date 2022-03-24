#include<iostream>
using namespace std;

// 1.템플릿
// 

template <typename T>		// 함수템플릿
T Add(T num1, T num2)		// 여기서 T는 임의의 자료형이다 나중에 우리가 지정
{
	return num1 + num2;
}

int main(void)
{
	// 함수템플릿에 의해 실행되는 함수들 == 함수템플릿
	cout << Add<int>(15, 20) << endl;			// T자리에 int, double이 들어감
	cout << Add<double>(2.9,3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14,2.75) << endl;

	// * 출력결과 *
	// 35
	// 6.6
	// 6
	// 5.89

	return 0;
}