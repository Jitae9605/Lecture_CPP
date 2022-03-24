#include<iostream>
using namespace std;

// 1_2. 두 가지타입의 Add Function
// 

template <typename T>		// 함수템플릿
T Add(T num1, T num2)		// 여기서 T는 임의의 자료형이다 나중에 우리가 지정
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	// 함수템플릿에 의해 실행되는 함수들 == 함수템플릿
	cout << Add(5, 7) << endl;			
	cout << Add(3.7, 7.5) << endl;
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(3.7, 7.5) << endl;

	// * 출력결과 *
	// Add(int num1, int num2)
	// 12
	// Add(double num1, double num2)
	// 11.2
	// T Add(T num1, T num2)
	// 12
	// T Add(T num1, T num2)
	// 11.2

	return 0;
}